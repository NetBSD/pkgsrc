$NetBSD: patch-grammar_lexer.l,v 1.3 2014/12/12 12:47:46 fhajny Exp $

Fix build on BSD.
--- grammar/lexer.l.orig	2014-12-02 10:15:16.000000000 +0000
+++ grammar/lexer.l
@@ -95,7 +95,7 @@ extern int yydebug;
 /* somehow, I need these prototype even though the headers are 
  * included. I guess that's some autotools magic I don't understand...
  */
-#if !defined(__FreeBSD__)
+#if !defined(__FreeBSD__) && !defined(__NetBSD__) && !defined(__OpenBSD__) && !defined(__DragonflyBSD__)
 int fileno(FILE *stream);
 #endif
 
