$NetBSD: patch-src_expbuilder.c,v 1.2 2015/12/29 23:34:44 dholland Exp $

Avoid implicit int.
Use C89.

--- src/expbuilder.c.orig	2012-10-26 13:06:11.000000000 +0000
+++ src/expbuilder.c
@@ -195,7 +195,7 @@ struct EXP *elook()
 
 /* Bygger opp et uttrykstree, Alle operatorene leses postfix */
 
-ebuild ()
+void ebuild (void)
 {
   struct EXP *re;
 
