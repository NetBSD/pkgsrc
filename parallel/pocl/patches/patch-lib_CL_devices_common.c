$NetBSD: patch-lib_CL_devices_common.c,v 1.1 2021/06/10 09:57:40 nia Exp $

Test for dlfcn.h instead of libdl.

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
