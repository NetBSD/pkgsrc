$NetBSD: patch-rclex.l,v 1.2 2012/05/03 09:08:11 obache Exp $

* yylineno is present in all scanners by flex>=2.5.20 

--- rclex.l.orig	1997-06-05 11:11:42.000000000 +0000
+++ rclex.l
@@ -15,7 +15,12 @@
  * the Makefile from the Imakefile (with "xmkmf" or whatever else you
  * used the first time), and (d) trying to compile again.
  */
-int yylineno = 1;
+#if !defined(YY_FLEX_MAJOR_VERSION) || \
+	(YY_FLEX_MAJOR_VERSION == 2 && (YY_FLEX_MINOR_VERSION < 5) || \
+	(YY_FLEX_MINOR_VERSION == 5 && (!defined(YY_FLEX_SUBMINOR_VERSION) || \
+					YY_FLEX_SUBMINOR_VERSION < 20)))
+int yylineno = 0;
+#endif
 #define YYLINE yylineno++
 #undef yywrap
 #else
