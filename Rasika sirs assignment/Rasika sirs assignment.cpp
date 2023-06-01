// Vinuki Thomasz - G20991607

#include <iostream>
#include<fstream>


using namespace std;

// text 1,2,3,4 and banned words files opening and reading functions calling : 
void OpenBannedFile(ifstream& infile5);
void ReadBannedFile(ifstream& infile5);

void OpenFile1(ifstream& infile1);
void ReadFile1(ifstream& infile1);

void OpenFile2(ifstream& infile2);
void ReadFile2(ifstream& infile2);

void OpenFile3(ifstream& infile3);
void ReadFile3(ifstream& infile3);

void OpenFile4(ifstream& infile4);
void ReadFile4(ifstream& infile4);

//global variables:
string banned[8];	// array that stores the banned words taken from "Banned.txt" file
string text1Array[99];
string text2Array[185];
string text3Array[161];
string text4Array[207];

// varibles that store data from the 4 text files
string text1;
string text2;
string text3;
string text4;

// variables that store the banned words count :
int catCount = 0;
int dogCount = 0;
int aimCount = 0;
int addCount = 0;
int earCount = 0;
int backCount = 0;
int punkCount = 0;
int ableCount = 0;

//varibales that hold the no of elements of text files
int element1 = 0;
int element2 = 0;
int element3 = 0;
int element4 = 0;


// function calling - word and letter comparings:

string WordFinder(string text);
int letterFinder1(string text, string bad);
int letterFinder2(string text, string bad);
string WordFinder2(string text);
string asteriskChange(string text, string banned, int index);
string asteriskChange2(string text, string banned, int index);
string WordFinder3(string text);
string WordFinder4(string text);

int main()
{

	//function callings:
	ifstream infile5;
	ifstream infile1;
	ifstream infile2;
	ifstream infile3;
	ifstream infile4;

	OpenBannedFile(infile5);
	ReadBannedFile(infile5);

	OpenFile1(infile1);
	ReadFile1(infile1);

	OpenFile2(infile2);
	ReadFile2(infile2);

	OpenFile3(infile3);
	ReadFile3(infile3);

	OpenFile4(infile4);
	ReadFile4(infile4);

}
//for banned.txt file
void OpenBannedFile(ifstream& infile5)   //to open banned words file
{
	infile5.open("Banned.txt");
	if (!infile5)
	{
		cout << "ERROR: ";
		cout << "Can't open input file\n";
	}
}

void ReadBannedFile(ifstream& infile5)	// to read the content of banned file
{
	while (!infile5.eof())
	{

		for (int i = 0; i < 8; i++)
		{
			infile5 >> banned[i];		// the words in the file are taken to a array

		}
		cout << ".................................................." << endl;
		cout << "The 8 banned words are : " << endl;
		for (int i = 0; i < 8; i++)
		{
			cout << banned[i] << endl;
		}

		cout << ".................................................." << endl;
	}
}
// for text1.txt file
void OpenFile1(ifstream& infile1)     //to open text1 file
{
	infile1.open("text1.txt");
	if (!infile1)
	{
		cout << "ERROR: ";
		cout << "Can't open input file\n";
	}
}

void ReadFile1(ifstream& infile1)    //to read text1 file
{
	remove("text1Filtered.txt");   // this command deletes the text filtered file which was created in the previous run time which enables the code to re-write a filtered text file

	while (!infile1.eof())
	{

		//string text1;
		infile1 >> text1;		//the words from the text file is sent to a variable

		/*for (int i = 0; i < 99; i++)
		{
			infile1 >> text1Array[i];
		}
		element1 = 99;
		*/
		//cout << text1 << endl;

		//text1 = WordFinder(text1);			//to satify 3 criteria - remmove the comment and c the outputs for criteria 3
		text1 = WordFinder2(text1);				//to satify  criteria - remmove the comment and c the outputs for criteria 


		ofstream outfile1("text1Filtered.txt", ios::app); // writes the modified text to Text1Filtered file
		outfile1 << text1 << endl;
		outfile1.close();

	}

	cout << "............................................." << endl;
	cout << "IN TEXT 1 FILE :" << endl;
	cout << "No of times the word 'cat' found : " << catCount << endl;
	cout << "No of times the word 'dog' found : " << dogCount << endl;
	cout << "No of times the word 'aim' found : " << aimCount << endl;
	cout << "No of times the word 'add' found : " << addCount << endl;
	cout << "No of times the word 'ear' found : " << earCount << endl;
	cout << "No of times the word 'back' found : " << backCount << endl;
	cout << "No of times the word 'punk' found : " << punkCount << endl;
	cout << "No of times the word 'able' found : " << ableCount << endl;
	cout << "............................................." << endl;

	catCount = 0, dogCount = 0, aimCount = 0, addCount = 0, earCount = 0, backCount = 0, punkCount = 0, ableCount = 0;
	//cout << catCount << endl << dogCount << endl << aimCount << endl << addCount << endl << earCount << endl << backCount << endl << punkCount << endl << ableCount << endl;
}


// for text2.txt file
void OpenFile2(ifstream& infile2)    //to open text2 file
{
	infile2.open("text2.txt");
	if (!infile2)
	{
		cout << "ERROR: ";
		cout << "Can't open input file\n";
	}
}

void ReadFile2(ifstream& infile2)     //to read text2 file
{
	remove("text2Filtered.txt");
	// This is a formatting command. It says do not skip // white space when reading from the input stream
		//infile >> noskipws;

	while (!infile2.eof())
	{
		infile2 >> text2;

		/*for (int i = 0; i < 185; i++)
		{
			infile2 >> text2Array[i];

		}
		element2 = 185;*/
		//cout << text2 << endl; //this works ; the detected words are substituted by *** 
		text2 = WordFinder2(text2);

		ofstream outfile2("text2Filtered.txt", ios::app);     // writes the modified text to Text2Filtered file
		outfile2 << text2 << endl;
		outfile2.close();
	}

	cout << "............................................." << endl;
	cout << "IN TEXT 2 FILE :" << endl;
	cout << "No of times the word 'cat' found : " << catCount << endl;
	cout << "No of times the word 'dog' found : " << dogCount << endl;
	cout << "No of times the word 'aim' found : " << aimCount << endl;
	cout << "No of times the word 'add' found : " << addCount << endl;
	cout << "No of times the word 'ear' found : " << earCount << endl;
	cout << "No of times the word 'back' found : " << backCount << endl;
	cout << "No of times the word 'punk' found : " << punkCount << endl;
	cout << "No of times the word 'able' found : " << ableCount << endl;
	cout << "............................................." << endl;

	catCount = 0, dogCount = 0, aimCount = 0, addCount = 0, earCount = 0, backCount = 0, punkCount = 0, ableCount = 0;

	//if( !infile.eof() )
	//{
		//cout << text2 << "\n";
	//}
}


// for text3.txt file
void OpenFile3(ifstream& infile3)     // to open text3 file
{
	infile3.open("text3.txt");
	if (!infile3)
	{
		cout << "ERROR: ";
		cout << "Can't open input file\n";
	}
}

void ReadFile3(ifstream& infile3)    // to read text3 file
{
	remove("text3Filtered.txt");
	// This is a formatting command. It says do not skip // white space when reading from the input stream
		//infile >> noskipws;
	while (!infile3.eof())
	{

		infile3 >> text3;

		/*	for (int i = 0; i < 161; i++)
			{
				infile3 >> text3Array[i];

			}
			element3 = 161;*/

			//text3 = WordFinder2(text3);  
		text3 = WordFinder3(text3);

		ofstream outfile3("text3Filtered.txt", ios::app);      // writes the modified text to Text3Filtered file
		outfile3 << text3 << endl;
		outfile3.close();

		//cout << text2 << endl; //this works ; the detected words are substituted by *** 

	}
	cout << "............................................." << endl;
	cout << "IN TEXT 3 FILE :" << endl;
	cout << "No of times the word 'cat' found : " << catCount << endl;
	cout << "No of times the word 'dog' found : " << dogCount << endl;
	cout << "No of times the word 'aim' found : " << aimCount << endl;
	cout << "No of times the word 'add' found : " << addCount << endl;
	cout << "No of times the word 'ear' found : " << earCount << endl;
	cout << "No of times the word 'back' found : " << backCount << endl;
	cout << "No of times the word 'punk' found : " << punkCount << endl;
	cout << "No of times the word 'able' found : " << ableCount << endl;
	cout << "............................................." << endl;

	catCount = 0, dogCount = 0, aimCount = 0, addCount = 0, earCount = 0, backCount = 0, punkCount = 0, ableCount = 0;
	//if( !infile.eof() )
	{
		//cout << text3 << "\n";
	}
}


// for text4.txt file 
void OpenFile4(ifstream& infile4)    // to open text4 file
{
	infile4.open("text4.txt");
	if (!infile4)
	{
		cout << "ERROR: ";
		cout << "Can't open input file\n";
	}
}

void ReadFile4(ifstream& infile4)   //to read text4 file
{
	remove("text4Filtered.txt");
	// This is a formatting command. It says do not skip // white space when reading from the input stream
		//infile >> noskipws;
	while (!infile4.eof())
	{
		infile4 >> text4;
		/*for (int i = 0; i < 207; i++)
		{
			infile4 >> text4Array[i];

		}
		element4 = 207;*/
		text4 = WordFinder4(text4);

		ofstream outfile4("text4Filtered.txt", ios::app);     // writes the modified text to Text4Filtered file
		outfile4 << text4 << endl;
		outfile4.close();

		//if( !infile.eof() )
		{
			//cout << text3 << "\n";
		}
		//if( !infile.eof() )
		{
			//cout << text4 << "\n";
		}
	}
	cout << "............................................." << endl;
	cout << "IN TEXT4 FILE :" << endl;
	cout << "No of times the word 'cat' found : " << catCount << endl;
	cout << "No of times the word 'dog' found : " << dogCount << endl;
	cout << "No of times the word 'aim' found : " << aimCount << endl;
	cout << "No of times the word 'add' found : " << addCount << endl;
	cout << "No of times the word 'ear' found : " << earCount << endl;
	cout << "No of times the word 'back' found : " << backCount << endl;
	cout << "No of times the word 'punk' found : " << punkCount << endl;
	cout << "No of times the word 'able' found : " << ableCount << endl;
	cout << "............................................." << endl;

	catCount = 0, dogCount = 0, aimCount = 0, addCount = 0, earCount = 0, backCount = 0, punkCount = 0, ableCount = 0;
}

string WordFinder(string text)   //to satisfy 2.2 criteria  (here only the solid words are compared; if there are banned words in the text solidly then the words would be idenified )
{
	//catCount = 0, dogCount = 0, aimCount = 0, addCount = 0, earCount = 0, backCount = 0, punkCount = 0, ableCount = 0;
	//cout << endl << endl << endl << text << endl << endl << banned[1] << banned[2] << banned[3] << banned[4] << banned[5] << banned[6] << banned[7] << endl;

	if (text == banned[0])
	{
		text = "***";
		catCount++;
	}

	else if (text == banned[1])
	{
		text = "***";
		dogCount++;
	}

	else if (text == banned[2])
	{
		text = "***";
		aimCount++;
	}

	else if (text == banned[3])
	{
		text = "***";
		addCount++;
	}

	else if (text == banned[4])
	{
		text = "***";
		earCount++;
	}

	else if (text == banned[5])
	{
		text = "***";
		backCount++;
	}

	else if (text == banned[6])
	{
		text = "***";
		punkCount++;
	}

	else if (text == banned[7])
	{
		text = "***";
		ableCount++;
	}
	return text;
}


int letterFinder1(string text, string bad)  // function used to compare each letter of banned word with each letter on text 
// 2.1 criteria
{
	int i = 0;
	int j = 0;
	int count = 0;
	int good_len = text.length();
	int bad_len = bad.length();

	while (count != bad_len)
	{
		if (tolower(text[i]) == bad[j])  // tolower is used to chnage all the capital letters to simple letters (2.2 criteria)
		{
			i++; j++; count++;   // i , j -  index is changed	 count - equal no. of letters
			//cout << "matching banned word found in the text" << endl;
		}

		else
		{
			//cout << "letters aren't matching" << endl;
			count = 0; i++; j = 0;    // j becomes zero so the banned word is compared from the start again
		}

		if (i == good_len)
			break;
	}

	if (count == bad_len)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

string WordFinder2(string text)		// to satisfy 2.2 criteria - here the words in the text file is compared letter by letter with each banned letter.
// every letter of the banned word in compared with every letter of the text file
{
	if (letterFinder1(text, banned[0]) == 1)
	{
		text = "***";
		catCount++;
	}

	else if (letterFinder1(text, banned[1]) == 1)
	{
		text = "***";
		dogCount++;
	}

	else if (letterFinder1(text, banned[2]) == 1)
	{
		text = "***";
		aimCount++;
	}

	else if (letterFinder1(text, banned[3]) == 1)
	{
		text = "***";
		addCount++;
	}

	else if (letterFinder1(text, banned[4]) == 1)
	{
		text = "***";
		earCount++;
	}

	else if (letterFinder1(text, banned[5]) == 1)
	{
		text = "***";
		backCount++;
	}

	else if (letterFinder1(text, banned[6]) == 1)
	{
		text = "***";
		punkCount++;
	}

	else if (letterFinder1(text, banned[7]) == 1)
	{
		text = "***";
		ableCount++;
	}
	return text;
}

int letterFinder2(string text, string bad)
{ //1 st criteria
	int i = 0;
	int j = 0;
	int count = 0;
	int good_len = text.length();
	int bad_len = bad.length();

	while (count != bad_len)
	{
		if (tolower(text[i]) == bad[j])  // tolower is used to chnage all the capital letters to simple letters (2.1 criteria)
		{
			i++; j++; count++;
			//cout << "matching banned word found in the text" << endl;
		}

		else
		{
			//cout << "letters aren't matching" << endl;
			count = 0; i++; j = 0;
		}

		if (i == good_len)
			break;
	}

	if (count == bad_len)
	{
		return i;
	}
	else
	{
		return 0;
	}
}

string asteriskChange(string text, string banned, int index)
{
	int banned_len = banned.length();


	for (int i = index; i > (index - banned_len); i--)
	{
		text[i] = '*';
	}
	return text;
}

string WordFinder3(string text)  // to satisfy 1st criteria
{
	if (letterFinder1(text, banned[0]) == 1)
	{
		text = asteriskChange(text, banned[0], letterFinder2(text, banned[0]));
		catCount++;
	}

	else if (letterFinder1(text, banned[1]) == 1)
	{
		text = asteriskChange(text, banned[1], letterFinder2(text, banned[1]));
		dogCount++;
	}

	else if (letterFinder1(text, banned[2]) == 1)
	{
		text = asteriskChange(text, banned[2], letterFinder2(text, banned[2]));
		aimCount++;
	}

	else if (letterFinder1(text, banned[3]) == 1)
	{
		text = asteriskChange(text, banned[3], letterFinder2(text, banned[3]));
		addCount++;
	}

	else if (letterFinder1(text, banned[4]) == 1)
	{
		text = asteriskChange(text, banned[4], letterFinder2(text, banned[4]));
		earCount++;
	}

	else if (letterFinder1(text, banned[5]) == 1)
	{
		text = asteriskChange(text, banned[5], letterFinder2(text, banned[5]));
		backCount++;
	}

	else if (letterFinder1(text, banned[6]) == 1)
	{
		text = asteriskChange(text, banned[6], letterFinder2(text, banned[6]));
		punkCount++;
	}

	else if (letterFinder1(text, banned[7]) == 1)
	{
		text = asteriskChange(text, banned[7], letterFinder2(text, banned[7]));
		ableCount++;
	}
	return text;
}
string asteriskChange2(string text, string banned, int index)  // to satisfy "highest 1st" criteria
{
	int banned_len = banned.length();

	if (banned_len % 2 == 1)
	{
		text[index - (banned_len / 2) - 1] = '*';
	}
	else
	{
		text[index - (banned_len / 2) - 1] = '*';
		text[index - (banned_len / 2)] = '*';

	}

	return text;
}

string WordFinder4(string text)		// to satisfy highest first criteria 
{
	if (letterFinder1(text, banned[0]) == 1)
	{
		text = asteriskChange2(text, banned[0], letterFinder2(text, banned[0]));
		catCount++;
	}

	else if (letterFinder1(text, banned[1]) == 1)
	{
		text = asteriskChange2(text, banned[1], letterFinder2(text, banned[1]));
		dogCount++;
	}

	else if (letterFinder1(text, banned[2]) == 1)
	{
		text = asteriskChange2(text, banned[2], letterFinder2(text, banned[2]));
		aimCount++;
	}

	else if (letterFinder1(text, banned[3]) == 1)
	{
		text = asteriskChange2(text, banned[3], letterFinder2(text, banned[3]));
		addCount++;
	}

	else if (letterFinder1(text, banned[4]) == 1)
	{
		text = asteriskChange2(text, banned[4], letterFinder2(text, banned[4]));
		earCount++;
	}

	else if (letterFinder1(text, banned[5]) == 1)
	{
		text = asteriskChange2(text, banned[5], letterFinder2(text, banned[5]));
		backCount++;
	}

	else if (letterFinder1(text, banned[6]) == 1)
	{
		text = asteriskChange2(text, banned[6], letterFinder2(text, banned[6]));
		punkCount++;
	}

	else if (letterFinder1(text, banned[7]) == 1)
	{
		text = asteriskChange2(text, banned[7], letterFinder2(text, banned[7]));
		ableCount++;
	}
	return text;
}
/*int counterText()
{
	int arr[] = { 3, 2, 1, 3, 3, 5, 3 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Number of times 3 appears : "
		<< count(arr, arr + n, 3);
}
*/



