$NetBSD: patch-src_runtime_gc-common.c,v 1.2 2016/12/05 20:03:29 asau Exp $

--- src/runtime/gc-common.c.orig	2016-11-29 21:07:36.000000000 +0000
+++ src/runtime/gc-common.c
@@ -27,6 +27,10 @@
 
 #define _GNU_SOURCE /* for ffsl(3) from string.h */
 
+#if defined(__NetBSD__)
+#define _KERNTYPES
+#endif
+
 #include <stdio.h>
 #include <signal.h>
 #include <string.h>
