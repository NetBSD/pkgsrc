$NetBSD: patch-src_liboutils_sha2.c,v 1.1 2022/10/08 11:30:27 bsiegert Exp $

Portability fix for SunOS.

--- src/liboutils/sha2.c.orig	2021-10-14 15:34:52.000000000 +0000
+++ src/liboutils/sha2.c
@@ -58,6 +58,27 @@
 #endif
 #endif
 
+/*
+ * Must define BYTE_ORDER on SunOS
+ * since it lacks endian.h
+ *
+ */
+ 
+#if defined(__sun)
+#include <sys/byteorder.h>
+#define bswap_16(x) BSWAP_16(x)
+#define bswap_32(x) BSWAP_32(x)
+#define bswap_64(x) BSWAP_64(x)
+#define LITTLE_ENDIAN 1234
+#define BIG_ENDIAN 4321
+#ifdef LITTLE_ENDIAN
+#define BYTE_ORDER LITTLE_ENDIAN
+#else
+#define BYTE_ORDER BIG_ENDIAN
+#endif
+#endif
+
+
 /*** SHA-224/256/384/512 Machine Architecture Definitions *****************/
 /*
  * BYTE_ORDER NOTE:
