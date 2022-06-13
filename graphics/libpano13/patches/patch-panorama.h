$NetBSD: patch-panorama.h,v 1.1 2022/06/13 07:18:09 adam Exp $

Detect endianness on Darwin.

--- panorama.h.orig	2022-05-30 07:37:25.000000000 +0000
+++ panorama.h
@@ -52,6 +52,11 @@
 #if defined(_BYTE_ORDER) && (_BYTE_ORDER == _BIG_ENDIAN)
 #define PT_BIGENDIAN 1
 #endif
+#elif defined(__APPLE__)
+#include <machine/endian.h>
+#if defined(BYTE_ORDER) && (BYTE_ORDER == BIG_ENDIAN)
+#define PT_BIGENDIAN 1
+#endif
 #else
 #include <endian.h>
 #endif
