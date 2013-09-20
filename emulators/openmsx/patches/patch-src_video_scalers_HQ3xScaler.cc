$NetBSD: patch-src_video_scalers_HQ3xScaler.cc,v 1.1 2013/09/20 23:04:59 joerg Exp $

--- src/video/scalers/HQ3xScaler.cc.orig	2013-09-20 13:50:47.000000000 +0000
+++ src/video/scalers/HQ3xScaler.cc
@@ -28,12 +28,12 @@ template <typename Pixel> struct HQ_1x1o
 
 template <typename Pixel>
 void HQ_1x1on3x3<Pixel>::operator()(
-	const Pixel* __restrict in0, const Pixel* __restrict in1,
-	const Pixel* __restrict in2,
-	Pixel* __restrict out0, Pixel* __restrict out1,
-	Pixel* __restrict out2,
-	unsigned srcWidth, unsigned* __restrict edgeBuf,
-	EdgeHQ edgeOp) __restrict
+	const Pixel* in0, const Pixel* in1,
+	const Pixel* in2,
+	Pixel* out0, Pixel* out1,
+	Pixel* out2,
+	unsigned srcWidth, unsigned* edgeBuf,
+	EdgeHQ edgeOp)
 {
 	unsigned c1, c2, c3, c4, c5, c6, c7, c8, c9;
 	c2 = c3 = readPixel(in0[0]);
