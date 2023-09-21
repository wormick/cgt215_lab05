#include <iostream>
#include <string>

using namespace std;

char encode(char c, const string& codeTable)   
    {
    if (c >= 65 && c <= 90) {
        return codeTable[c - 65];
    }
    else if (c >= 97 && c <= 122) 
    {
        char upperCaseLetter = c - 32;
        char upperCaseCode = codeTable[upperCaseLetter - 65];
        return upperCaseCode + 32; 
    }
    else 
    { 
        return c;
    }
}

int main() {
    string user_input;
    string codeTable = "VFXBLITZJRPDHKNOWSGUYQMACE"; // Example code table

    cout << "Enter a string (up to 128 characters): ";
    getline(cin, user_input);

    string encoded_text;

    if (user_input.length() > 128) 
    {
        cout << "Input is too long (max 128 characters)." << endl;
        return 1;
    }

    for (char c : user_input) 
    {
        encoded_text += encode(c, codeTable);
    }

    cout << "Encoded text: " << encoded_text << endl;

    return 0;
}