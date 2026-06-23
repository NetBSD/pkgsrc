$NetBSD: patch-lib_device.c,v 1.1 2026/06/23 12:40:05 wiz Exp $

Add header for opendisk().

--- lib/device.c.orig	2026-06-23 12:38:49.327131604 +0000
+++ lib/device.c
@@ -36,6 +36,10 @@
 #include <limits.h>
 #include <stdarg.h>
 
+#ifdef __NetBSD__
+#include <util.h>
+#endif
+
 #ifdef __linux__
 # if !defined(__GLIBC__) || \
         ((__GLIBC__ < 2) || ((__GLIBC__ == 2) && (__GLIBC_MINOR__ < 1)))
