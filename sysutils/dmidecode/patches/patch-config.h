$NetBSD: patch-config.h,v 1.1 2021/07/24 13:23:52 jmcneill Exp $

* Use /dev/smbios instead of /dev/mem on NetBSD aarch64

--- config.h.orig	2020-10-14 12:51:11.000000000 +0000
+++ config.h
@@ -8,6 +8,8 @@
 /* Default memory device file */
 #if defined(__BEOS__) || defined(__HAIKU__)
 #define DEFAULT_MEM_DEV "/dev/misc/mem"
+#elif defined(__NetBSD__) && defined(__aarch64__)
+#define DEFAULT_MEM_DEV "/dev/smbios"
 #else
 #ifdef __sun
 #define DEFAULT_MEM_DEV "/dev/xsvc"
