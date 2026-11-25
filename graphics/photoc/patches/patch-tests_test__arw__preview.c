$NetBSD: patch-tests_test__arw__preview.c,v 1.1 2026/11/25 15:56:43 ktnb Exp $

symlink(3) requires _NETBSD_SOURCE to be set

--- tests/test_arw_preview.c.orig	2026-11-25 15:48:55.916573653 +0000
+++ tests/test_arw_preview.c
@@ -1,5 +1,7 @@
 #if defined(__APPLE__)
 #define _DARWIN_C_SOURCE
+#elif defined(__NetBSD__)
+#define _NETBSD_SOURCE
 #endif
 #define _POSIX_C_SOURCE 200809L
 
