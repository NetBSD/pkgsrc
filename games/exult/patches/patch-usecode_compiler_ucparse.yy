$NetBSD: patch-usecode_compiler_ucparse.yy,v 1.2 2011/12/21 16:58:15 dholland Exp $

 - use standard headers
 - const correctness demanded by gcc 4.5

--- usecode/compiler/ucparse.yy.orig	2003-09-18 06:37:05.000000000 +0000
+++ usecode/compiler/ucparse.yy
@@ -29,7 +29,7 @@ Foundation, Inc., 59 Temple Place - Suit
 #include <iostream>
 #include <stdio.h>
 #include <stdlib.h>
-#include <string.h>
+#include <cstring>
 #include <vector>
 
 #include "ucfun.h"
@@ -42,7 +42,7 @@ using std::strcpy;
 using std::strcat;
 using std::strlen;
 
-void yyerror(char *);
+void yyerror(const char *);
 extern int yylex();
 static Uc_array_expression *Create_array(int, Uc_expression *);
 static Uc_array_expression *Create_array(int, Uc_expression *, 
