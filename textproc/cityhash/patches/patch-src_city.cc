$NetBSD: patch-src_city.cc,v 1.1 2013/07/08 00:56:45 rodent Exp $

Add support for SunOS.

--- src/city.cc.orig	2013-06-17 19:45:57.000000000 +0000
+++ src/city.cc
@@ -69,6 +69,11 @@ static uint32 UNALIGNED_LOAD32(const cha
 #define bswap_64(x) bswap64(x)
 #endif
 
+#elif defined(__sun)
+#include <sys/byteorder.h>
+#define bswap_32(x) htonl(x)
+#define bswap_64(x) htonll(x)
+
 #else
 
 #include <byteswap.h>
