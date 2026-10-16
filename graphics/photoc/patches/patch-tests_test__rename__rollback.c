$NetBSD: patch-tests_test__rename__rollback.c,v 1.1 2026/10/16 00:43:51 ktnb Exp $

Add NetBSD support

--- tests/test_rename_rollback.c.orig	2026-10-16 00:19:55.601744028 +0000
+++ tests/test_rename_rollback.c
@@ -1,5 +1,7 @@
 #if defined(__APPLE__)
 #define _DARWIN_C_SOURCE
+#elif defined(__NetBSD__)
+#define _NETBSD_SOURCE
 #endif
 #define _POSIX_C_SOURCE 200809L
 
