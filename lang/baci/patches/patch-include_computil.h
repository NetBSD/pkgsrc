$NetBSD: patch-include_computil.h,v 1.2 2015/12/29 23:34:43 dholland Exp $

Avoid symbol name conflict with strtoi.

--- include/computil.h.orig	2015-01-24 16:18:49.000000000 +0000
+++ include/computil.h
@@ -114,7 +114,7 @@ extern void stdproc_pcode(int px, int pc
 extern TYPES resulttype(TYPES a, TYPES b);
    /* used for checking the result type of a binary operator */
 
-extern unsigned int strtoi(char *str, int base);
+extern unsigned int my_strtoi(char *str, int base);
 /*
    interprets 'str' string as an unsigned integer in the base 'base'
    for 'base' == 2, 8, 10, or 16
