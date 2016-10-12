$NetBSD: patch-src_runtime_os-common.c,v 1.1 2016/10/12 11:35:48 asau Exp $

--- src/runtime/os-common.c.orig	2016-09-30 16:41:12.000000000 +0000
+++ src/runtime/os-common.c
@@ -9,6 +9,11 @@
  * files for more information.
  */
 # define _GNU_SOURCE /* needed for RTLD_DEFAULT from dlfcn.h */
+
+#if defined(__NetBSD__)
+#define _KERNTYPES
+#endif
+
 #include <stdio.h>
 #include <errno.h>
 #include <string.h>
