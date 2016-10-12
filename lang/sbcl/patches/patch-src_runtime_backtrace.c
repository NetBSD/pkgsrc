$NetBSD: patch-src_runtime_backtrace.c,v 1.1 2016/10/12 11:35:48 asau Exp $

--- src/runtime/backtrace.c.orig	2016-09-30 16:41:12.000000000 +0000
+++ src/runtime/backtrace.c
@@ -16,6 +16,10 @@
 /* needed if we want dladdr() and Dl_Info from glibc's dlfcn.h */
 #define _GNU_SOURCE
 
+#if defined(__NetBSD__)
+#define _KERNTYPES
+#endif
+
 #include <stdio.h>
 #include <signal.h>
 #include "sbcl.h"
