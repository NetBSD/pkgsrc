$NetBSD: patch-lib_CL_devices_proxy_pocl__proxy.c,v 1.1 2024/08/03 09:54:16 nia Exp $

alloca.h is not portable.

--- lib/CL/devices/proxy/pocl_proxy.c.orig	2024-08-03 09:51:54.171097319 +0000
+++ lib/CL/devices/proxy/pocl_proxy.c
@@ -31,7 +31,9 @@
 #include "devices.h"
 
 #include <assert.h>
+#if defined(__linux) || defined(__sun)
 #include <alloca.h>
+#endif
 #include <stdlib.h>
 #include <string.h>
 #include <unistd.h>
