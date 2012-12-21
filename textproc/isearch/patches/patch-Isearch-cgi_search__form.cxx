$NetBSD: patch-Isearch-cgi_search__form.cxx,v 1.1 2012/12/21 10:29:46 dholland Exp $

Chase after the C++ standard:
   - use the newfangled names for C++ headers
   - open the std namespace instead of using explicit "std" qualification

--- Isearch-cgi/search_form.cxx~	2000-02-04 22:52:25.000000000 +0000
+++ Isearch-cgi/search_form.cxx
@@ -43,13 +43,13 @@ Description:    CGI app that builds a se
 Author:         Kevin Gamiel, kgamiel@cnidr.org
 @@@*/
 
-#include <iostream.h>
-#include <stdio.h>
+#include <iostream>
+#include <cstdio>
 #include <sys/types.h>
 #include <sys/stat.h>
-#include <string.h>
-#include <time.h>
-#include <locale.h>
+#include <cstring>
+#include <ctime>
+#include <clocale>
 
 #include "gdt.h"
 #include "isearch.hxx"
@@ -66,6 +66,8 @@ Author:         Kevin Gamiel, kgamiel@cn
 //#include "infix2rpn.hxx"
 #include "config.hxx"
 
+using namespace std;
+
 #define SIMPLE 1
 #define BOOLEAN 2
 #define ADVANCED 3
