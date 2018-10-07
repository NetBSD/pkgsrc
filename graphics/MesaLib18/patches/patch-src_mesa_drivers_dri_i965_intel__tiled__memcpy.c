$NetBSD: patch-src_mesa_drivers_dri_i965_intel__tiled__memcpy.c,v 1.1 2018/10/07 23:49:31 ryoon Exp $

From wip/MesaLib 13.0.1.

--- src/mesa/drivers/dri/i965/intel_tiled_memcpy.c.orig	2016-11-10 22:05:17.000000000 +0000
+++ src/mesa/drivers/dri/i965/intel_tiled_memcpy.c
@@ -64,6 +64,7 @@ ror(uint32_t n, uint32_t d)
    return (n >> d) | (n << (32 - d));
 }
 
+#if !defined(__NetBSD__)
 static inline uint32_t
 bswap32(uint32_t n)
 {
@@ -76,6 +77,7 @@ bswap32(uint32_t n)
           (n << 24);
 #endif
 }
+#endif /* NetBSD */
 
 /**
  * Copy RGBA to BGRA - swap R and B.
