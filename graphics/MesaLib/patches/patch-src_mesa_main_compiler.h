$NetBSD: patch-src_mesa_main_compiler.h,v 1.3 2013/06/16 04:16:59 obache Exp $

--- src/mesa/main/compiler.h.orig	2011-11-23 01:09:52.000000000 +0000
+++ src/mesa/main/compiler.h
@@ -248,7 +248,26 @@ extern "C" {
  * Try to use a runtime test instead.
  * For now, only used by some DRI hardware drivers for color/texel packing.
  */
-#if defined(BYTE_ORDER) && defined(BIG_ENDIAN) && BYTE_ORDER == BIG_ENDIAN
+#ifdef __sun
+#include <sys/isa_defs.h>
+#elif defined(__OpenBSD__) || defined(__NetBSD__)
+#include <machine/endian.h>
+#elif defined(__FreeBSD__) || defined(__DragonFly__)
+#include <sys/endian.h>
+#endif
+
+#if defined(BYTE_ORDER) && defined(BIG_ENDIAN)
+#  if BYTE_ORDER == BIG_ENDIAN
+#define MESA_BIG_ENDIAN 1
+#  endif
+#elif defined(_BYTE_ORDER) && defined(_BIG_ENDIAN)
+#  if _BYTE_ORDER == _BIG_ENDIAN
+#define MESA_BIG_ENDIAN 1
+#  endif
+#elif defined(__sun) && defined(_BIG_ENDIAN)
+#define MESA_BIG_ENDIAN 1
+#endif
+#if MESA_BIG_ENDIAN == 1
 #if defined(__linux__)
 #include <byteswap.h>
 #define CPU_TO_LE32( x )	bswap_32( x )
@@ -263,11 +282,13 @@ static INLINE GLuint CPU_TO_LE32(GLuint 
            ((x & 0x00ff0000) >>  8) |
            ((x & 0xff000000) >> 24));
 }
+#elif defined(__sun)
+#include <sys/byteorder.h>
+#define CPU_TO_LE32( x )        BSWAP_32( x )
 #else /*__linux__ */
 #include <sys/endian.h>
 #define CPU_TO_LE32( x )	bswap32( x )
 #endif /*__linux__*/
-#define MESA_BIG_ENDIAN 1
 #else
 #define CPU_TO_LE32( x )	( x )
 #define MESA_LITTLE_ENDIAN 1
