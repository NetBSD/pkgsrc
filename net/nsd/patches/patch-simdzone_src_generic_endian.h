$NetBSD: patch-simdzone_src_generic_endian.h,v 1.1 2024/09/21 16:09:29 he Exp $

WHen borrowing code from NetBSD, make it build
*on* NetBSD, and don't cause redefinition issues...

--- simdzone/src/generic/endian.h.orig	2024-09-21 15:58:37.017604378 +0000
+++ simdzone/src/generic/endian.h
@@ -87,6 +87,11 @@
 #elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__DragonFly__)
 #include <sys/endian.h>
 #endif
+#if defined(__NetBSD__)
+/* Bring bswap{16,32,64} into scope: */
+#include <sys/types.h>
+#include <machine/bswap.h>
+#endif
 
 #if !defined(LITTLE_ENDIAN)
 # if defined(__ORDER_LITTLE_ENDIAN__)
@@ -122,6 +127,7 @@
 # endif
 #endif
 
+#if !defined(__NetBSD__)
 static really_inline uint16_t bswap16(uint16_t x)
 {
   // Copied from src/common/lib/libc/gen/bswap16.c in NetBSD
@@ -155,6 +161,7 @@ static really_inline uint64_t bswap64(ui
          ( (x >> 40) & 0x000000000000ff00ull ) |
          ( (x >> 56) & 0x00000000000000ffull );
 }
+#endif /* ! __NetBSD__ */
 
 # if BYTE_ORDER == LITTLE_ENDIAN
 #   define htobe(bits, x) bswap ## bits((x))
