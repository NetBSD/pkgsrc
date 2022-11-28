$NetBSD: patch-config.h,v 1.2 2022/11/28 04:26:08 mrg Exp $

* Use /dev/smbios instead of /dev/mem on NetBSD if available.

--- config.h.orig	2022-06-27 08:06:32.000000000 -0700
+++ config.h	2022-11-27 14:30:20.312604489 -0800
@@ -8,6 +8,8 @@
 /* Default memory device file */
 #if defined(__BEOS__) || defined(__HAIKU__)
 #define DEFAULT_MEM_DEV "/dev/misc/mem"
+#elif defined(__NetBSD__) 
+#define USE_DEFAULT_MEM_DEV_FUNC 1
 #else
 #ifdef __sun
 #define DEFAULT_MEM_DEV "/dev/xsvc"
@@ -16,6 +18,11 @@
 #endif
 #endif
 
+#ifdef USE_DEFAULT_MEM_DEV_FUNC
+const char *default_mem_dev(void);
+#define DEFAULT_MEM_DEV default_mem_dev()
+#endif
+
 /* Use mmap or not */
 #ifndef __BEOS__
 #define USE_MMAP
