$NetBSD: patch-src_parse-yy.h,v 1.1 2017/01/04 12:46:06 jperkin Exp $

Ensure the local yywrap is used.

--- src/parse-yy.h.orig	2010-12-27 09:55:02.000000000 +0000
+++ src/parse-yy.h
@@ -87,6 +87,7 @@ void yyrestart (FILE *input_file);
 
 #define YY_SKIP_YYWRAP 1 /* Don't use yywrap prototype */
 
+#undef yywrap
 #ifndef yywrap
 
 /*+ Needed in lex but does nothing. +*/
