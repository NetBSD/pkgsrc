$NetBSD: patch-src_d__osc.c,v 1.4 2013/05/29 11:26:12 wiz Exp $

Detect endianness on NetBSD.
https://sourceforge.net/tracker/?func=detail&aid=3411732&group_id=55736&atid=478072

Detect endianness on OpenBSD.

Detect endianness on Solaris.

--- src/d_osc.c.orig	2010-07-28 20:55:17.000000000 +0000
+++ src/d_osc.c
@@ -11,11 +11,11 @@
 #define UNITBIT32 1572864.  /* 3*2^19; bit 32 has place value 1 */
 
 
-#ifdef IRIX
+#if defined(IRIX) || defined(__OpenBSD__)
 #include <sys/endian.h>
 #endif
 
-#if defined(__FreeBSD__) || defined(__APPLE__) || defined(__FreeBSD_kernel__)
+#if defined(__FreeBSD__) || defined(__APPLE__) || defined(__FreeBSD_kernel__) || defined(__NetBSD__)
 #include <machine/endian.h>
 #endif
 
@@ -23,6 +23,17 @@
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
