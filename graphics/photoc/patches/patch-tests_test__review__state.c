$NetBSD: patch-tests_test__review__state.c,v 1.1 2026/10/16 00:43:51 ktnb Exp $

Add NetBSD support

--- tests/test_review_state.c.orig	2026-10-16 00:25:17.075881815 +0000
+++ tests/test_review_state.c
@@ -2,6 +2,8 @@
 #define _GNU_SOURCE
 #elif defined(__APPLE__)
 #define _DARWIN_C_SOURCE
+#elif defined(__NetBSD__)
+#define _NETBSD_SOURCE
 #endif
 #define _POSIX_C_SOURCE 200809L
 
