$NetBSD: patch-doctype_dif.cxx,v 1.1 2012/12/21 10:29:46 dholland Exp $

Chase after the C++ standard:
   - use the newfangled names for C++ headers
   - use "std" qualification
   - string constants are const char *

--- doctype/dif.cxx~	2000-10-12 20:55:25.000000000 +0000
+++ doctype/dif.cxx
@@ -9,13 +9,13 @@ Author:		Archie Warnock, warnock@clark.n
 		Enhancements by Ken Lambert Hughes STX 3/97
 		Enhancements by Chris Gokey Hughes STX 3/98
 @@@*/
-#include <iostream.h>
-#include <fstream.h>
-#include <stdio.h>
-#include <stdlib.h>
-#include <string.h>
-#include <errno.h>
-#include <ctype.h>
+#include <iostream>
+#include <fstream>
+#include <cstdio>
+#include <cstdlib>
+#include <cstring>
+#include <cerrno>
+#include <cctype>
 #include "isearch.hxx"
 #include "glist.hxx"
 #include "gstack.hxx"
@@ -76,7 +76,7 @@ char multilineGroup[NO_MULTILINE_GROUPS]
                                                  "Project_Text",
                                                  "Source_Text",
                                                  "Sensor_Text" };
-void dbg(char *s) {
+void dbg(const char *s) {
   // printf("%s\n",s);
 }
 /* ========================= FROM FGDC doctype ========================*/
@@ -101,11 +101,11 @@ void DIF::LoadFieldTable() {
   Db->GetDocTypeOptions(&StrList);
   StrList.GetValue("FIELDTYPE", &FieldTypeFilename);
   if (FieldTypeFilename.GetLength() == 0) {
-    cout << "No fieldtype file specified.  Assuming all fields are text.";
-    cout << endl;
-    cout << "Make sure you use the correct doctype option:" << endl;
-    cout << endl;
-    cout << "    -o fieldtype=<filename>" << endl;
+    std::cout << "No fieldtype file specified.  Assuming all fields are text.";
+    std::cout << std::endl;
+    std::cout << "Make sure you use the correct doctype option:" << std::endl;
+    std::cout << std::endl;
+    std::cout << "    -o fieldtype=<filename>" << std::endl;
     return;
   }
   STRING Field_and_Type;
@@ -114,11 +114,11 @@ void DIF::LoadFieldTable() {
   PFILE fp = fopen(FieldTypeFilename, "r");
   // Let's bring the entire file into memory
   if (!fp) {
-    cout << "Specified fieldtype file not found.  Assuming all fields are text.";
-    cout << endl;
-    cout << "Make sure you use the correct doctype option:" << endl;
-    cout << endl;
-    cout << "    -o fieldtype=<filename>" << endl;
+    std::cout << "Specified fieldtype file not found.  Assuming all fields are text.";
+    std::cout << std::endl;
+    std::cout << "Make sure you use the correct doctype option:" << std::endl;
+    std::cout << std::endl;
+    std::cout << "    -o fieldtype=<filename>" << std::endl;
     return;
   }
   fseek(fp, 0, 2);
@@ -192,9 +192,9 @@ void DIF::ParseDate(const CHR *Buffer, D
 DOUBLE DIF::ParseDateSingle(const CHR *Buffer) {
   DOUBLE fVal;
   STRING Hold;
-  cout << "Parse Single Date:" << fVal << endl;
+  std::cout << "Parse Single Date:" << fVal << std::endl;
 #ifdef DEBUG
-  cout << "Parse Single Date." << endl;
+  std::cout << "Parse Single Date." << std::endl;
 #endif
   Hold = Buffer;
   //cout << "Hold = " << Hold << "." << endl;
@@ -207,7 +207,7 @@ DOUBLE DIF::ParseDateSingle(const CHR *B
   else if (Hold.IsNumber())
     fVal = Hold.GetFloat();
   else {
-    cout << "Bad date, value=" << Buffer << endl;
+    std::cout << "Bad date, value=" << Buffer << std::endl;
     fVal = -1.0;
   }
   if (fVal == 0) fVal = 99999999;
@@ -243,14 +243,14 @@ DIF::ParseDateRange(const CHR *Buffer, D
       }
       *fStart = dStart.GetValue();
     } else {
-      cerr << "[DIF::ParseDateRange] Didn't parse START_DATE, value=" 
-	   << Hold << endl;
+      std::cerr << "[DIF::ParseDateRange] Didn't parse START_DATE, value="
+	   << Hold << std::endl;
       *fStart = DATE_ERROR;
     }
   }
   else {
-    cerr << "[DIF::ParseDateRange] Didn't parse START_DATE, value=" 
-	 << Hold << endl;
+    std::cerr << "[DIF::ParseDateRange] Didn't parse START_DATE, value=" 
+	 << Hold << std::endl;
     *fStart = DATE_ERROR;
     *fEnd = *fStart;
     return;
@@ -795,7 +795,7 @@ void DIF::textML() {
   parserError("Error: expected text or end_group");
   dbg("</textML>");
 }
-void DIF::parserError(char *s) {  /* Parser error. */
+void DIF::parserError(const char *s) {  /* Parser error. */
 	fprintf(stdout,"***** %s ***** \n", s);
 }
 /*
