$NetBSD: patch-src_video_scalers_Scale2xScaler.cc,v 1.1 2013/09/20 23:04:59 joerg Exp $

--- src/video/scalers/Scale2xScaler.cc.orig	2013-09-20 13:51:42.000000000 +0000
+++ src/video/scalers/Scale2xScaler.cc
@@ -38,9 +38,9 @@ Scale2xScaler<Pixel>::Scale2xScaler(cons
 
 template <class Pixel>
 void Scale2xScaler<Pixel>::scaleLineHalf_1on2(
-	Pixel* __restrict dst, const Pixel* __restrict src0,
-	const Pixel* __restrict src1, const Pixel* __restrict src2,
-	unsigned long srcWidth) __restrict
+	Pixel* dst, const Pixel* src0,
+	const Pixel* src1, const Pixel* src2,
+	unsigned long srcWidth)
 {
 	//   n      m is expaned to a b
 	// w m e                    c d
@@ -634,9 +634,9 @@ void Scale2xScaler<Pixel>::scaleLineHalf
 
 template <class Pixel>
 void Scale2xScaler<Pixel>::scaleLineHalf_1on1(
-	Pixel* __restrict dst, const Pixel* __restrict src0,
-	const Pixel* __restrict src1, const Pixel* __restrict src2,
-	unsigned long srcWidth) __restrict
+	Pixel* dst, const Pixel* src0,
+	const Pixel* src1, const Pixel* src2,
+	unsigned long srcWidth)
 {
 	//    ab ef
 	// x0 12 34 5x
