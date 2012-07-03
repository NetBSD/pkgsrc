$NetBSD: patch-lexer.c,v 1.1 2012/07/03 18:13:26 joerg Exp $

--- lexer.c.orig	2012-07-03 10:49:15.000000000 +0000
+++ lexer.c
@@ -23,16 +23,19 @@
  *
  */
 
+#include <stdlib.h>
 #include <stdio.h>
+#include <string.h>
 #include <ctype.h>
 #include "as31.h"
 
+void error(const char *, ...);
+
 extern union ystack yylval;
 extern int pass;
 
 struct symbol *looksym();
 struct opcode *lookop();
-char *malloc();
 int lineno;
 
 static char line[100],*lineptr=line;
