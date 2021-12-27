$NetBSD: patch-src_lexer.l,v 1.2 2021/12/27 04:27:10 dholland Exp $

Ensure the local yywrap is used.

Use the right type for "clclex"; otherwise the link fails on some
platforms. (And on others, the behavior is probably undefined...)

--- src/lexer.l.orig	2010-09-01 22:29:25.000000000 +0000
+++ src/lexer.l
@@ -38,6 +38,7 @@ LICENSE TERMS
 /*#undef wchar_t*/
 /*#define wchar_t unsigned char*/
 
+#undef yywrap
 #ifndef yywrap
 static int yywrap(void)
 {
@@ -68,7 +69,7 @@ int sparkearslev = 0;
    By default, the C-INTERCAL meanings are used; the extern variable clclex
    causes CLC-INTERCAL interpretations to be put on the ambiguous symbols.
    Otherwise, mixing syntaxes freely is allowed. */
-extern int clclex;
+extern bool clclex;
 
 #ifdef FLEX_SCANNER
 static char linebuf[YY_BUF_SIZE];
