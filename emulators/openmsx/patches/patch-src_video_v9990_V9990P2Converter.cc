$NetBSD: patch-src_video_v9990_V9990P2Converter.cc,v 1.1 2013/09/20 23:04:59 joerg Exp $

--- src/video/v9990/V9990P2Converter.cc.orig	2013-09-20 13:48:18.000000000 +0000
+++ src/video/v9990/V9990P2Converter.cc
@@ -58,8 +58,8 @@ void V9990P2Converter<Pixel>::convertLin
 
 template <class Pixel>
 void V9990P2Converter<Pixel>::renderPattern(
-	Pixel* __restrict buffer, unsigned width, unsigned x, unsigned y,
-	byte pal) __restrict
+	Pixel* buffer, unsigned width, unsigned x, unsigned y,
+	byte pal)
 {
 	static const unsigned patternTable = 0x00000;
 	static const unsigned nameTable    = 0x7C000;
@@ -153,7 +153,7 @@ void V9990P2Converter<Pixel>::renderPatt
 
 template <class Pixel>
 void V9990P2Converter<Pixel>::determineVisibleSprites(
-	int* __restrict visibleSprites, int displayY) __restrict
+	int* visibleSprites, int displayY)
 {
 	static const unsigned spriteTable = 0x3FE00;
 
@@ -179,8 +179,8 @@ void V9990P2Converter<Pixel>::determineV
 
 template <class Pixel>
 void V9990P2Converter<Pixel>::renderSprites(
-	Pixel* __restrict buffer, int displayX, int displayEnd, unsigned displayY,
-	int* __restrict visibleSprites, bool front) __restrict
+	Pixel* buffer, int displayX, int displayEnd, unsigned displayY,
+	int* visibleSprites, bool front)
 {
 	static const unsigned spriteTable = 0x3FE00;
 	unsigned spritePatternTable = vdp.getSpritePatternAddress(P1);
