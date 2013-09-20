$NetBSD: patch-src_video_CharacterConverter.cc,v 1.1 2013/09/20 23:04:59 joerg Exp $

--- src/video/CharacterConverter.cc.orig	2013-09-20 13:45:16.000000000 +0000
+++ src/video/CharacterConverter.cc
@@ -59,7 +59,7 @@ void CharacterConverter<Pixel>::convertL
 
 template <class Pixel>
 void CharacterConverter<Pixel>::renderText1(
-	Pixel* __restrict pixelPtr, int line) __restrict
+	Pixel* pixelPtr, int line)
 {
 	Pixel fg = palFg[vdp.getForegroundColor()];
 	Pixel bg = palFg[vdp.getBackgroundColor()];
@@ -88,7 +88,7 @@ void CharacterConverter<Pixel>::renderTe
 
 template <class Pixel>
 void CharacterConverter<Pixel>::renderText1Q(
-	Pixel* __restrict pixelPtr, int line) __restrict
+	Pixel* pixelPtr, int line)
 {
 	Pixel fg = palFg[vdp.getForegroundColor()];
 	Pixel bg = palFg[vdp.getBackgroundColor()];
@@ -118,7 +118,7 @@ void CharacterConverter<Pixel>::renderTe
 
 template <class Pixel>
 void CharacterConverter<Pixel>::renderText2(
-	Pixel* __restrict pixelPtr, int line) __restrict
+	Pixel* pixelPtr, int line)
 {
 	Pixel plainFg = palFg[vdp.getForegroundColor()];
 	Pixel plainBg = palFg[vdp.getBackgroundColor()];
@@ -238,7 +238,7 @@ const byte* CharacterConverter<Pixel>::g
 }
 template <class Pixel>
 void CharacterConverter<Pixel>::renderGraphic1(
-	Pixel* __restrict pixelPtr, int line) __restrict
+	Pixel* pixelPtr, int line)
 {
 	const byte* patternArea = vram.patternTable.getReadArea(0, 256 * 8);
 	patternArea += line & 7;
@@ -268,7 +268,7 @@ void CharacterConverter<Pixel>::renderGr
 
 template <class Pixel>
 void CharacterConverter<Pixel>::renderGraphic2(
-	Pixel* __restrict pixelPtr, int line) __restrict
+	Pixel* pixelPtr, int line)
 {
 	int quarter = ((line / 8) * 32) & ~0xFF;
 	int baseLine = (-1 << 13) | (quarter * 8) | (line & 7);
@@ -351,8 +351,8 @@ void CharacterConverter<Pixel>::renderGr
 
 template <class Pixel>
 void CharacterConverter<Pixel>::renderMultiHelper(
-	Pixel* __restrict pixelPtr, int line,
-	int mask, int patternQuarter) __restrict
+	Pixel* pixelPtr, int line,
+	int mask, int patternQuarter)
 {
 	unsigned baseLine = mask | ((line / 4) & 7);
 	unsigned scroll = vdp.getHorizontalScrollHigh();
@@ -372,7 +372,7 @@ void CharacterConverter<Pixel>::renderMu
 }
 template <class Pixel>
 void CharacterConverter<Pixel>::renderMulti(
-	Pixel* __restrict pixelPtr, int line) __restrict
+	Pixel* pixelPtr, int line)
 {
 	int mask = (-1 << 11);
 	renderMultiHelper(pixelPtr, line, mask, 0);
@@ -380,7 +380,7 @@ void CharacterConverter<Pixel>::renderMu
 
 template <class Pixel>
 void CharacterConverter<Pixel>::renderMultiQ(
-	Pixel* __restrict pixelPtr, int line) __restrict
+	Pixel* pixelPtr, int line)
 {
 	int mask = (-1 << 13);
 	int patternQuarter = (line * 4) & ~0xFF;  // (line / 8) * 32
@@ -389,7 +389,7 @@ void CharacterConverter<Pixel>::renderMu
 
 template <class Pixel>
 void CharacterConverter<Pixel>::renderBogus(
-	Pixel* __restrict pixelPtr) __restrict
+	Pixel* pixelPtr)
 {
 	Pixel fg = palFg[vdp.getForegroundColor()];
 	Pixel bg = palFg[vdp.getBackgroundColor()];
