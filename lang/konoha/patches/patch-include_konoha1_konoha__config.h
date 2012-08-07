$NetBSD: patch-include_konoha1_konoha__config.h,v 1.1 2012/08/07 16:06:06 ryoon Exp $

* Add NetBSD support

--- include/konoha1/konoha_config.h.orig	2012-03-07 06:52:14.000000000 +0000
+++ include/konoha1/konoha_config.h
@@ -288,6 +288,17 @@ typedef struct knh_sysinfo_t {
 #define     K_USING_SQLITE3     1
 #endif
 
+#if defined(__NetBSD__) /* NetBSD */
+#define		K_USING_PTHREAD
+#define		K_USING_STDC_    1
+#define 	K_USING_POSIX_      1
+#define 	K_USING_BSD_        1
+#define     K_USING_BSDSYSCTL_  1
+#define     K_USING_SYSLOG      1
+#define     K_USING_ICONV       1
+#define     K_USING_SQLITE3     1
+#endif
+
 #if defined(__MINGW32__)  /* mingw */
 #define		K_USING_STDC_       1
 #define		K_USING_SETJMP_     1
