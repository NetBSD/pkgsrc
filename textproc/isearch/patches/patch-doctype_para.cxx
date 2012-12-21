$NetBSD: patch-doctype_para.cxx,v 1.1 2012/12/21 10:29:47 dholland Exp $

Chase after the C++ standard:
   - use "std" qualification

--- doctype/para.cxx~	1997-03-11 14:40:22.000000000 +0000
+++ doctype/para.cxx
@@ -27,7 +27,7 @@ void PARA::ParseRecords(const RECORD& Fi
   PFILE fp = fopen (fn, "rb");
   if (!fp)
     {
-      cout << "Could not access '" << fn << "'\n";
+      std::cout << "Could not access '" << fn << "'\n";
       return;			// File not accessed
 
     }
@@ -48,8 +48,8 @@ void PARA::ParseRecords(const RECORD& Fi
   
 
   if(fseek(fp, 0L, SEEK_END) == -1) {
-    cout << "PARA::ParseRecords(): Seek failed - ";
-    cout << fn << "\n";
+    std::cout << "PARA::ParseRecords(): Seek failed - ";
+    std::cout << fn << "\n";
     fclose(fp);
     return;	
   }
@@ -57,15 +57,15 @@ void PARA::ParseRecords(const RECORD& Fi
   RecStart = 0;
   RecEnd = ftell(fp);
   if(RecEnd == 0) {
-    cout << "PARA::ParseRecords(): Skipping ";
-    cout << " zero-length record -" << fn << "...\n";
+    std::cout << "PARA::ParseRecords(): Skipping ";
+    std::cout << " zero-length record -" << fn << "...\n";
     fclose(fp);
     return;
   }
 
 
   if(fseek(fp, (long)RecStart, SEEK_SET) == -1) {
-    cout << "PARA::ParseRecords(): Seek failed - " << fn << "\n";
+    std::cout << "PARA::ParseRecords(): Seek failed - " << fn << "\n";
     fclose(fp);
     return;	
   }
@@ -74,24 +74,24 @@ void PARA::ParseRecords(const RECORD& Fi
 	
   RecBuffer = new CHR[RecLength + 2];
   if(!RecBuffer) {
-    cout << "PARA::ParseRecords(): Failed to allocate ";
-    cout << RecLength + 1 << " bytes - " << fn << "\n";
+    std::cout << "PARA::ParseRecords(): Failed to allocate ";
+    std::cout << RecLength + 1 << " bytes - " << fn << "\n";
     fclose(fp);
     return;
   }
 
   ActualLength = (GPTYPE)fread(RecBuffer, 1, RecLength, fp);
   if(ActualLength == 0) {
-    cout << "PARA::ParseRecords(): Failed to fread\n";
+    std::cout << "PARA::ParseRecords(): Failed to fread\n";
     delete [] RecBuffer;
     fclose(fp);
     return;
   }
   fclose(fp);
   if(ActualLength != RecLength) {
-    cout << "PARA::ParseRecords(): Failed to fread ";
-    cout << RecLength << " bytes.  Actually read " << ActualLength;
-    cout << " bytes - " << fn << "\n";
+    std::cout << "PARA::ParseRecords(): Failed to fread ";
+    std::cout << RecLength << " bytes.  Actually read " << ActualLength;
+    std::cout << " bytes - " << fn << "\n";
     delete [] RecBuffer;
     return;
   }
