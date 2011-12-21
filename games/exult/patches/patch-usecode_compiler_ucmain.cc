$NetBSD: patch-usecode_compiler_ucmain.cc,v 1.2 2011/12/21 16:58:15 dholland Exp $

 - use standard headers
 - const correctness demanded by gcc 4.5

--- usecode/compiler/ucmain.cc.orig	2003-09-18 06:37:05.000000000 +0000
+++ usecode/compiler/ucmain.cc
@@ -29,6 +29,7 @@ Foundation, Inc., 59 Temple Place - Suit
 #include <fstream>
 #include <unistd.h>
 #include <stdio.h>
+#include <cstring>
 #include <string>
 #include <vector>
 #include "ucloc.h"
@@ -133,7 +134,7 @@ int main
  */
 void yyerror
 	(
-	char *s
+	const char *s
 	)
 	{
 	Uc_location::yyerror(s);
