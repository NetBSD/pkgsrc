$NetBSD: patch-src_lib_eina__str.c,v 1.1 2025/12/20 12:17:12 nia Exp $

Fix build on systems with recent gcc versions and non-posix iconv.

--- src/lib/eina_str.c.orig	2025-12-20 11:54:21.107595074 +0000
+++ src/lib/eina_str.c
@@ -31,6 +31,14 @@
 #ifdef HAVE_ICONV
 # include <errno.h>
 # include <iconv.h>
+#if defined(__NetBSD__)
+#include <sys/param.h>
+#if __NetBSD_Prereq__(9,99,17)
+#define NETBSD_POSIX_ICONV 1
+#else
+#define NETBSD_POSIX_ICONV 0
+#endif /* __NetBSD_Prereq__ */
+#endif /* __NetBSD__ */
 #endif
 
 #include "eina_private.h"
@@ -479,7 +487,11 @@ eina_str_convert(const char *enc_from, const char *enc
         size_t count;
 
         tob = outb;
+#if (defined(__NetBSD__) && !NETBSD_POSIX_ICONV) || defined(__sun)
+        count = iconv(ic, (const char **)&inp, &inb, &outp, &outb);
+#else
         count = iconv(ic, &inp, &inb, &outp, &outb);
+#endif
         outlen += tob - outb;
         if (count == (size_t)(-1))
           {
