$NetBSD: patch-lib_CL_devices_basic_basic.c,v 1.2 2021/06/10 12:26:26 nia Exp $

Fix detection of dlopen
https://github.com/pocl/pocl/pull/950

--- lib/CL/devices/basic/basic.c.orig	2021-05-19 08:12:19.000000000 +0000
+++ lib/CL/devices/basic/basic.c
@@ -50,8 +50,8 @@
 #include "pocl_llvm.h"
 #endif
 
-#ifndef HAVE_LIBDL
-#error Basic driver requires DL library
+#ifndef HAVE_DLFCN_H
+#error Basic driver requires dlopen
 #endif
 
 struct data {
