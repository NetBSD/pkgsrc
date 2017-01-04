$NetBSD: patch-src_lexer.l,v 1.1 2017/01/04 12:52:40 jperkin Exp $

Ensure the local yywrap is used.

--- src/lexer.l.orig	2010-09-01 22:29:25.000000000 +0000
+++ src/lexer.l
@@ -38,6 +38,7 @@ LICENSE TERMS
 /*#undef wchar_t*/
 /*#define wchar_t unsigned char*/
 
+#undef yywrap
 #ifndef yywrap
 static int yywrap(void)
 {
