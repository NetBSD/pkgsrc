$NetBSD: patch-Wnn_uum_termcap.c,v 1.3 2026/07/10 23:32:38 tsutsui Exp $

- Remove unnecessary old style declaration for standard C function

--- Wnn/uum/termcap.c.orig	2006-03-04 19:01:46.000000000 +0000
+++ Wnn/uum/termcap.c
@@ -116,7 +116,7 @@ getTermData ()
   char *pter;
   char *sr_set ();
   char *j;
-  extern char *getenv (), *get_kbd_env ();
+  extern char *get_kbd_env ();
 
 
 #ifdef DCUREOR
