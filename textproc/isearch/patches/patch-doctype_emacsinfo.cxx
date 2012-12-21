$NetBSD: patch-doctype_emacsinfo.cxx,v 1.1 2012/12/21 10:29:46 dholland Exp $

Chase after the C++ standard:
   - use the newfangled names for C++ headers
   - use "std" qualification

--- doctype/emacsinfo.cxx~	1998-02-26 01:50:23.000000000 +0000
+++ doctype/emacsinfo.cxx
@@ -6,8 +6,8 @@ Description: class EMACSINFO - index fil
 Author:      Erik Scott, Scott Technologies, Inc.
 */
 
-#include <ctype.h>
-#include <string.h>  /* For strstr() in ParseRecords */
+#include <cctype>
+#include <cstring>  /* For strstr() in ParseRecords */
 #include "isearch.hxx"
 #include "emacsinfo.hxx"
 
@@ -30,7 +30,7 @@ void EMACSINFO::ParseRecords(const RECOR
   PFILE fp = fopen (fn, "rb");
   if (!fp)
     {
-      cout << "Could not access '" << fn << "'\n";
+      std::cout << "Could not access '" << fn << "'\n";
       return;			// File not accessed
 
     }
@@ -47,8 +47,8 @@ void EMACSINFO::ParseRecords(const RECOR
   Record.SetDocumentType ( s );
 
   if(fseek(fp, 0L, SEEK_END) == -1) {
-    cout << "EMACSINFO::ParseRecords(): Seek failed - ";
-    cout << fn << "\n";
+    std::cout << "EMACSINFO::ParseRecords(): Seek failed - ";
+    std::cout << fn << "\n";
     fclose(fp);
     return;	
   }
@@ -56,15 +56,15 @@ void EMACSINFO::ParseRecords(const RECOR
   RecStart = 0;
   RecEnd = ftell(fp);
   if(RecEnd == 0) {
-    cout << "EMACSINFO::ParseRecords(): Skipping ";
-    cout << " zero-length record -" << fn << "...\n";
+    std::cout << "EMACSINFO::ParseRecords(): Skipping ";
+    std::cout << " zero-length record -" << fn << "...\n";
     fclose(fp);
     return;
   }
 
 
   if(fseek(fp, (long)RecStart, SEEK_SET) == -1) {
-    cout << "EMACSINFO::ParseRecords(): Seek failed - " << fn << "\n";
+    std::cout << "EMACSINFO::ParseRecords(): Seek failed - " << fn << "\n";
     fclose(fp);
     return;	
   }
@@ -73,24 +73,24 @@ void EMACSINFO::ParseRecords(const RECOR
 	
   RecBuffer = new CHR[RecLength + 2];
   if(!RecBuffer) {
-    cout << "EMACSINFO::ParseRecords(): Failed to allocate ";
-    cout << RecLength + 1 << " bytes - " << fn << "\n";
+    std::cout << "EMACSINFO::ParseRecords(): Failed to allocate ";
+    std::cout << RecLength + 1 << " bytes - " << fn << "\n";
     fclose(fp);
     return;
   }
 
   ActualLength = (GPTYPE)fread(RecBuffer, 1, RecLength, fp);
   if(ActualLength == 0) {
-    cout << "EMACSINFO::ParseRecords(): Failed to fread\n";
+    std::cout << "EMACSINFO::ParseRecords(): Failed to fread\n";
     delete [] RecBuffer;
     fclose(fp);
     return;
   }
   fclose(fp);
   if(ActualLength != RecLength) {
-    cout << "EMACSINFO::ParseRecords(): Failed to fread ";
-    cout << RecLength << " bytes.  Actually read " << ActualLength;
-    cout << " bytes - " << fn << "\n";
+    std::cout << "EMACSINFO::ParseRecords(): Failed to fread ";
+    std::cout << RecLength << " bytes.  Actually read " << ActualLength;
+    std::cout << " bytes - " << fn << "\n";
     delete [] RecBuffer;
     return;
   }
@@ -143,7 +143,7 @@ void EMACSINFO::ParseFields(PRECORD NewR
   file = fn.NewCString();
   fp = fopen(fn, "rb");
   if (!fp) {
-    cout << "EMACSINFO::ParseRecords(): Failed to open file\n\t";
+    std::cout << "EMACSINFO::ParseRecords(): Failed to open file\n\t";
     perror(file);
     return;
   }
@@ -154,16 +154,16 @@ void EMACSINFO::ParseFields(PRECORD NewR
 	
   if (RecEnd == 0) {
     if(fseek(fp, 0L, SEEK_END) == -1) {
-      cout << "EMACSINFO::ParseRecords(): Seek failed - ";
-      cout << fn << "\n";
+      std::cout << "EMACSINFO::ParseRecords(): Seek failed - ";
+      std::cout << fn << "\n";
       fclose(fp);
       return;	
     }
     RecStart = 0;
     RecEnd = ftell(fp);
     if(RecEnd == 0) {
-      cout << "EMACSINFO::ParseRecords(): Skipping ";
-      cout << " zero-length record -" << fn << "...\n";
+      std::cout << "EMACSINFO::ParseRecords(): Skipping ";
+      std::cout << " zero-length record -" << fn << "...\n";
       fclose(fp);
       return;
     }
@@ -172,7 +172,7 @@ void EMACSINFO::ParseFields(PRECORD NewR
 
   // Make two copies of the record in memory
   if(fseek(fp, (long)RecStart, SEEK_SET) == -1) {
-    cout << "EMACSINFO::ParseRecords(): Seek failed - " << fn << "\n";
+    std::cout << "EMACSINFO::ParseRecords(): Seek failed - " << fn << "\n";
     fclose(fp);
     return;	
   }
@@ -180,15 +180,15 @@ void EMACSINFO::ParseFields(PRECORD NewR
 	
   RecBuffer = new CHR[RecLength + 1];
   if(!RecBuffer) {
-    cout << "EMACSINFO::ParseRecords(): Failed to allocate ";
-    cout << RecLength + 1 << " bytes - " << fn << "\n";
+    std::cout << "EMACSINFO::ParseRecords(): Failed to allocate ";
+    std::cout << RecLength + 1 << " bytes - " << fn << "\n";
     fclose(fp);
     return;
   }
 
   ActualLength = (GPTYPE)fread(RecBuffer, 1, RecLength, fp);
   if(ActualLength == 0) {
-    cout << "EMACSINFO::ParseRecords(): Failed to fread\n\t";
+    std::cout << "EMACSINFO::ParseRecords(): Failed to fread\n\t";
     perror(file);
     delete [] RecBuffer;
     fclose(fp);
@@ -196,9 +196,9 @@ void EMACSINFO::ParseFields(PRECORD NewR
   }
   fclose(fp);
   if(ActualLength != RecLength) {
-    cout << "EMACSINFO::ParseRecords(): Failed to fread ";
-    cout << RecLength << " bytes.  Actually read " << ActualLength;
-    cout << " bytes - " << fn << "\n";
+    std::cout << "EMACSINFO::ParseRecords(): Failed to fread ";
+    std::cout << RecLength << " bytes.  Actually read " << ActualLength;
+    std::cout << " bytes - " << fn << "\n";
     delete [] RecBuffer;
     return;
   }
@@ -220,8 +220,8 @@ void EMACSINFO::ParseFields(PRECORD NewR
 
   pdft = new DFT();
   if(!pdft) {
-    cout << "EMACSINFO::ParseRecords(): Failed to allocate DFT - ";
-    cout << fn << "\n";
+    std::cout << "EMACSINFO::ParseRecords(): Failed to allocate DFT - ";
+    std::cout << fn << "\n";
     delete [] RecBuffer;
     return;
   }
@@ -284,7 +284,7 @@ STRING myBuff;
 ResultRecord.GetRecordData(&myBuff);
 STRINGINDEX firstNL = myBuff.Search('\n');
 if (firstNL == 0) {
-   cout << "FTP::Present() -- Can't find first Newline in file to present.\n";
+   std::cout << "FTP::Present() -- Can't find first Newline in file to present.\n";
    return;
    }
 
