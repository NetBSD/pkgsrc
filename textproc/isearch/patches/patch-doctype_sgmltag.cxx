$NetBSD: patch-doctype_sgmltag.cxx,v 1.1 2012/12/21 10:29:47 dholland Exp $

Chase after the C++ standard:
   - use the newfangled names for C++ headers
   - use "std" qualification

--- doctype/sgmltag.cxx~	2000-02-04 22:50:50.000000000 +0000
+++ doctype/sgmltag.cxx
@@ -51,11 +51,11 @@ Changes:	1.02
 			- Misc Error checking
 @@@*/
 
-#include <iostream.h>
-#include <stdio.h>
-#include <stdlib.h>
-#include <string.h>
-#include <errno.h>
+#include <iostream>
+#include <cstdio>
+#include <cstdlib>
+#include <cstring>
+#include <cerrno>
 #include "isearch.hxx"
 #include "sgmltag.hxx"
 
@@ -101,7 +101,7 @@ SGMLTAG::ParseFields(PRECORD NewRecord) 
   file = fn.NewCString();
   fp = fopen(fn, "rb");
   if (!fp) {
-    cout << "SGMLTAG::ParseRecords(): Failed to open file\n\t";
+    std::cout << "SGMLTAG::ParseRecords(): Failed to open file\n\t";
     perror(file);
     return;
   }
@@ -111,16 +111,16 @@ SGMLTAG::ParseFields(PRECORD NewRecord) 
   RecEnd = NewRecord->GetRecordEnd();
   if (RecEnd == 0) {
     if(fseek(fp, 0L, SEEK_END) == -1) {
-      cout << "SGMLTAG::ParseRecords(): Seek failed - ";
-      cout << fn << "\n";
+      std::cout << "SGMLTAG::ParseRecords(): Seek failed - ";
+      std::cout << fn << "\n";
       fclose(fp);
       return;	
     }
     RecStart = 0;
     RecEnd = ftell(fp);
     if(RecEnd == 0) {
-      cout << "SGMLTAG::ParseRecords(): Skipping ";
-      cout << " zero-length record -" << fn << "...\n";
+      std::cout << "SGMLTAG::ParseRecords(): Skipping ";
+      std::cout << " zero-length record -" << fn << "...\n";
       fclose(fp);
       return;
     }
@@ -129,7 +129,7 @@ SGMLTAG::ParseFields(PRECORD NewRecord) 
 
   // Make two copies of the record in memory
   if(fseek(fp, (long)RecStart, SEEK_SET) == -1) {
-    cout << "SGMLTAG::ParseRecords(): Seek failed - " << fn << "\n";
+    std::cout << "SGMLTAG::ParseRecords(): Seek failed - " << fn << "\n";
     fclose(fp);
     return;	
   }
@@ -137,15 +137,15 @@ SGMLTAG::ParseFields(PRECORD NewRecord) 
 	
   RecBuffer = new CHR[RecLength + 1];
   if(!RecBuffer) {
-    cout << "SGMLTAG::ParseRecords(): Failed to allocate ";
-    cout << RecLength + 1 << " bytes - " << fn << "\n";
+    std::cout << "SGMLTAG::ParseRecords(): Failed to allocate ";
+    std::cout << RecLength + 1 << " bytes - " << fn << "\n";
     fclose(fp);
     return;
   }
   OrigRecBuffer = new CHR[RecLength + 1];
   if(!OrigRecBuffer) {
-    cout << "SGMLTAG::ParseRecords(): Failed to allocate ";
-    cout << RecLength + 1 << " bytes - " << fn << "\n";
+    std::cout << "SGMLTAG::ParseRecords(): Failed to allocate ";
+    std::cout << RecLength + 1 << " bytes - " << fn << "\n";
     delete [] RecBuffer;
     fclose(fp);
     return;
@@ -153,7 +153,7 @@ SGMLTAG::ParseFields(PRECORD NewRecord) 
 
   ActualLength = (GPTYPE)fread(RecBuffer, 1, RecLength, fp);
   if(ActualLength == 0) {
-    cout << "SGMLTAG::ParseRecords(): Failed to fread\n\t";
+    std::cout << "SGMLTAG::ParseRecords(): Failed to fread\n\t";
     perror(file);
     delete [] RecBuffer;
     delete [] OrigRecBuffer;
@@ -162,9 +162,9 @@ SGMLTAG::ParseFields(PRECORD NewRecord) 
   }
   fclose(fp);
   if(ActualLength != RecLength) {
-    cout << "SGMLTAG::ParseRecords(): Failed to fread ";
-    cout << RecLength << " bytes.  Actually read " << ActualLength;
-    cout << " bytes - " << fn << "\n";
+    std::cout << "SGMLTAG::ParseRecords(): Failed to fread ";
+    std::cout << RecLength << " bytes.  Actually read " << ActualLength;
+    std::cout << " bytes - " << fn << "\n";
     delete [] RecBuffer;
     delete [] OrigRecBuffer;
     return;
@@ -189,8 +189,8 @@ SGMLTAG::ParseFields(PRECORD NewRecord) 
 
   pdft = new DFT();
   if(!pdft) {
-    cout << "SGMLTAG::ParseRecords(): Failed to allocate DFT - ";
-    cout << fn << "\n";
+    std::cout << "SGMLTAG::ParseRecords(): Failed to allocate DFT - ";
+    std::cout << fn << "\n";
     delete [] RecBuffer;
     delete [] OrigRecBuffer;
     return;
@@ -198,7 +198,7 @@ SGMLTAG::ParseFields(PRECORD NewRecord) 
   //  tags = sgml_parse_tags(RecBuffer, RecLength);
   tags = sgml_parse_tags(RecBuffer, RecLength, &numtags);
   if(tags == NULL) {
-    cout << "Unable to parse SGML file " << fn << "\n";
+    std::cout << "Unable to parse SGML file " << fn << "\n";
     delete pdft;
     delete [] RecBuffer;
     delete [] OrigRecBuffer;
@@ -272,7 +272,7 @@ SGMLTAG::sgml_parse_tags(char *b, int le
 
   t = new CHR*[128];
   if(!t) {
-    cout << "SGMLTAG::sgml_parse_tags(): Out of memory\n";
+    std::cout << "SGMLTAG::sgml_parse_tags(): Out of memory\n";
     return NULL;
   }
   max_num_tags = TAG_GROW_SIZE;
