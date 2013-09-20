$NetBSD: patch-src_video_scalers_SaI2xScaler.cc,v 1.1 2013/09/20 23:04:59 joerg Exp $

--- src/video/scalers/SaI2xScaler.cc.orig	2013-09-20 13:51:18.000000000 +0000
+++ src/video/scalers/SaI2xScaler.cc
@@ -53,10 +53,10 @@ inline Pixel SaI2xScaler<Pixel>::blend(P
 
 template <class Pixel>
 void SaI2xScaler<Pixel>::scaleLine1on2(
-	const Pixel* __restrict srcLine0, const Pixel* __restrict srcLine1,
-	const Pixel* __restrict srcLine2, const Pixel* __restrict srcLine3,
-	Pixel* __restrict dstUpper, Pixel* __restrict dstLower,
-	unsigned srcWidth) __restrict
+	const Pixel* srcLine0, const Pixel* srcLine1,
+	const Pixel* srcLine2, const Pixel* srcLine3,
+	Pixel* dstUpper, Pixel* dstLower,
+	unsigned srcWidth)
 {
 	// TODO: Scale border pixels as well.
 	for (unsigned x = 0; x < srcWidth; x++) {
@@ -188,10 +188,10 @@ void SaI2xScaler<Pixel>::scaleLine1on2(
 
 template <class Pixel>
 void SaI2xScaler<Pixel>::scaleLine1on1(
-	const Pixel* __restrict srcLine0, const Pixel* __restrict srcLine1,
-	const Pixel* __restrict srcLine2, const Pixel* __restrict srcLine3,
-	Pixel* __restrict dstUpper, Pixel* __restrict dstLower,
-	unsigned srcWidth) __restrict
+	const Pixel* srcLine0, const Pixel* srcLine1,
+	const Pixel* srcLine2, const Pixel* srcLine3,
+	Pixel* dstUpper, Pixel* dstLower,
+	unsigned srcWidth)
 {
 	// Apply 2xSaI and keep the bottom-left pixel.
 	// It's not great, but at least it looks better than doubling the pixel
