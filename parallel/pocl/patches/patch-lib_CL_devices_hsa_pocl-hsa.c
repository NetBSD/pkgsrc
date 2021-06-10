$NetBSD: patch-lib_CL_devices_hsa_pocl-hsa.c,v 1.1 2021/06/10 09:57:40 nia Exp $

Detect dlfcn.h (portable) instead of libdl (not portable).

--- lib/CL/devices/hsa/pocl-hsa.c.orig	2021-05-19 08:12:19.000000000 +0000
+++ lib/CL/devices/hsa/pocl-hsa.c
@@ -73,8 +73,8 @@
 
 #endif
 
-#ifndef HAVE_LIBDL
-#error HSA driver requires DL library
+#ifndef HAVE_DLFCN_H
+#error HSA driver requires dlopen
 #endif
 
 #include "pocl-hsa.h"
