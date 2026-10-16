$NetBSD: patch-tests_test__hash.c,v 1.1 2026/10/16 00:43:51 ktnb Exp $

Add NetBSD support

--- tests/test_hash.c.orig	2026-10-16 00:22:59.526939833 +0000
+++ tests/test_hash.c
@@ -1,5 +1,7 @@
 #if defined(__APPLE__)
 #define _DARWIN_C_SOURCE
+#elif defined(__NetBSD__)
+#define _NETBSD_SOURCE
 #endif
 #define _POSIX_C_SOURCE 200809L
 
