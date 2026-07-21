$NetBSD: patch-tests_shared__mmap.c,v 1.1 2026/07/21 21:17:40 rjs Exp $

Add int return type for main().

--- ../tests/shared_mmap.c.orig	2026-07-21 19:55:39.226204434 +0000
+++ ../tests/shared_mmap.c
@@ -15,6 +15,7 @@
 #define MAP_FILE 0
 #endif
 
+int
 main()
 {
 	int *buf;
