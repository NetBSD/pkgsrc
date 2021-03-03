$NetBSD: patch-mono_eglib_giconv.c,v 1.1 2021/03/03 12:05:41 nia Exp $

Support POSIX iconv(3) on modern NetBSD.

--- mono/eglib/giconv.c.orig	2020-04-30 07:46:10.000000000 +0000
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
@@ -197,7 +205,7 @@ g_iconv (GIConv cd, gchar **inbytes, gsi
 			outleftptr = NULL;
 		}
 // AIX needs this for C++ and GNU iconv
-#if defined(__NetBSD__) || defined(_AIX)
+#if (defined(__NetBSD__) && !NETBSD_POSIX_ICONV) || defined(_AIX)
 		return iconv (cd->cd, (const gchar **)inbytes, inleftptr, outbytes, outleftptr);
 #else
 		return iconv (cd->cd, inbytes, inleftptr, outbytes, outleftptr);
