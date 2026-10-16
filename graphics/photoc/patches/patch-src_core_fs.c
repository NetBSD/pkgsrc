$NetBSD: patch-src_core_fs.c,v 1.1 2026/10/16 00:43:51 ktnb Exp $

Add NetBSD support

--- src/core/fs.c.orig	2026-10-10 15:49:33.000000000 +0000
+++ src/core/fs.c
@@ -2,6 +2,8 @@
 #define _GNU_SOURCE
 #elif defined(__APPLE__)
 #define _DARWIN_C_SOURCE
+#elif defined(__NetBSD__)
+#define _NETBSD_SOURCE
 #endif
 #define _POSIX_C_SOURCE 200809L
 
@@ -14,6 +16,8 @@
 #include <linux/fs.h>
 #elif defined(__APPLE__)
 #include <sys/stdio.h>
+#elif defined(__NetBSD__)
+#include <sys/dirent.h>
 #endif
 #include <stdio.h>
 #include <stdint.h>
