$NetBSD: patch-usecode_compiler_ucloc.cc,v 1.2 2011/12/21 16:58:15 dholland Exp $

- use standard headers
- const correctness demanded by gcc 4.5

--- usecode/compiler/ucloc.cc.orig	2002-06-04 21:00:00.000000000 +0000
+++ usecode/compiler/ucloc.cc
@@ -27,6 +27,7 @@ Foundation, Inc., 59 Temple Place - Suit
 #endif
 
 #include <iostream>
+#include <cstring>
 #include "ucloc.h"
 
 using std::strcmp;
@@ -88,7 +89,7 @@ void Uc_location::error
 
 void Uc_location::yyerror
 	(
-	char *s
+	const char *s
 	)
 	{
 	cout << cur_source << ':' << cur_line + 1 << ": " << s << endl;
