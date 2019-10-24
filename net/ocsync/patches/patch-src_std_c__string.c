$NetBSD: patch-src_std_c__string.c,v 1.2 2019/10/24 22:28:46 kamil Exp $

* For NetBSD iconv(3), this should be fixed for GNU iconv and NetBSD case.

--- src/std/c_string.c.orig	2013-10-18 13:11:09.000000000 +0000
+++ src/std/c_string.c
@@ -40,6 +40,15 @@
 #include <windows.h>
 #endif
 
+#if defined(__NetBSD__)
+#include <sys/param.h>
+#if __NetBSD_Prereq__(9,99,17)
+#define NETBSD_POSIX_ICONV 1
+#else
+#define NETBSD_POSIX_ICONV 0
+#endif
+#endif
+
 #ifdef WITH_ICONV
 #include <iconv.h>
 
@@ -83,7 +92,11 @@ enum iconv_direction { iconv_from_native
 
 static char *c_iconv(const char* str, enum iconv_direction dir)
 {
+#if defined(__NetBSD__) && !NETBSD_POSIX_ICONV
+  const char *in = (char*)str;
+#else
   char *in = (char*)str;
+#endif
   size_t size;
   size_t outsize;
   char *out;
