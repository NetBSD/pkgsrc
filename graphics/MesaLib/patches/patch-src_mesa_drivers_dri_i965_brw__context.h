$NetBSD: patch-src_mesa_drivers_dri_i965_brw__context.h,v 1.1 2015/09/11 12:38:27 tnn Exp $

Fix build on NetBSD 5.x.
The ALIGN macro in Mesa conflicts with machine/param.h. It is easier to
avoid it than attempting to fix the include order here.

--- src/mesa/drivers/dri/i965/brw_context.h.orig	2015-09-10 17:40:31.000000000 +0000
+++ src/mesa/drivers/dri/i965/brw_context.h
@@ -1912,7 +1912,11 @@ brw_compute_program(struct gl_compute_pr
 static inline int
 brw_register_blocks(int reg_count)
 {
+#if 0
    return ALIGN(reg_count, 16) / 16 - 1;
+#else
+   return (((reg_count + 0xF) & ~0xF) >> 4) - 1;
+#endif
 }
 
 static inline uint32_t
