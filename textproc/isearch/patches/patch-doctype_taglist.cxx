$NetBSD: patch-doctype_taglist.cxx,v 1.1 2012/12/21 10:29:47 dholland Exp $

Chase after the C++ standard:
   - use the newfangled names for C++ headers
   - use "std" qualification
   - string constants are const char *

--- doctype/taglist.cxx~	2000-10-12 20:55:25.000000000 +0000
+++ doctype/taglist.cxx
@@ -52,12 +52,12 @@ TODO:
 				based indexes.
 @@@*/
 
-#include <iostream.h>
-#include <stdio.h>
-#include <stdlib.h>
-#include <string.h>
-#include <errno.h>
-#include <ctype.h>
+#include <iostream>
+#include <cstdio>
+#include <cstdlib>
+#include <cstring>
+#include <cerrno>
+#include <cctype>
 #include "isearch.hxx"
 #include "taglist.hxx"
 
@@ -103,7 +103,7 @@ TAGLIST::ReplaceWithSpace(PCHR data, INT
 	*p = '\0';			// Add a NULL to terminate the record
 }
 
-char *ValidTags[] = {"TITLE",
+const char *ValidTags[] = {"TITLE",
 					"H1",
 					"H2",
 					"H3",
@@ -162,7 +162,7 @@ TAGLIST::ParseFields(PRECORD NewRecord) 
   file = fn.NewCString();
   fp = fopen(fn, "rb");
   if (!fp) {
-    cout << "SGMLTAG::ParseRecords(): Failed to open file\n\t";
+    std::cout << "SGMLTAG::ParseRecords(): Failed to open file\n\t";
     perror(file);
     return;
   }
@@ -172,16 +172,16 @@ TAGLIST::ParseFields(PRECORD NewRecord) 
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
@@ -190,7 +190,7 @@ TAGLIST::ParseFields(PRECORD NewRecord) 
 
   // Make two copies of the record in memory
   if(fseek(fp, (long)RecStart, SEEK_SET) == -1) {
-    cout << "SGMLTAG::ParseRecords(): Seek failed - " << fn << "\n";
+    std::cout << "SGMLTAG::ParseRecords(): Seek failed - " << fn << "\n";
     fclose(fp);
     return;	
   }
@@ -198,15 +198,15 @@ TAGLIST::ParseFields(PRECORD NewRecord) 
 	
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
@@ -214,7 +214,7 @@ TAGLIST::ParseFields(PRECORD NewRecord) 
 
   ActualLength = (GPTYPE)fread(RecBuffer, 1, RecLength, fp);
   if(ActualLength == 0) {
-    cout << "SGMLTAG::ParseRecords(): Failed to fread\n\t";
+    std::cout << "SGMLTAG::ParseRecords(): Failed to fread\n\t";
     perror(file);
     delete [] RecBuffer;
     delete [] OrigRecBuffer;
@@ -223,9 +223,9 @@ TAGLIST::ParseFields(PRECORD NewRecord) 
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
@@ -249,15 +249,15 @@ TAGLIST::ParseFields(PRECORD NewRecord) 
 
   pdft = new DFT();
   if(!pdft) {
-    cout << "SGMLTAG::ParseRecords(): Failed to allocate DFT - ";
-    cout << fn << "\n";
+    std::cout << "SGMLTAG::ParseRecords(): Failed to allocate DFT - ";
+    std::cout << fn << "\n";
     delete [] RecBuffer;
     delete [] OrigRecBuffer;
     return;
   }
   tags = sgml_parse_tags(RecBuffer, RecLength, &numtags);
   if(tags == NULL) {
-    cout << "Unable to parse SGML file " << fn << "\n";
+    std::cout << "Unable to parse SGML file " << fn << "\n";
     delete pdft;
     delete [] RecBuffer;
     delete [] OrigRecBuffer;
@@ -348,7 +348,7 @@ TAGLIST::ParseWords(
 			{
 				if (GpListSize >= GpLength) 
 				{
-					cout << "GpListSize >= GpLength" << endl;
+					std::cout << "GpListSize >= GpLength" << std::endl;
 					exit(1);
 				}
 				GpBuffer[GpListSize++] = DataOffset + Position;
