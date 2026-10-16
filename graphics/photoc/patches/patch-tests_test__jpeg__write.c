$NetBSD: patch-tests_test__jpeg__write.c,v 1.1 2026/10/16 00:43:51 ktnb Exp $

Add NetBSD support

--- tests/test_jpeg_write.c.orig	2026-10-16 00:27:10.033678241 +0000
+++ tests/test_jpeg_write.c
@@ -1,5 +1,7 @@
 #if defined(__APPLE__)
 #define _DARWIN_C_SOURCE
+#elif defined(__NetBSD__)
+#define _NETBSD_SOURCE
 #endif
 #define _POSIX_C_SOURCE 200809L
 
