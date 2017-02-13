$NetBSD: patch-grammar_lexer.l,v 1.4 2017/02/13 19:59:36 fhajny Exp $

Fix build on BSD.
--- grammar/lexer.l.orig	2017-01-10 09:00:04.000000000 +0000
+++ grammar/lexer.l
@@ -102,7 +102,7 @@ extern int yydebug;
 /* somehow, I need these prototype even though the headers are 
  * included. I guess that's some autotools magic I don't understand...
  */
-#if !defined(__FreeBSD__) && !defined(_AIX)
+#if !defined(__FreeBSD__) && !defined(__NetBSD__) && !defined(__OpenBSD__) && !defined(__DragonflyBSD__) && !defined(_AIX)
 int fileno(FILE *stream);
 #endif
 
