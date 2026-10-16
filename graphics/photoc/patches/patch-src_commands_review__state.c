$NetBSD: patch-src_commands_review__state.c,v 1.1 2026/10/16 00:43:50 ktnb Exp $

Add NetBSD support

--- src/commands/review_state.c.orig	2026-10-16 00:21:18.559709260 +0000
+++ src/commands/review_state.c
@@ -2,6 +2,8 @@
 #define _GNU_SOURCE
 #elif defined(__APPLE__)
 #define _DARWIN_C_SOURCE
+#elif defined(__NetBSD__)
+#define _NETBSD_SOURCE
 #endif
 #define _POSIX_C_SOURCE 200809L
 
@@ -14,6 +16,9 @@
 #include <fcntl.h>
 #include <stdint.h>
 #include <stdio.h>
+#if defined(__NetBSD__)
+#include <sys/param.h>
+#endif
 #include <stdlib.h>
 #include <string.h>
 #include <sys/stat.h>
