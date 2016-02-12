$NetBSD: patch-src_third__party_s2_base_port.h,v 1.2 2016/02/12 03:37:24 ryoon Exp $

* Add NetBSD support.

--- src/third_party/s2/base/port.h.orig	2016-01-05 18:31:44.000000000 +0000
+++ src/third_party/s2/base/port.h
@@ -102,7 +102,7 @@ typedef uint16_t u_int16_t;
 
 #endif
 
-#if defined __sun || defined __FreeBSD__ || defined __OpenBSD__
+#if defined __sun || defined __FreeBSD__ || defined __OpenBSD__ || defined __DragonFly__ || defined __NetBSD__
 #ifdef _LITTLE_ENDIAN
 #define IS_LITTLE_ENDIAN
 #elif defined _BIG_ENDIAN
@@ -139,6 +139,11 @@ typedef uint16_t u_int16_t;
 #define bswap_16(x) swap16(x)
 #define bswap_32(x) swap32(x)
 #define bswap_64(x) swap64(x)
+#elif defined __NetBSD__
+#include <machine/bswap.h>
+#define bswap_16(x) bswap16(x)
+#define bswap_32(x) bswap32(x)
+#define bswap_64(x) bswap64(x)
 #else
 #include <byteswap.h>
 #endif
