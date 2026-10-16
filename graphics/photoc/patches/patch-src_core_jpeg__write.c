$NetBSD: patch-src_core_jpeg__write.c,v 1.1 2026/10/16 00:43:51 ktnb Exp $

Add NetBSD support

--- src/core/jpeg_write.c.orig	2026-10-16 00:18:51.183798284 +0000
+++ src/core/jpeg_write.c
@@ -1,5 +1,7 @@
 #if defined(__APPLE__)
 #define _DARWIN_C_SOURCE
+#elif defined(__NetBSD__)
+#define _NETBSD_SOURCE
 #endif
 #define _POSIX_C_SOURCE 200809L
 
