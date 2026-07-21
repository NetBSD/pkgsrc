$NetBSD: patch-tests_ftruncate.c,v 1.1 2026/07/21 21:17:40 rjs Exp $

Add int return type for main().

--- ../tests/ftruncate.c.orig	2026-07-21 20:42:31.964579367 +0000
+++ ../tests/ftruncate.c
@@ -7,10 +7,12 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
+#include <stdlib.h>
 
 #define DATA "conftest.trunc"
 #define LEN 7663
 
+int
 main()
 {
 	int *buf;
