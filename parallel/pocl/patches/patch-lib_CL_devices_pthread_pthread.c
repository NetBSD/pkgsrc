$NetBSD: patch-lib_CL_devices_pthread_pthread.c,v 1.2 2021/06/10 12:26:26 nia Exp $

Fix detection of dlopen
https://github.com/pocl/pocl/pull/950

--- lib/CL/devices/pthread/pthread.c.orig	2021-05-19 08:12:19.000000000 +0000
+++ lib/CL/devices/pthread/pthread.c
@@ -51,8 +51,8 @@
 #include "pocl_util.h"
 #include "pocl_mem_management.h"
 
-#ifndef HAVE_LIBDL
-#error Pthread driver requires DL library
+#ifndef HAVE_DLFCN_H
+#error Pthread driver requires dlopen
 #endif
 
 #ifdef OCS_AVAILABLE
