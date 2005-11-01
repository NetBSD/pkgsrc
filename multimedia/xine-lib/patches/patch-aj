$NetBSD: patch-aj,v 1.9 2005/11/01 06:15:33 reed Exp $

--- src/input/libdvdnav/bswap.h.orig	2005-10-31 21:49:47.000000000 -0800
+++ src/input/libdvdnav/bswap.h	2005-10-31 21:53:43.000000000 -0800
@@ -53,7 +53,7 @@
 #define B2N_32(x) x = swap32(x)
 #define B2N_64(x) x = swap64(x)
 
-#elif defined(__FreeBSD__) && __FreeBSD_version >= 470000
+#elif defined(__DragonFly__) || (defined(__FreeBSD__) && __FreeBSD_version >= 470000)
 #include <sys/endian.h>
 #define B2N_16(x) x = be16toh(x)
 #define B2N_32(x) x = be32toh(x)
