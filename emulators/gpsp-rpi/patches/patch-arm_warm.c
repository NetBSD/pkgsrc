$NetBSD: patch-arm_warm.c,v 1.1 2015/02/06 02:02:03 jmcneill Exp $

--- arm/warm.c.orig	2015-01-06 20:57:45.000000000 +0000
+++ arm/warm.c
@@ -42,15 +42,18 @@
 #define WARM_CODE
 #include "warm.h"
 
+#if defined(__linux__)
 /* provided by glibc */
 extern long init_module(void *, unsigned long, const char *);
 extern long delete_module(const char *, unsigned int);
+#endif
 
 static int warm_fd = -1;
 static int kernel_version;
 
 static void sys_cacheflush(void *start, void *end)
 {
+#if defined(__linux__)
 #ifdef __ARM_EABI__
 	/* EABI version */
 	int num = __ARM_NR_cacheflush;
@@ -68,12 +71,16 @@ static void sys_cacheflush(void *start, 
 		"swi  %2" : : "r" (start), "r" (end), "i" __ARM_NR_cacheflush
 			: "r0", "r1", "r2", "r3");
 #endif
+#else
+	__clear_cache(start, end);
+#endif
 }
 
 /* Those are here because system() occasionaly fails on Wiz
  * with errno 12 for some unknown reason */
 static int manual_insmod_26(const char *fname, const char *opts)
 {
+#if defined(__linux__)
 	unsigned long len, read_len;
 	int ret = -1;
 	void *buff;
@@ -104,11 +111,18 @@ fail1:
 fail0:
 	fclose(f);
 	return ret;
+#else
+	return -1;
+#endif
 }
 
 static int manual_rmmod(const char *name)
 {
+#if defined(__linux__)
 	return delete_module(name, O_NONBLOCK|O_EXCL);
+#else
+	return 0;
+#endif
 }
 
 int warm_init(void)
