$NetBSD: patch-src-lexer.l,v 1.2 2012/03/26 11:56:12 obache Exp $

* yylineno is present in all scanners by flex>=2.5.20 

--- src/lexer.l.orig	1998-09-15 16:46:49.000000000 +0000
+++ src/lexer.l
@@ -176,7 +176,12 @@ PROTOTYPE(parse_eof,
 
 #define	YYTEXT	yytext
 
+#if !defined(YY_FLEX_MAJOR_VERSION) || \
+	(YY_FLEX_MAJOR_VERSION == 2 && (YY_FLEX_MINOR_VERSION < 5) || \
+	(YY_FLEX_MINOR_VERSION == 5 && (!defined(YY_FLEX_SUBMINOR_VERSION) || \
+					YY_FLEX_SUBMINOR_VERSION < 20)))
 int yylineno = 0;
+#endif
 
 #undef	YY_INPUT
 #define	YY_INPUT(buf, result, max_size) \
