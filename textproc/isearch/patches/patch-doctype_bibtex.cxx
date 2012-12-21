$NetBSD: patch-doctype_bibtex.cxx,v 1.1 2012/12/21 10:29:46 dholland Exp $

Chase after the C++ standard:
   - use the newfangled names for C++ headers
   - use "std" qualification
   - string constants are const char *

--- doctype/bibtex.cxx~	1998-05-12 16:48:27.000000000 +0000
+++ doctype/bibtex.cxx
@@ -8,8 +8,8 @@ Description: class BIBTEX - index docume
 Author:      Erik Scott, Scott Technologies, Inc.
 */
 
-#include <iostream.h>
-#include <ctype.h>
+#include <iostream>
+#include <cctype>
 #include "isearch.hxx"
 #include "bibtex.hxx"
 
@@ -30,7 +30,7 @@ void BIBTEX::ParseRecords(const RECORD& 
   PFILE fp = fopen (fn, "rb");
   if (!fp)
     {
-      cout << "Could not access '" << fn << "'\n";
+      std::cout << "Could not access '" << fn << "'\n";
       return;			// File not accessed
       
     }
@@ -51,8 +51,8 @@ void BIBTEX::ParseRecords(const RECORD& 
   
   
   if(fseek(fp, 0L, SEEK_END) == -1) {
-    cout << "BIBTEX::ParseRecords(): Seek failed - ";
-    cout << fn << "\n";
+    std::cout << "BIBTEX::ParseRecords(): Seek failed - ";
+    std::cout << fn << "\n";
     fclose(fp);
     return;	
   }
@@ -60,15 +60,15 @@ void BIBTEX::ParseRecords(const RECORD& 
   RecStart = 0;
   RecEnd = ftell(fp);
   if(RecEnd == 0) {
-    cout << "BIBTEX::ParseRecords(): Skipping ";
-    cout << " zero-length record -" << fn << "...\n";
+    std::cout << "BIBTEX::ParseRecords(): Skipping ";
+    std::cout << " zero-length record -" << fn << "...\n";
     fclose(fp);
     return;
   }
   
   
   if(fseek(fp, (long)RecStart, SEEK_SET) == -1) {
-    cout << "BIBTEX::ParseRecords(): Seek failed - " << fn << "\n";
+    std::cout << "BIBTEX::ParseRecords(): Seek failed - " << fn << "\n";
     fclose(fp);
     return;	
   }
@@ -77,24 +77,24 @@ void BIBTEX::ParseRecords(const RECORD& 
   
   RecBuffer = new CHR[RecLength + 2];
   if(!RecBuffer) {
-    cout << "BIBTEX::ParseRecords(): Failed to allocate ";
-    cout << RecLength + 1 << " bytes - " << fn << "\n";
+    std::cout << "BIBTEX::ParseRecords(): Failed to allocate ";
+    std::cout << RecLength + 1 << " bytes - " << fn << "\n";
     fclose(fp);
     return;
   }
   
   ActualLength = (GPTYPE)fread(RecBuffer, 1, RecLength, fp);
   if(ActualLength == 0) {
-    cout << "BIBTEX::ParseRecords(): Failed to fread\n";
+    std::cout << "BIBTEX::ParseRecords(): Failed to fread\n";
     delete [] RecBuffer;
     fclose(fp);
     return;
   }
   fclose(fp);
   if(ActualLength != RecLength) {
-    cout << "BIBTEX::ParseRecords(): Failed to fread ";
-    cout << RecLength << " bytes.  Actually read " << ActualLength;
-    cout << " bytes - " << fn << "\n";
+    std::cout << "BIBTEX::ParseRecords(): Failed to fread ";
+    std::cout << RecLength << " bytes.  Actually read " << ActualLength;
+    std::cout << " bytes - " << fn << "\n";
     delete [] RecBuffer;
     return;
   }
@@ -145,7 +145,7 @@ void BIBTEX::ParseFields(PRECORD NewReco
   file = fn.NewCString();
   fp = fopen(fn, "rb");
   if (!fp) {
-    cout << "BIBTEX::ParseRecords(): Failed to open file\n\t";
+    std::cout << "BIBTEX::ParseRecords(): Failed to open file\n\t";
     perror(file);
     return;
   }
@@ -156,16 +156,16 @@ void BIBTEX::ParseFields(PRECORD NewReco
   
   if (RecEnd == 0) {
     if(fseek(fp, 0L, SEEK_END) == -1) {
-      cout << "BIBTEX::ParseRecords(): Seek failed - ";
-      cout << fn << "\n";
+      std::cout << "BIBTEX::ParseRecords(): Seek failed - ";
+      std::cout << fn << "\n";
       fclose(fp);
       return;	
     }
     RecStart = 0;
     RecEnd = ftell(fp);
     if(RecEnd == 0) {
-      cout << "BIBTEX::ParseRecords(): Skipping ";
-      cout << " zero-length record -" << fn << "...\n";
+      std::cout << "BIBTEX::ParseRecords(): Skipping ";
+      std::cout << " zero-length record -" << fn << "...\n";
       fclose(fp);
       return;
     }
@@ -174,7 +174,7 @@ void BIBTEX::ParseFields(PRECORD NewReco
   
   // Make two copies of the record in memory
   if(fseek(fp, (long)RecStart, SEEK_SET) == -1) {
-    cout << "BIBTEX::ParseRecords(): Seek failed - " << fn << "\n";
+    std::cout << "BIBTEX::ParseRecords(): Seek failed - " << fn << "\n";
     fclose(fp);
     return;	
   }
@@ -182,15 +182,15 @@ void BIBTEX::ParseFields(PRECORD NewReco
   
   RecBuffer = new CHR[RecLength + 1];
   if(!RecBuffer) {
-    cout << "BIBTEX::ParseRecords(): Failed to allocate ";
-    cout << RecLength + 1 << " bytes - " << fn << "\n";
+    std::cout << "BIBTEX::ParseRecords(): Failed to allocate ";
+    std::cout << RecLength + 1 << " bytes - " << fn << "\n";
     fclose(fp);
     return;
   }
   
   ActualLength = (GPTYPE)fread(RecBuffer, 1, RecLength, fp);
   if(ActualLength == 0) {
-    cout << "BIBTEX::ParseRecords(): Failed to fread\n\t";
+    std::cout << "BIBTEX::ParseRecords(): Failed to fread\n\t";
     perror(file);
     delete [] RecBuffer;
     fclose(fp);
@@ -198,9 +198,9 @@ void BIBTEX::ParseFields(PRECORD NewReco
   }
   fclose(fp);
   if(ActualLength != RecLength) {
-    cout << "BIBTEX::ParseRecords(): Failed to fread ";
-    cout << RecLength << " bytes.  Actually read " << ActualLength;
-    cout << " bytes - " << fn << "\n";
+    std::cout << "BIBTEX::ParseRecords(): Failed to fread ";
+    std::cout << RecLength << " bytes.  Actually read " << ActualLength;
+    std::cout << " bytes - " << fn << "\n";
     delete [] RecBuffer;
     return;
   }
@@ -222,8 +222,8 @@ void BIBTEX::ParseFields(PRECORD NewReco
   
   pdft = new DFT();
   if(!pdft) {
-    cout << "BIBTEX::ParseRecords(): Failed to allocate DFT - ";
-    cout << fn << "\n";
+    std::cout << "BIBTEX::ParseRecords(): Failed to allocate DFT - ";
+    std::cout << fn << "\n";
     delete [] RecBuffer;
     return;
   }
@@ -261,12 +261,12 @@ void BIBTEX::ParseFields(PRECORD NewReco
 		  }
 		}
 		if (i==ActualLength) {
-		  cout << "Cannot find quote mark after title.\n";
+		  std::cout << "Cannot find quote mark after title.\n";
 		  return;
 		}
 		for (i=val_start+1; (RecBuffer[i]!='"') && (i<ActualLength); i++);
 		if (i==ActualLength) {
-		  cout << "couldn't find ending quote.\n";
+		  std::cout << "couldn't find ending quote.\n";
 		  return;
 		}
 		else {
