$NetBSD: patch-doctype_eos__guide.cxx,v 1.1 2012/12/21 10:29:46 dholland Exp $

Chase after the C++ standard:
   - use the newfangled names for C++ headers
   - use "std" qualification
   - string constants are const char *

--- doctype/eos_guide.cxx~	2000-11-02 05:37:08.000000000 +0000
+++ doctype/eos_guide.cxx
@@ -7,10 +7,10 @@ Author:         Nassib Nassar <nassar@et
 
 #define EOS_GUIDE_MAX_TOKEN_LENGTH 4096
 
-#include <stdio.h>
-#include <ctype.h>
-#include <string.h>
-#include <iostream.h>
+#include <cstdio>
+#include <cctype>
+#include <cstring>
+#include <iostream>
 #include "isearch.hxx"
 #include "eos_guide.hxx"
 
@@ -31,7 +31,7 @@ EOS_GUIDE::ParseFields(PRECORD NewRecord
   CHR* fn = filename.NewCString();
   FILE* fp = fopen(fn, "rb");
   if (!fp) {
-    cout << "EOS_GUIDE::ParseFields(): Failed to open file\n\t";
+    std::cout << "EOS_GUIDE::ParseFields(): Failed to open file\n\t";
     perror(fn);
     delete [] fn;
     return;
@@ -357,7 +357,7 @@ EOS_GUIDE::~EOS_GUIDE() {
 //     and tagType[] == "META"
 // then TagMatch will return 1
 INT 
-EOS_GUIDE::TagMatch(char* tag, char* tagType) const {
+EOS_GUIDE::TagMatch(const char* tag, const char* tagType) const {
   // check first character
   if (*tag != '<') {
     return 0;
