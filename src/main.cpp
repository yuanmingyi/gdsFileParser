/*
 * MIT License
 *
 * Copyright (c) 2017 EDDR Software, LLC.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/*
 * Changes:
 * 2017-01-01: First & Last Name: What you did.
 * 2017-06-10: Kevin Nesmith: Initial contribution.
 *
 */

#include <stdlib.h>

#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <iomanip>

#include "gdsFileParser.h"

using namespace std;

#define SET_2W setfill('0') << setw(2)

class MyTestParser : public gdsfp::gdsFileParser
{
protected:
    virtual void onParsedGDSVersion(unsigned short version) {
        cout << "GDSII Version: " << version << endl;
    };
    virtual void onParsedModTime(short year, short month, short day,
                                 short hour, short minute, short sec) {
        cout << "Modified Time: " << endl;

        if(year==0 && month==0) {
            cout << "\tNot recorded." << endl;
        } else {
            cout << "\t" << year << "-" << SET_2W << month <<  "-" << SET_2W <<
                 day << " " << SET_2W << hour << ":" << SET_2W << minute <<
                 ":" << SET_2W << sec << endl;
        }
    };
    virtual void onParsedAccessTime(short year, short month, short day,
                                    short hour, short minute, short sec) {
        cout << "Accessed Time: " << endl;

        if(year==0 && month==0) {
            cout << "\tNot recorded." << endl;
        } else {
            cout << "\t" << year << "-" << SET_2W << month <<  "-" << SET_2W <<
                 day << " " << SET_2W << hour << ":" << SET_2W << minute <<
                 ":" << SET_2W << sec << endl;
        }
    };
    virtual void onParsedLibName(const char *libName) {
        cout << "LibName: " << libName << endl;
    };
    virtual void onParsedUnits(double userUnits, double dbUnits) {
        cout << "UserUnits: " << setprecision(9) << fixed << userUnits << endl;
        cout << "DBUnits: " << setprecision(9) << fixed << dbUnits << endl;
    };
    virtual void onParsedStrName(const char *strName) {
        cout << "StrName: " << strName << endl;
    };
    virtual void onParsedBoundaryStart() {
        cout << "Boundry start" << endl;
    };
    virtual void onParsedPathStart() {
        cout << "Path start" << endl;
    };
    virtual void onParsedBoxStart() {
        cout << "Box start" << endl;
    };
    virtual void onParsedEndElement() {
        cout << "Element end" << endl;
    };
    virtual void onParsedEndStructure() {
        cout << "Structure end" << endl;
    };
    virtual void onParsedEndLib() {
        cout << "Lib end" << endl;
    };
    virtual void onParsedColumnsRows(unsigned short columns,
                                     unsigned short rows) {
        cout << "Columns: " << columns << " Rows: " << rows << endl;
    };
    virtual void onParsedPathType(unsigned short pathType) {
        cout << "PathType: " << pathType << endl;
    };
    virtual void onParsedStrans(short strans) {
        cout << "Strans: " << strans << endl;
    };
    virtual void onParsedPresentation(short font, short valign,
                                      short halign) {
        cout << "Font: " << font << endl;
        cout << "Valign: " << valign << endl;
        cout << "Halign: " << halign << endl;
    };
    virtual void onParsedNodeStart() {
        cout << "Node start" << endl;
    };
    virtual void onParsedTextStart() {
        cout << "Text start" << endl;
    };
    virtual void onParsedSrefStart() {
        cout << "Sref start" << endl;
    };
    virtual void onParsedArefStart() {
        cout << "Aref start" << endl;
    };
    virtual void onParsedSname(const char *sname) {
        cout << "Sname: " << sname << endl;
    };
    virtual void onParsedString(const char *str) {
        cout << "String: " << str << endl;
    };
    virtual void onParsedPropValue(const char *propValue) {
        cout << "Prop Value: " << propValue << endl;
    };
    virtual void onParsedXY(int count, int x[], int y[]) {
        cout << "XY: " << count << endl;

        for(int i=0; i<count; ++i) {
            cout << "(" << x[i] << "," << y[i] << ")";
        }

        cout << endl;
    };
    virtual void onParsedLayer(unsigned short layer) {
        cout << "Layer: " << layer << endl;
    };
    virtual void onParsedWidth(int width) {
        cout << "Width: " << width << endl;
    };
    virtual void onParsedDataType(unsigned short dataType) {
        cout << "Data Type: " << dataType << endl;
    };
    virtual void onParsedTextType(unsigned short textType) {
        cout << "Text Type: " << textType << endl;
    };
    virtual void onParsedAngle(double angle) {
        cout << "Angle: " << angle << endl;
    };
    virtual void onParsedMag(double mag) {
        cout << "Mag: " << mag << endl;
    };
    virtual void onParsedBeginExtension(unsigned short bext) {
        cout << "Begin Extension: " << bext << endl;
    };
    virtual void onParsedEndExtension(unsigned short eext) {
        cout << "End Extension: " << eext << endl;
    };
    virtual void onParsedPropertyNumber(unsigned short propNum) {
        cout << "Property Number: " << propNum << endl;
    };
    virtual void onParsedNodeType(unsigned short nodeType) {
        cout << "Node Type: " << nodeType << endl;
    };
    virtual void onParsedBoxType(unsigned short boxType) {
        cout << "Box Type: " << boxType << endl;
    };
    virtual void onError(const char* error) {
        cerr << error << endl;
    }
};


// ****************************************************************************
// main()
//
// This is the top level function that tests the parser.
// ****************************************************************************
int main(int argc, char *argv[])
{
    if(argc<2) {
        cerr << "Missing GDSII file as the only parameter." << endl;
        cerr << "Usage: ./testParser /path/to/file.gds" << endl;
        return 1;
    }

    MyTestParser parser;
    return parser.parse(argv[1]);
}

