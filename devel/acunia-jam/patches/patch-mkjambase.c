$NetBSD: patch-mkjambase.c,v 1.1 2026/03/17 14:24:09 nia Exp $

Modern GCC no longer likes implicit int.

--- mkjambase.c.orig	2026-03-17 14:03:13.558470544 +0000
+++ mkjambase.c
@@ -23,6 +23,7 @@
 # include <stdio.h>
 # include <string.h>
 
+int
 main( int argc, char **argv, char **envp )
 {
 	char buf[ 1024 ];
