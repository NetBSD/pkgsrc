$NetBSD: patch-yacc_verbose.c,v 1.2 2015/12/29 23:34:44 dholland Exp $

Avoid implicit int.
Use C89.

--- yacc/verbose.c.orig	2012-10-20 13:15:43.000000000 +0000
+++ yacc/verbose.c
@@ -4,7 +4,7 @@
 
 static short *null_rules;
 
-verbose()
+void verbose(void)
 {
     register int i;
 
