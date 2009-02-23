$NetBSD: patch-aa,v 1.10 2009/02/23 11:09:27 wiz Exp $

--- src/bswap.h.orig	2008-09-06 21:55:51.000000000 +0000
+++ src/bswap.h
@@ -65,6 +65,12 @@
 #define B2N_32(x) x = be32toh(x)
 #define B2N_64(x) x = be64toh(x)
 
+#elif defined(__DragonFly__)
+#include <sys/endian.h>
+#define B2N_16(x) x = bswap16(x)
+#define B2N_32(x) x = bswap32(x)
+#define B2N_64(x) x = bswap64(x)
+
 /* This is a slow but portable implementation, it has multiple evaluation
  * problems so beware.
  * Old FreeBSD's and Solaris don't have <byteswap.h> or any other such
