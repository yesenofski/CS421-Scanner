#include<iostream>
#include<fstream>
#include<string>
using namespace std;

//=====================================================
// File scanner.cpp written by: Group Number: 22 
//=====================================================

// --------- DFAs ---------------------------------

// ** MYTOKEN DFA to be replaced by the WORD DFA
// ** Done by: Esmeralda Urena
// ** RE: Dylan Yesenofski
bool word (string s)
{
  int state = 0;
  int charpos = 0;

  while (s[charpos] != '\0') 
    {

      //STATE: q0
      if (state == 0 && s[charpos] == 'a')
	state = 1;
      else if (state == 0 && s[charpos] == 'e'|| s[charpos]== 'E')
	state = 1;
      else if (state == 0 && s[charpos] == 'i' || s[charpos == 'I')
	state = 1;
      else if (state == 0 && s[charpos] == 'o')
	state = 1;
      else if (state == 0 && s[charpos] == 'u')
	state = 1;
      else if (state == 0 && s[charpos] == 'b')
	state = 1;
      else if (state == 0 && s[charpos] == 'd')
        state = 1;
      else if (state == 0 && s[charpos] == 'g')
        state = 1;
      else if (state == 0 && s[charpos] == 'h')
        state = 1;
      else if (state == 0 && s[charpos] == 'j')
        state = 1;
      else if (state == 0 && s[charpos] == 'k')
        state = 1;
      else if (state == 0 && s[charpos] == 'm')
        state = 1;
      else if (state == 0 && s[charpos] == 'n')
        state = 1;
      else if (state == 0 && s[charpos] == 'p')
        state = 1;
      else if (state == 0 && s[charpos] == 'r')
        state = 1;
      else if (state == 0 && s[charpos] == 's')
        state = 1;
      else if (state == 0 && s[charpos] == 't')
        state = 1;
      else if (state == 0 && s[charpos] == 'w')
        state = 1;
      else if (state == 0 && s[charpos] == 'y')
        state = 1;
      else if (state == 0 && s[charpos] == 'z')
        state = 1;
      else if (state == 0 && s[charpos] == 'by')
        state = 1;
      else if (state == 0 && s[charpos] == 'gy')
        state = 1;
      else if (state == 0 && s[charpos] == 'hy')
        state = 1;
      else if (state == 0 && s[charpos] == 'ky')
        state = 1;
      else if (state == 0 && s[charpos] == 'my')
        state = 1;
      else if (state == 0 && s[charpos] == 'ny')
        state = 1;
      else if (state == 0 && s[charpos] == 'py')
        state = 1;
      else if (state == 0 && s[charpos] == 'ry')
        state = 1;
      else if (state == 0 && s[charpos] == 'ch')
        state = 1;
      else if (state == 0 && s[charpos] == 'sh')
        state = 1;
      else if (state == 0 && s[charpos] == 'ts')
        state = 1;
	       
	      
      else if (state == 1 && s[charpos] == 'n')
        state = 2;
      else if (state == 1 && s[charpos] == 'a')
        state = 2;
      else if (state == 1 && s[charpos] == 'e')
        state = 2;
      else if (state == 1 && s[charpos] == 'i')
        state = 2;
      else if (state == 1 && s[charpos] == 'o')
        state = 2;
      else if (state == 1 && s[charpos] == 'u')
        state = 2;
      else if (state == 2 && s[charpos] == 'n')
        state = 3;
      else
	{
	  return(false);
	  cout<<"ERROR: Token not found..."
	}
      charpos++;
    }//end of while
  
      if (state == 2 || state ==0)
	{
	  return(true);
	}
      else
	return false;
 
}

// ** Add the PERIOD DFA here
bool period (string s)
{
  int state = 0;
  int charpos = 0;

  while (s[charpos] != '\0')
    {
      if (state == 0 && s[charpos] == '.')
        state = 1;
      else
	return(false);
      ++charpos;
    }
  if (state ==1)
    return(true);
  else
    return(false);
}

// ** Done by:

// -----  Tables -------------------------------------

// ** Update the tokentype to be WORD1, WORD2, PERIOD, ERROR, EOFM, etc.
enum tokentype {ERROR, WORD1, WORD2, EOFM, PERIOD, VERB, VERBNEG, VERBPAST, VERBPASTNEG, IS, WAS, OBJECT, SUBJECT, DESTINATION, PRONOUN, CONNECTOR};

string tokenName[30] = {"ERROR", "WORD1", "WORD2", "EOFM", "PERIOD", "VERB", "VERBNEG", "VERBPAST", "VERBPASTNEG", "IS", "WAS", "OBJECT", "SUBJECT", "DESTINATION", "PRONOUN", "CONNECTOR" }; //for the display names oftokens - must be in the same order as the tokentype.

string tokenName[30][10] = {"ERROR", "WORD1", "WORD2", "EOFM"};
// ** Need the reservedwords table to be set up here. 
// ** Do not require any file input for this.
// ** a.out should work without any additional files.

struct reserved
{
  const char* string;
  tokentype tok;
}

 reserved[] = {
   { "masu",VERB},
   {"masen",VERBNEG},
   {"mashita",VERBPAST},
   {"masendeshita",VERBPASTNEG},
   {"desu",IS},
   {"deshita",WAS},
   {"o", OBJECT},
   {"wa", SUBJECT},
   {"ni", DESTINATION},
   {"watashi",PRONOUN},
   {"anata",PRONOUN},
   {"kare",PRONOUN},
   {"kanojo", PRONOUN},
   {"sore", PRONOUN},
   {"mata",CONNECTOR},
   {"soshite", CONNECTOR},
   {"shikashi", CONNECTOR},
   { "dakara", CONNECTOR}
 };


// ------------ Scaner and Driver ----------------------- 

ifstream fin;  // global stream for reading from the input file

// Scanner processes only one word each time it is called
// Gives back the token type and the word itself
// ** Done by: 
int scanner(tokentype& a, string& inputWord)
{
  string inputWord;
  bool status;//to make sure word is a valid word or a period
  int count = sizeof reserved/ sizeof reserved[0];//size of reserved


  // ** Grab the next word from the file via fin
  fin >> inputWord;
  // 1. If it is eofm, return right now.   
  if(inputWord == "eofm")
    return;
  
  /*2. Call the token functions one after another (if-then-else)
     And generate a lexical error message if both DFAs failed.
     Let the token_type be ERROR in that case.*/
  /*
======================================================
ESME'S PART 2
  if(word(inputWord))
    status=true;
  else if(period(inputWord))
    status=true;
  else
    token_type=tokenName[0];
=====================================================
  */
  if(word(inputWord))//Beggining of  Dylans Part 2 
    {

   /* 3. Then, make sure WORDs are checked against the reservedwords list
      If not reserved, token_type is WORD1 or WORD2.*/


  //=====================================
  //checks the reserved stuct to see if token matches 
      if(word(inputWord))//Dylans Part 3
    {
      for (int i = 0; i < count; i++)
	{
	  if (inputWord == reserved[i].string)
	    {
	      a = reserved[i].tok;
	      return 0;
	    }
	}
    
      char end = inputWord[(inputWord.length()-1)];

      if (end == 'E' || end == 'I')
	{
	  a = WORD2;
	}
      else
	{
	  a = WORD1;
	}


    }
      //Dylans end of part 2

      else if(period(inputWord))
	{
	  a = PERIOD;
	}
      else if(inputWord == "eofm")
	{ //nothing happens
	}
      else
	{
	  cout << "ERROR: Lexical error found \n"<< w <<" is not a token\n";
	  a = ERROR;
	}

      




  /*
===================================================
ESME'S PART 3 
while(wordFound)
     { 
       if(inputWord== reservedWords[i][0])
	 wordFound=true;
       else
	 i++;
     }
====================================================
  */






   /*
   4. Return the token type & string  (pass by reference)
    */

      //needs to be done not sure  if we just add this into if-else statments in accordance to token type 
   
}//the end of scanner
 

 


// The temporary test driver to just call the scanner repeatedly  
// This will go away after this assignment
// DO NOT CHANGE THIS!!!!!! 
// Done by:  Rika
int main()
{
  tokentype thetype;
  string theword; 
  string filename;

  cout << "Enter the input file name: ";
  cin >> filename;

  fin.open(filename.c_str());

  // the loop continues until eofm is returned.
  while (true)
    {
      scanner(thetype, theword);  // call the scanner
      if (theword == "eofm") break;  // stop now

      cout << "Type is:" << tokenName[thetype] << endl;
      cout << "Word is:" << theword << endl;   
    }

  cout << "End of file is encountered." << endl;
  fin.close();

}// end
