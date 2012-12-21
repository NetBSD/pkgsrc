$NetBSD: patch-doctype_htmltag.cxx,v 1.1 2012/12/21 10:29:47 dholland Exp $

Chase after the C++ standard:
   - use the newfangled names for C++ headers
   - use "std" qualification
   - string constants are const char *

--- doctype/htmltag.cxx~	2000-02-24 20:51:21.000000000 +0000
+++ doctype/htmltag.cxx
@@ -7,10 +7,10 @@ Author:         Nassib Nassar <nassar@et
 
 #define HTMLTAG_MAX_TOKEN_LENGTH 4096
 
-#include <stdio.h>
-#include <ctype.h>
-#include <string.h>
-#include <iostream.h>
+#include <cstdio>
+#include <cctype>
+#include <cstring>
+#include <iostream>
 #include "isearch.hxx"
 #include "htmltag.hxx"
 
@@ -27,7 +27,7 @@ HTMLTAG::ParseFields(PRECORD NewRecord) 
   CHR* fn = filename.NewCString();
   FILE* fp = fopen(fn, "rb");
   if (!fp) {
-    cout << "HTMLTAG::ParseFields(): Failed to open file\n\t";
+    std::cout << "HTMLTAG::ParseFields(): Failed to open file\n\t";
     perror(fn);
     delete [] fn;
     return;
@@ -201,7 +201,7 @@ HTMLTAG::~HTMLTAG() {
 // e.g. if tag[] == "<META NAME=\"AUTHOR\" CONTENT=\"Nassar\">"
 //     and tagType[] == "META"
 // then TagMatch will return 1
-int HTMLTAG::TagMatch(char* tag, char* tagType) const {
+int HTMLTAG::TagMatch(const char* tag, const char* tagType) const {
 	// check first character
 	if (*tag != '<') {
 		return 0;
