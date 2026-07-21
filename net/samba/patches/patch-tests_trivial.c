$NetBSD: patch-tests_trivial.c,v 1.1 2026/07/21 21:17:40 rjs Exp $

Add int return type for main().

--- ../tests/trivial.c.orig	2015-02-22 14:11:32.000000000 +0000
+++ ../tests/trivial.c
@@ -1,6 +1,7 @@ void exit(int);
 
 void exit(int);
 
+int
 main()
 {
 	exit(0);
