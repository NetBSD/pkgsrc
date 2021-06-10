$NetBSD: patch-lib_CL_devices_common.c,v 1.2 2021/06/10 12:26:26 nia Exp $

Fix detection of dlopen
https://github.com/pocl/pocl/pull/950

--- lib/CL/devices/common.c.orig	2021-05-19 08:12:19.000000000 +0000
+++ lib/CL/devices/common.c
@@ -61,7 +61,7 @@
 #include <unistd.h>
 #endif
 
-#ifdef HAVE_LIBDL
+#ifdef HAVE_DLFCN_H
 #if defined(__APPLE__)
 #define _DARWIN_C_SOURCE
 #endif
