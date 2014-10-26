$NetBSD: patch-grammar_lexer.l,v 1.2 2014/10/26 21:11:09 fhajny Exp $

Fix build on BSD.
--- grammar/lexer.l.orig	2014-10-02 10:27:30.000000000 +0000
+++ grammar/lexer.l
@@ -31,7 +31,7 @@
 %{
 #include "config.h"
 #include "parserif.h"
-extern char *strdup(__const char*); /* somehow we may not get this from string.h... */
+// extern char *strdup(__const char*); /* somehow we may not get this from string.h... */
 %}
 
 %option noyywrap nodefault case-insensitive yylineno
@@ -92,7 +92,7 @@ extern int yydebug;
 /* somehow, I need these prototype even though the headers are 
  * included. I guess that's some autotools magic I don't understand...
  */
-#if !defined(__FreeBSD__)
+#if !defined(__FreeBSD__) && !defined(__NetBSD__) && !defined(__OpenBSD__) && !defined(__DragonflyBSD__)
 int fileno(FILE *stream);
 #endif
 
