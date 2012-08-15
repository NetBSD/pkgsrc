$NetBSD: patch-src-post-deinterlace-plugins-greedy2frame_template_sse2.c,v 1.1 2012/08/15 18:34:36 jdc Exp $

--- src/post/deinterlace/plugins/greedy2frame_template_sse2.c.orig	2012-08-14 12:47:20.000000000 +0100
+++ src/post/deinterlace/plugins/greedy2frame_template_sse2.c	2012-08-15 09:47:02.000000000 +0100
@@ -85,10 +85,12 @@
 */
 
 
+#if defined(ARCH_X86) || defined(ARCH_X86_64)
 static const sse_t Mask128 = { uq: { 0x7f7f7f7f7f7f7f7fll, 0x7f7f7f7f7f7f7f7fll} };
 #define TP GREEDYTWOFRAMETHRESHOLD, GREEDYTWOFRAMETHRESHOLD2
 static const sse_t GreedyTwoFrameThreshold128 = { ub: {TP, TP, TP, TP, TP, TP, TP, TP} };
 #undef TP
+#endif /*ARCH_X86 */
 
 static void DeinterlaceGreedy2Frame_SSE2(uint8_t *output, int outstride,
                                          deinterlace_frame_data_t *data,
