$NetBSD: patch-src_intel_isl_isl__tiled__memcpy.c,v 1.1 2019/08/22 17:24:01 nia Exp $

NetBSD has bswap32 in libc.

--- src/intel/isl/isl_tiled_memcpy.c.orig	2019-08-07 16:39:17.000000000 +0000
+++ src/intel/isl/isl_tiled_memcpy.c
@@ -64,6 +64,7 @@ ror(uint32_t n, uint32_t d)
    return (n >> d) | (n << (32 - d));
 }
 
+#ifndef __NetBSD__
 static inline uint32_t
 bswap32(uint32_t n)
 {
@@ -76,6 +77,7 @@ bswap32(uint32_t n)
           (n << 24);
 #endif
 }
+#endif
 
 /**
  * Copy RGBA to BGRA - swap R and B.
