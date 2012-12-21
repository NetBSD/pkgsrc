$NetBSD: patch-doctype_filename.cxx,v 1.1 2012/12/21 10:29:47 dholland Exp $

Chase after the C++ standard:
   - use the newfangled names for C++ headers
   - use "std" qualification

--- doctype/filename.cxx~	1998-02-26 01:50:24.000000000 +0000
+++ doctype/filename.cxx
@@ -6,7 +6,7 @@ Description: class FILENAME - index file
 Author:      Erik Scott, Scott Technologies, Inc.
 */
 
-#include <ctype.h>
+#include <cctype>
 #include "isearch.hxx"
 #include "filename.hxx"
 
@@ -46,7 +46,7 @@ void FILENAME::ParseRecords(const RECORD
 
   FILE *fnfp = fopen(newfilename,"wb");
   if (fnfp == NULL) {
-    cout << "Cannot write file " << newfilename << ", bailing out.\n";
+    std::cout << "Cannot write file " << newfilename << ", bailing out.\n";
     return; // leaking all the way...
   }
 
@@ -122,7 +122,7 @@ void FILENAME::Present(const RESULT& Res
   PFILE fp = fopen (hackedFN, "rb");
   if (!fp)
     {
-      cout << "Could not access '" << hackedFN << "'\n";
+      std::cout << "Could not access '" << hackedFN << "'\n";
       return;			// File not accessed
 
     }
@@ -130,8 +130,8 @@ void FILENAME::Present(const RESULT& Res
   
 
   if(fseek(fp, 0L, SEEK_END) == -1) {
-    cout << "FILENAME::Present(): Seek failed (I) - ";
-    cout << hackedFN << "\n";
+    std::cout << "FILENAME::Present(): Seek failed (I) - ";
+    std::cout << hackedFN << "\n";
     fclose(fp);
     return;	
   }
@@ -139,15 +139,15 @@ void FILENAME::Present(const RESULT& Res
   GPTYPE RecStart = 0;
   GPTYPE RecEnd = ftell(fp);
   if(RecEnd == 0) {
-    cout << "FILENAME::Present(): Skipping ";
-    cout << " zero-length record -" << hackedFN << "...\n";
+    std::cout << "FILENAME::Present(): Skipping ";
+    std::cout << " zero-length record -" << hackedFN << "...\n";
     fclose(fp);
     return;
   }
 
 
   if(fseek(fp, (long)RecStart, SEEK_SET) == -1) {
-    cout << "FILENAME::Present(): Seek failed (II) - " << hackedFN << "\n";
+    std::cout << "FILENAME::Present(): Seek failed (II) - " << hackedFN << "\n";
     fclose(fp);
     return;	
   }
@@ -156,24 +156,24 @@ void FILENAME::Present(const RESULT& Res
 	
   PCHR RecBuffer = new CHR[RecLength + 2];
   if(!RecBuffer) {
-    cout << "FILENAME::Present(): Failed to allocate ";
-    cout << RecLength + 1 << " bytes - " << hackedFN << "\n";
+    std::cout << "FILENAME::Present(): Failed to allocate ";
+    std::cout << RecLength + 1 << " bytes - " << hackedFN << "\n";
     fclose(fp);
     return;
   }
 
   GPTYPE ActualLength = (GPTYPE)fread(RecBuffer, 1, RecLength, fp);
   if(ActualLength == 0) {
-    cout << "FILENAME::Present(): Failed to fread\n";
+    std::cout << "FILENAME::Present(): Failed to fread\n";
     delete [] RecBuffer;
     fclose(fp);
     return;
   }
   fclose(fp);
   if(ActualLength != RecLength) {
-    cout << "FILENAME::Present(): Failed to fread ";
-    cout << RecLength << " bytes.  Actually read " << ActualLength;
-    cout << " bytes - " << hackedFN << "\n";
+    std::cout << "FILENAME::Present(): Failed to fread ";
+    std::cout << RecLength << " bytes.  Actually read " << ActualLength;
+    std::cout << " bytes - " << hackedFN << "\n";
     delete [] RecBuffer;
     return;
   }
