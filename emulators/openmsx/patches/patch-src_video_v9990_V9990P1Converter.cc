$NetBSD: patch-src_video_v9990_V9990P1Converter.cc,v 1.1 2013/09/20 23:04:59 joerg Exp $

--- src/video/v9990/V9990P1Converter.cc.orig	2013-09-20 13:48:36.000000000 +0000
+++ src/video/v9990/V9990P1Converter.cc
@@ -94,8 +94,8 @@ void V9990P1Converter<Pixel>::renderPatt
 
 template <class Pixel>
 void V9990P1Converter<Pixel>::renderPattern2(
-	Pixel* __restrict buffer, unsigned width, unsigned x, unsigned y,
-	unsigned nameTable, unsigned patternTable, byte pal) __restrict
+	Pixel* buffer, unsigned width, unsigned x, unsigned y,
+	unsigned nameTable, unsigned patternTable, byte pal)
 {
 	x &= 511;
 	const Pixel* palette = palette64 + pal;
@@ -186,7 +186,7 @@ void V9990P1Converter<Pixel>::renderPatt
 
 template <class Pixel>
 void V9990P1Converter<Pixel>::determineVisibleSprites(
-	int* __restrict visibleSprites, unsigned displayY) __restrict
+	int* visibleSprites, unsigned displayY)
 {
 	static const unsigned spriteTable = 0x3FE00;
 
@@ -211,8 +211,8 @@ void V9990P1Converter<Pixel>::determineV
 
 template <class Pixel>
 void V9990P1Converter<Pixel>::renderSprites(
-	Pixel* __restrict buffer, int displayX, int displayEnd, unsigned displayY,
-	int* __restrict visibleSprites, bool front) __restrict
+	Pixel* buffer, int displayX, int displayEnd, unsigned displayY,
+	int* visibleSprites, bool front)
 {
 	static const unsigned spriteTable = 0x3FE00;
 	unsigned spritePatternTable = vdp.getSpritePatternAddress(P1);
