$NetBSD: patch-src_video_scalers_SaI3xScaler.cc,v 1.1 2013/09/20 23:04:59 joerg Exp $

--- src/video/scalers/SaI3xScaler.cc.orig	2013-09-20 13:51:36.000000000 +0000
+++ src/video/scalers/SaI3xScaler.cc
@@ -323,8 +323,8 @@ class LineRepeater
 public:
 	template <unsigned NX, unsigned NY, typename Pixel>
 	inline static void scaleFixedLine(
-		const Pixel* __restrict src0, const Pixel* __restrict src1,
-		const Pixel* __restrict src2, const Pixel* __restrict src3,
+		const Pixel* src0, const Pixel* src1,
+		const Pixel* src2, const Pixel* src3,
 		unsigned srcWidth, ScalerOutput<Pixel>& dst, unsigned& dstY)
 	{
 		Pixel* dp = dst.acquireLine(dstY);
@@ -413,7 +413,7 @@ void SaI3xScaler<Pixel>::scaleFixed(Fram
 template <typename Pixel>
 void SaI3xScaler<Pixel>::scaleAny(FrameSource& src,
 	unsigned srcStartY, unsigned /*srcEndY*/, unsigned srcWidth,
-	ScalerOutput<Pixel>& dst, unsigned dstStartY, unsigned dstEndY) __restrict
+	ScalerOutput<Pixel>& dst, unsigned dstStartY, unsigned dstEndY)
 {
 	// Calculate fixed point end coordinates and deltas.
 	const unsigned wfinish = (srcWidth - 1) << 16;
@@ -426,14 +426,14 @@ void SaI3xScaler<Pixel>::scaleAny(FrameS
 		// Get source line pointers.
 		int line = srcStartY + (h >> 16);
 		// TODO possible optimization: reuse srcN from previous step
-		const Pixel* __restrict src0 = src.getLinePtr<Pixel>(line - 1, srcWidth);
-		const Pixel* __restrict src1 = src.getLinePtr<Pixel>(line + 0, srcWidth);
-		const Pixel* __restrict src2 = src.getLinePtr<Pixel>(line + 1, srcWidth);
-		const Pixel* __restrict src3 = src.getLinePtr<Pixel>(line + 2, srcWidth);
+		const Pixel* src0 = src.getLinePtr<Pixel>(line - 1, srcWidth);
+		const Pixel* src1 = src.getLinePtr<Pixel>(line + 0, srcWidth);
+		const Pixel* src2 = src.getLinePtr<Pixel>(line + 1, srcWidth);
+		const Pixel* src3 = src.getLinePtr<Pixel>(line + 2, srcWidth);
 
 		// Get destination line pointer.
 		Pixel* dstLine = dst.acquireLine(dstY);
-		Pixel* __restrict dp = dstLine;
+		Pixel* dp = dstLine;
 
 		// Fractional parts of the fixed point Y coordinates.
 		const unsigned y1 = h & 0xffff;
