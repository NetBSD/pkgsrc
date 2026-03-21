$NetBSD: patch-main.c,v 1.1 2026/03/21 09:42:49 nia Exp $

Modern GCC no longer likes implicit int.

--- main.c.orig	2026-03-21 09:18:34.229343745 +0000
+++ main.c
@@ -392,7 +392,7 @@ char* pid_file = 0; /* filename as asked
 
 
 /* callit before exiting; if show_status==1, mem status is displayed */
-void cleanup(show_status)
+void cleanup(int show_status)
 {
 	/*clean-up*/
 	destroy_modules();
