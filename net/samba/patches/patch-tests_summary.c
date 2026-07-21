$NetBSD: patch-tests_summary.c,v 1.1 2026/07/21 21:17:40 rjs Exp $

Add int return type for main().

--- ../tests/summary.c.orig	2015-02-22 14:11:32.000000000 +0000
+++ ../tests/summary.c
@@ -2,6 +2,7 @@ void exit(int);
 
 void exit(int);
 
+int
 main()
 {
     exit (0);
