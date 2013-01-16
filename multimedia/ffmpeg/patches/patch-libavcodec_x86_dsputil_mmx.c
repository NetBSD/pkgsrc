$NetBSD: patch-libavcodec_x86_dsputil_mmx.c,v 1.1 2013/01/16 20:55:47 adam Exp $

--- libavcodec/x86/dsputil_mmx.c.orig	2013-01-06 21:53:29.000000000 +0000
+++ libavcodec/x86/dsputil_mmx.c
@@ -1785,6 +1785,7 @@ static av_always_inline void gmc(uint8_t
     }
 }
 
+#if CONFIG_VIDEODSP
 #if HAVE_YASM
 #if ARCH_X86_32
 static void gmc_mmx(uint8_t *dst, uint8_t *src,
@@ -1814,6 +1815,7 @@ static void gmc_mmx(uint8_t *dst, uint8_
         width, height, &ff_emulated_edge_mc_8);
 }
 #endif
+#endif
 
 #endif /* HAVE_INLINE_ASM */
 
@@ -2518,7 +2520,7 @@ static void dsputil_init_sse(DSPContext 
     c->scalarproduct_float          = ff_scalarproduct_float_sse;
     c->butterflies_float_interleave = ff_butterflies_float_interleave_sse;
 
-#if HAVE_INLINE_ASM
+#if HAVE_INLINE_ASM && CONFIG_VIDEODSP
     c->gmc = gmc_sse;
 #endif
 #endif /* HAVE_YASM */
