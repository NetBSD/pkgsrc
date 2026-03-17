$NetBSD: patch-jam.c,v 1.1 2026/03/17 14:24:09 nia Exp $

Modern GCC no longer likes implicit int.

--- jam.c.orig	2026-03-17 14:03:04.967308616 +0000
+++ jam.c
@@ -151,6 +151,7 @@ extern char **environ;
 # endif
 # endif
 
+int
 main( int argc, char **argv, char **arg_environ )
 {
 	int		n;
