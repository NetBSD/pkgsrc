$NetBSD: patch-Isearch-cgi_isrch__fetch.cxx,v 1.1 2012/12/21 10:29:46 dholland Exp $

Chase after the C++ standard:
   - use the newfangled names for C++ headers
   - open the std namespace instead of using explicit "std" qualification

--- Isearch-cgi/isrch_fetch.cxx~	2000-02-04 22:52:25.000000000 +0000
+++ Isearch-cgi/isrch_fetch.cxx
@@ -43,12 +43,12 @@ Description:    CGI app that searches ag
 Author:         Kevin Gamiel, kgamiel@cnidr.org
 @@@*/
 
-#include <iostream.h>
-#include <stdio.h>
+#include <iostream>
+#include <cstdio>
 #include <sys/types.h>
 #include <sys/stat.h>
-#include <string.h>
-#include <locale.h>
+#include <cstring>
+#include <clocale>
 
 #include "gdt.h"
 #include "isearch.hxx"
@@ -66,6 +66,8 @@ Author:         Kevin Gamiel, kgamiel@cn
 //#include "infix2rpn.hxx"
 #include "config.hxx"
 
+using namespace std;
+
 int main(int argc, char **argv)
 {
   STRING DBPathName, DBRootName, Record;
