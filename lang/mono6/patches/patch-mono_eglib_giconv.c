$NetBSD: patch-mono_eglib_giconv.c,v 1.1 2020/02/12 13:43:31 kamil Exp $

Support POSIX iconv(3) on modern NetBSD.

--- mono/eglib/giconv.c.orig	2019-12-10 07:50:32.000000000 +0000
+++ mono/eglib/giconv.c
@@ -37,6 +37,14 @@
 #define FORCE_INLINE(RET_TYPE) inline RET_TYPE __attribute__((always_inline))
 #endif
 
+#if defined(__NetBSD__)
+#include <sys/param.h>
+#if __NetBSD_Prereq__(9,99,17)
+#define NETBSD_POSIX_ICONV 1
+#else
+#define NETBSD_POSIX_ICONV 0
+#endif
+#endif
 
 #define UNROLL_DECODE_UTF8 0
 #define UNROLL_ENCODE_UTF8 0
@@ -196,7 +204,7 @@ g_iconv (GIConv cd, gchar **inbytes, gsi
 		} else {
 			outleftptr = NULL;
 		}
-#if defined(__NetBSD__)
+#if defined(__NetBSD__) && !NETBSD_POSIX_ICONV
 		return iconv (cd->cd, (const gchar **)inbytes, inleftptr, outbytes, outleftptr);
 #else
 		return iconv (cd->cd, inbytes, inleftptr, outbytes, outleftptr);
