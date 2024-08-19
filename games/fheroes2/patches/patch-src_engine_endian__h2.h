$NetBSD: patch-src_engine_endian__h2.h,v 1.1 2024/08/19 22:09:32 nia Exp $

Portability.

--- src/engine/endian_h2.h.orig	2024-08-19 20:58:53.651518405 +0000
+++ src/engine/endian_h2.h
@@ -83,7 +83,7 @@
 #define le32toh( x ) ( x )
 
 #else
-#error "Unsupported platform"
+#include <endian.h> // IWYU pragma: export
 #endif
 
 #define IS_BIGENDIAN ( BYTE_ORDER == BIG_ENDIAN )
