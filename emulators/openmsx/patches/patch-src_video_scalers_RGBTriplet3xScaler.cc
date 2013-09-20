$NetBSD: patch-src_video_scalers_RGBTriplet3xScaler.cc,v 1.1 2013/09/20 23:04:59 joerg Exp $

--- src/video/scalers/RGBTriplet3xScaler.cc.orig	2013-09-20 13:51:07.000000000 +0000
+++ src/video/scalers/RGBTriplet3xScaler.cc
@@ -42,8 +42,8 @@ void RGBTriplet3xScaler<Pixel>::calcSpil
 
 template <class Pixel>
 void RGBTriplet3xScaler<Pixel>::rgbify(
-		const Pixel* __restrict in, Pixel* __restrict out,
-		unsigned inwidth) __restrict
+		const Pixel* in, Pixel* out,
+		unsigned inwidth)
 {
 	unsigned r, g, b, rs, gs, bs;
 	unsigned i = 0;
@@ -290,7 +290,7 @@ void RGBTriplet3xScaler<Pixel>::scale4x2
 }
 
 template <typename Pixel>
-static void fillLoop(const Pixel* __restrict in, Pixel* __restrict out,
+static void fillLoop(const Pixel* in, Pixel* out,
                      unsigned dstWidth)
 {
 	out[0] = in[0];
