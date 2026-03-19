$NetBSD: patch-info.c,v 1.1 2026/03/19 14:55:21 nia Exp $

Modern GCC no longer likes implicit int. ANSIfy.

--- info.c.orig	2026-03-19 14:43:30.550877756 +0000
+++ info.c
@@ -35,4 +35,3 @@ extern char *wdays[];
 
-int c_info(argc, argv)
-char *argv[];
+int c_info(int argc, char *argv[])
 {
