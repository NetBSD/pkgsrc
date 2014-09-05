$NetBSD: patch-grammar_lexer.l,v 1.1 2014/09/05 07:15:41 fhajny Exp $

Fix build on BSD.
--- grammar/lexer.l.orig	2014-08-18 09:14:06.000000000 +0000
+++ grammar/lexer.l
@@ -31,7 +31,7 @@
 %{
 #include "config.h"
 #include "parserif.h"
-extern char *strdup(char*); /* somehow we do not get this from string.h... */
+// extern char *strdup(char*); /* somehow we do not get this from string.h... */
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
 
