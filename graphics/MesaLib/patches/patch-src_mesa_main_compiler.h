$NetBSD: patch-src_mesa_main_compiler.h,v 1.1 2013/05/16 05:22:02 richard Exp $

--- src/mesa/main/compiler.h.orig	2011-11-23 01:09:52.000000000 +0000
+++ src/mesa/main/compiler.h
@@ -248,7 +248,11 @@ extern "C" {
  * Try to use a runtime test instead.
  * For now, only used by some DRI hardware drivers for color/texel packing.
  */
-#if defined(BYTE_ORDER) && defined(BIG_ENDIAN) && BYTE_ORDER == BIG_ENDIAN
+#ifdef __sun
+#include <sys/isa_defs.h>
+#endif
+
+#if (defined(BYTE_ORDER) && defined(BIG_ENDIAN) && BYTE_ORDER == BIG_ENDIAN) || defined(_BIG_ENDIAN)
 #if defined(__linux__)
 #include <byteswap.h>
 #define CPU_TO_LE32( x )	bswap_32( x )
@@ -263,6 +267,9 @@ static INLINE GLuint CPU_TO_LE32(GLuint
            ((x & 0x00ff0000) >>  8) |
            ((x & 0xff000000) >> 24));
 }
+#elif defined(__sun)
+#include <sys/byteorder.h>
+#define CPU_TO_LE32( x )        BSWAP_32( x )
 #else /*__linux__ */
 #include <sys/endian.h>
 #define CPU_TO_LE32( x )	bswap32( x )
