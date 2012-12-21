$NetBSD: patch-Isearch-cgi_isrch__srch.cxx,v 1.1 2012/12/21 10:29:46 dholland Exp $

Chase after the C++ standard:
   - use the newfangled names for C++ headers
   - open the std namespace instead of using explicit "std" qualification
   - string constants are const char *

--- Isearch-cgi/isrch_srch.cxx~	1998-05-18 19:22:06.000000000 +0000
+++ Isearch-cgi/isrch_srch.cxx
@@ -46,18 +46,18 @@ Authors:        Kevin Gamiel, kgamiel@cn
 		Archie Warnock, warnock@clark.net
 @@@*/
 
-#include <iostream.h>
-#include <stdio.h>
+#include <iostream>
+#include <cstdio>
 #include <sys/types.h>
 #include <sys/stat.h>
-#include <string.h>
+#include <cstring>
 #ifdef UNIX
 #include <sys/time.h>
 #else
 #include <time.h>
 #endif
 
-#include <locale.h>
+#include <clocale>
 
 #include "gdt.h"
 #include "isearch.hxx"
@@ -76,6 +76,8 @@ Authors:        Kevin Gamiel, kgamiel@cn
 #include "config.hxx"
 #include "cgi-util.hxx"
 
+using namespace std;
+
 #define SEARCH_TYPE(n)		((n) & SEARCH_TYPE_MASK)
 #define SEARCH_CLASS(n)		((n) & SEARCH_CLASS_MASK)
 
@@ -335,7 +337,7 @@ gettok(PCHR input)
 }
 
 PCHR
-get_field(PCHR f, INT n)
+get_field(PKCHR f, INT n)
 {
   PCHR bp;
   PCHR field;
