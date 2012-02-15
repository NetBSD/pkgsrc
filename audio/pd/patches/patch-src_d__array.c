$NetBSD: patch-src_d__array.c,v 1.3 2012/02/15 22:36:39 hans Exp $

Detect endianness on NetBSD.
https://sourceforge.net/tracker/?func=detail&aid=3411732&group_id=55736&atid=478072

--- src/d_array.c.orig	2010-07-28 20:55:17.000000000 +0000
+++ src/d_array.c
@@ -502,7 +502,7 @@ static void tabread4_tilde_setup(void)
 #include <sys/endian.h>
 #endif
 
-#if defined(__FreeBSD__) || defined(__APPLE__) || defined(__FreeBSD_kernel__)
+#if defined(__FreeBSD__) || defined(__APPLE__) || defined(__FreeBSD_kernel__) || defined(__NetBSD__)
 #include <machine/endian.h>
 #endif
 
@@ -510,6 +510,17 @@ static void tabread4_tilde_setup(void)
 #include <endian.h>
 #endif
 
+#if defined(__sun)
+#include <sys/byteorder.h>
+#define LITTLE_ENDIAN 1234
+#define BIG_ENDIAN 4321
+# ifdef _LITTLE_ENDIAN
+#  define BYTE_ORDER LITTLE_ENDIAN
+# else
+#  define BYTE_ORDER BIG_ENDIAN
+# endif
+#endif
+
 #ifdef __MINGW32__
 #include <sys/param.h>
 #endif
