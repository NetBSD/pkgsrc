$NetBSD: patch-rclex.l,v 1.1 2011/12/22 00:28:20 joerg Exp $

--- rclex.l.orig	2011-12-22 00:05:52.000000000 +0000
+++ rclex.l
@@ -15,7 +15,6 @@
  * the Makefile from the Imakefile (with "xmkmf" or whatever else you
  * used the first time), and (d) trying to compile again.
  */
-int yylineno = 1;
 #define YYLINE yylineno++
 #undef yywrap
 #else
