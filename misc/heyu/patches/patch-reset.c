$NetBSD: patch-reset.c,v 1.1 2026/03/19 14:55:21 nia Exp $

Modern GCC no longer likes implicit int. ANSIfy.

--- reset.c.orig	2026-03-19 14:44:36.909408043 +0000
+++ reset.c
@@ -22,8 +22,7 @@ extern int tty;
 
 /* ARGSUSED */
 
-void c_reset(argc, argv)
-char *argv[];
+void c_reset(int argc, char *argv[])
 {
     int hletter;
     int oldcode;
