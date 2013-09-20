$NetBSD: patch-src_video_scalers_HQ2xLiteScaler.cc,v 1.1 2013/09/20 23:04:59 joerg Exp $

--- src/video/scalers/HQ2xLiteScaler.cc.orig	2013-09-20 13:50:21.000000000 +0000
+++ src/video/scalers/HQ2xLiteScaler.cc
@@ -37,11 +37,11 @@ template <typename Pixel> struct HQLite_
 
 template <typename Pixel>
 void HQLite_1x1on2x2<Pixel>::operator()(
-	const Pixel* __restrict in0, const Pixel* __restrict in1,
-	const Pixel* __restrict in2,
-	Pixel* __restrict out0, Pixel* __restrict out1,
-	unsigned srcWidth, unsigned* __restrict edgeBuf,
-	EdgeHQLite /*edgeOp*/) __restrict
+	const Pixel* in0, const Pixel* in1,
+	const Pixel* in2,
+	Pixel* out0, Pixel* out1,
+	unsigned srcWidth, unsigned* edgeBuf,
+	EdgeHQLite /*edgeOp*/)
 {
 	unsigned c2, c4, c5, c6, c8, c9;
 	c2 =      readPixel(in0[0]);
@@ -93,11 +93,11 @@ void HQLite_1x1on2x2<Pixel>::operator()(
 
 template <typename Pixel>
 void HQLite_1x1on1x2<Pixel>::operator()(
-	const Pixel* __restrict in0, const Pixel* __restrict in1,
-	const Pixel* __restrict in2,
-	Pixel* __restrict out0, Pixel* __restrict out1,
-	unsigned srcWidth, unsigned* __restrict edgeBuf,
-	EdgeHQLite /*edgeOp*/) __restrict
+	const Pixel* in0, const Pixel* in1,
+	const Pixel* in2,
+	Pixel* out0, Pixel* out1,
+	unsigned srcWidth, unsigned* edgeBuf,
+	EdgeHQLite /*edgeOp*/)
 {
 	//  +---+---+---+
 	//  | 1 | 2 | 3 |
