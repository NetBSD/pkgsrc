$NetBSD: patch-src-post-deinterlace-plugins-greedy2frame_template.c,v 1.1 2012/08/15 18:34:36 jdc Exp $

--- src/post/deinterlace/plugins/greedy2frame_template.c.orig	2012-05-26 21:49:59.000000000 +0100
+++ src/post/deinterlace/plugins/greedy2frame_template.c	2012-08-15 09:46:37.000000000 +0100
@@ -85,6 +85,7 @@
 */
 
 
+#if defined(ARCH_X86) || defined(ARCH_X86_64)
 #if !defined(MASKS_DEFINED)
 #define MASKS_DEFINED
 static const mmx_t Mask = { uq: 0x7f7f7f7f7f7f7f7fll };
@@ -92,6 +93,7 @@
 static const mmx_t GreedyTwoFrameThreshold = { ub: {TP, TP, TP, TP} };
 #undef TP
 #endif
+#endif /*ARCH_X86 */
 
 #if defined(IS_MMXEXT)
 static void DeinterlaceGreedy2Frame_MMXEXT(uint8_t *output, int outstride,
