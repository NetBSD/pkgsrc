$NetBSD: patch-src_city.cc,v 1.3 2024/04/22 10:21:53 he Exp $

Add support for SunOS.
Fix support for NetBSD, submitted as
  https://github.com/google/cityhash/pull/40

--- src/city.cc.orig	2013-06-17 19:45:57.000000000 +0000
+++ src/city.cc
@@ -64,10 +64,18 @@ static uint32 UNALIGNED_LOAD32(const cha
 
 #include <sys/types.h>
 #include <machine/bswap.h>
-#if defined(__BSWAP_RENAME) && !defined(__bswap_32)
 #define bswap_32(x) bswap32(x)
 #define bswap_64(x) bswap64(x)
-#endif
+
+#elif defined(__sun)
+#include <sys/byteorder.h>
+#define bswap_32(x) htonl(x)
+#define bswap_64(x) htonll(x)
+
+#elif defined(__FreeBSD__)
+#include <sys/endian.h>
+#define bswap_32(x) bswap32(x)
+#define bswap_64(x) bswap64(x)
 
 #else
 
