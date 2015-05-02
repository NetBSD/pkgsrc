$NetBSD: patch-src_third__party_s2_base_port.h,v 1.1 2015/05/02 08:10:33 ryoon Exp $

* Add NetBSD support.

--- src/third_party/s2/base/port.h.orig	2015-04-08 20:28:08.000000000 +0000
+++ src/third_party/s2/base/port.h
@@ -102,7 +102,7 @@ typedef uint16_t u_int16_t;
 
 #endif
 
-#if defined __sunos__ || defined __freebsd__ || defined __openbsd__
+#if defined __sunos__ || defined __freebsd__ || defined __openbsd__ || defined __netbsd__
 #ifdef _LITTLE_ENDIAN
 #define IS_LITTLE_ENDIAN
 #elif defined _BIG_ENDIAN
@@ -139,6 +139,11 @@ typedef uint16_t u_int16_t;
 #define bswap_16(x) swap16(x)
 #define bswap_32(x) swap32(x)
 #define bswap_64(x) swap64(x)
+#elif defined __netbsd__
+#include <machine/bswap.h>
+#define bswap_16(x) bswap16(x)
+#define bswap_32(x) bswap32(x)
+#define bswap_64(x) bswap64(x)
 #else
 #include <byteswap.h>
 #endif
