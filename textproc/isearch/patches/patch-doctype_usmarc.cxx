$NetBSD: patch-doctype_usmarc.cxx,v 1.1 2012/12/21 10:29:47 dholland Exp $

Chase after the C++ standard:
   - use the newfangled names for C++ headers
   - use "std" qualification
   - string constants are const char *

--- doctype/usmarc.cxx~	1999-06-05 00:54:00.000000000 +0000
+++ doctype/usmarc.cxx
@@ -9,7 +9,7 @@ Modified by Bjorn L. Thordarson
 
 */
 
-#include <ctype.h>
+#include <cctype>
 #include "isearch.hxx"
 #include "marc.hxx"
 #include "usmarc.hxx"
@@ -35,10 +35,10 @@ USMARC::USMARC(PIDBOBJ DbParent) 
 
 struct ParseEntry
 {
-  char *field;
-  char *subfield;
-  char *tag;
-  char *name;
+  const char *field;
+  const char *subfield;
+  const char *tag;
+  const char *name;
 };
 
 // Maps a character string representation of a marc field
@@ -126,7 +126,7 @@ USMARC::ParseRecords(const RECORD& FileR
   FileRecord.GetFullFileName (&fn);
   PFILE fp = fopen (fn, "rb");
   if (!fp) {
-      cout << "Could not access '" << fn << "'" << EOL;
+      std::cout << "Could not access '" << fn << "'" << EOL;
       return;			// File not accessed   
   }
   
@@ -145,7 +145,7 @@ USMARC::ParseRecords(const RECORD& FileR
   int RS = 0;          // we also know the first record will begin @ 0.
   
   if(fseek(fp, 0, SEEK_SET) == -1) {
-    cout << "USMARC::ParseRecords(): Seek failed - " << fn << "\n";
+    std::cout << "USMARC::ParseRecords(): Seek failed - " << fn << "\n";
     fclose(fp);
     return;
   }
@@ -158,14 +158,14 @@ USMARC::ParseRecords(const RECORD& FileR
     marcLength = atoi(LenBuff);
 
     if (marcLength <= 0) {
-      cout << "Something went awry trying to read MARC record Length in "
+      std::cout << "Something went awry trying to read MARC record Length in "
 	   << fn << " \n";
       return;
     }
 
     // else we must have a valid marcLength now, so lets burn some characters
     if (fseek(fp, marcLength - 5, SEEK_CUR) < 0) {
-      cout << "Something went awry trying to read MARC record"
+      std::cout << "Something went awry trying to read MARC record"
 	   << fn << " \n";
       return;
     }
@@ -189,7 +189,7 @@ USMARC::readFileContents(PRECORD NewReco
   file = fn.NewCString();
   fp = fopen(fn, "rb");
   if (!fp) {
-    cout << "USMARC::ParseRecords(): Failed to open file\n\t";
+    std::cout << "USMARC::ParseRecords(): Failed to open file\n\t";
     perror(file);
     return;
   }
@@ -200,23 +200,23 @@ USMARC::readFileContents(PRECORD NewReco
 
   if (RecEnd == 0) {
     if(fseek(fp, 0L, SEEK_END) == -1) {
-      cout << "USMARC::ParseRecords(): Seek failed - ";
-      cout << fn << "\n";
+      std::cout << "USMARC::ParseRecords(): Seek failed - ";
+      std::cout << fn << "\n";
       fclose(fp);
       return;
     }
     RecStart = 0;
     RecEnd = ftell(fp);
     if(RecEnd == 0) {
-      cout << "USMARC::ParseRecords(): Skipping ";
-      cout << " zero-length record -" << fn << "...\n";
+      std::cout << "USMARC::ParseRecords(): Skipping ";
+      std::cout << " zero-length record -" << fn << "...\n";
       fclose(fp);
       return;
     }
     //RecEnd -= 1;
   }
   if(fseek(fp, (long)RecStart, SEEK_SET) == -1) {
-    cout << "USMARC::ParseRecords(): Seek failed - " << fn << "\n";
+    std::cout << "USMARC::ParseRecords(): Seek failed - " << fn << "\n";
     fclose(fp);
     return;
   }
@@ -224,16 +224,16 @@ USMARC::readFileContents(PRECORD NewReco
 
   RecBuffer = new CHR[RecLength + 1];
   if(!RecBuffer) {
-    cout << "USMARC::ParseRecords(): Failed to allocate ";
-    cout << RecLength + 1 << " bytes - " << fn << "\n";
+    std::cout << "USMARC::ParseRecords(): Failed to allocate ";
+    std::cout << RecLength + 1 << " bytes - " << fn << "\n";
     fclose(fp);
     return;
   }
 
   GPTYPE ActualLength = (GPTYPE)fread(RecBuffer, 1, RecLength, fp);
   if(ActualLength == 0) {
-    cout << "USMARC::ParseRecords(): Failed to fread\n\t";
-    cout << "RecLength is: " << RecLength << endl;
+    std::cout << "USMARC::ParseRecords(): Failed to fread\n\t";
+    std::cout << "RecLength is: " << RecLength << std::endl;
     perror(file);
     delete [] RecBuffer;
     fclose(fp);
@@ -241,9 +241,9 @@ USMARC::readFileContents(PRECORD NewReco
   }
   fclose(fp);
   if(ActualLength != RecLength) {
-    cout << "USMARC::ParseRecords(): Failed to fread ";
-    cout << RecLength << " bytes.  Actually read " << ActualLength;
-    cout << " bytes - " << fn << "\n";
+    std::cout << "USMARC::ParseRecords(): Failed to fread ";
+    std::cout << RecLength << " bytes.  Actually read " << ActualLength;
+    std::cout << " bytes - " << fn << "\n";
     delete [] RecBuffer;
     return;
   }
@@ -331,7 +331,7 @@ USMARC::usefulMarcField(char *fieldStr)
 }
 
 int
-USMARC::compareReg(char *s1 , char *s2) {
+USMARC::compareReg(const char *s1 , const char *s2) {
   if (s1 == NULL || s2 == NULL) { // FIXME: Think out behavior if this happens
   }
 
@@ -423,7 +423,7 @@ USMARC::ParseFields(PRECORD NewRecord) 
   //      if so, then add it again using the name we give it.
   PDFT pdft = new DFT();
   if(!pdft) {
-    cout << "USMARC::ParseRecords(): Failed to allocate DFT \n";
+    std::cout << "USMARC::ParseRecords(): Failed to allocate DFT \n";
     delete [] RecBuffer;
     delete [] marcDir;
     return;
@@ -510,13 +510,13 @@ USMARC::ParseWords(CHR* DataBuffer, INT 
        char *tmp = new char[e - s + 1];
        strncpy(tmp, DataBuffer + s, e - s);
        tmp[e - s] = 0x00;
-       cerr << "DataBuffer: " << tmp << endl;
+       cerr << "DataBuffer: " << tmp << std::endl;
        delete []tmp;
 
        tmp = new char[e - s + 1];
        strncpy(tmp, RecBuffer + s, e - s);
        tmp[e - s] = 0x00;
-       cerr << "RecBuffer:  " << tmp << endl;
+       cerr << "RecBuffer:  " << tmp << std::endl;
        delete []tmp;*/
 
     } // end of while loop;
