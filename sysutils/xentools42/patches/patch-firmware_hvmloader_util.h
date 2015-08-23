$NetBSD: patch-firmware_hvmloader_util.h,v 1.2 2015/08/23 16:17:12 spz Exp $

--- firmware/hvmloader/util.h.orig	2014-09-02 06:22:57.000000000 +0000
+++ firmware/hvmloader/util.h
@@ -3,6 +3,7 @@
 
 #include <stdarg.h>
 #include <stdint.h>
+#include <stddef.h>
 #include <xen/xen.h>
 #include <xen/hvm/hvm_info_table.h>
 
@@ -172,7 +173,6 @@ int printf(const char *fmt, ...) __attri
 int vprintf(const char *fmt, va_list ap);
 
 /* Buffer output */
-typedef unsigned long size_t;
 int snprintf(char *buf, size_t size, const char *fmt, ...) __attribute__ ((format (printf, 3, 4)));
 
 /* Populate specified memory hole with RAM. */
