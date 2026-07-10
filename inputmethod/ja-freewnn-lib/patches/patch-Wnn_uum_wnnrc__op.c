$NetBSD: patch-Wnn_uum_wnnrc__op.c,v 1.1 2026/07/10 23:32:38 tsutsui Exp $

- Remove unnecessary old style declaration for standard C function

--- Wnn/uum/wnnrc_op.c.orig	2013-09-02 11:01:40.000000000 +0000
+++ Wnn/uum/wnnrc_op.c
@@ -139,7 +139,6 @@ expand_expr (s)
   register char *p, *s1;
   int noerr, expandsuc;
   struct passwd *u;
-  extern struct passwd *getpwnam ();
 
   if (*s != '~' && *s != '@')
     {
