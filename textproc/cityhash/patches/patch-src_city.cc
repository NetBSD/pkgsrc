$NetBSD: patch-src_city.cc,v 1.2 2014/01/19 02:54:56 rodent Exp $

Add support for SunOS.

--- src/city.cc.orig	2013-06-17 19:45:57.000000000 +0000
+++ src/city.cc
@@ -69,6 +69,16 @@ static uint32 UNALIGNED_LOAD32(const cha
 #define bswap_64(x) bswap64(x)
 #endif
 
+#elif defined(__sun)
+#include <sys/byteorder.h>
+#define bswap_32(x) htonl(x)
+#define bswap_64(x) htonll(x)
+
+#elif defined(__FreeBSD__)
+#include <sys/endian.h>
+#define bswap_32(x) bswap32(x)
+#define bswap_64(x) bswap64(x)
+
 #else
 
 #include <byteswap.h>
