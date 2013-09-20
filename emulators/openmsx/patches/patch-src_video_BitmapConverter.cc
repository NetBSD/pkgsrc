$NetBSD: patch-src_video_BitmapConverter.cc,v 1.1 2013/09/20 23:04:59 joerg Exp $

--- src/video/BitmapConverter.cc.orig	2013-09-20 13:46:13.000000000 +0000
+++ src/video/BitmapConverter.cc
@@ -102,8 +102,8 @@ void BitmapConverter<Pixel>::convertLine
 
 template <class Pixel>
 void BitmapConverter<Pixel>::renderGraphic4(
-	Pixel*      __restrict pixelPtr,
-	const byte* __restrict vramPtr0) __restrict
+	Pixel*      pixelPtr,
+	const byte* vramPtr0)
 {
 	/*for (unsigned i = 0; i < 128; i += 2) {
 		unsigned data0 = vramPtr0[i + 0];
@@ -180,8 +180,8 @@ void BitmapConverter<Pixel>::renderGraph
 
 template <class Pixel>
 void BitmapConverter<Pixel>::renderGraphic5(
-	Pixel*      __restrict pixelPtr,
-	const byte* __restrict vramPtr0) __restrict
+	Pixel*      pixelPtr,
+	const byte* vramPtr0)
 {
 	for (unsigned i = 0; i < 128; ++i) {
 		unsigned data = vramPtr0[i];
@@ -194,9 +194,9 @@ void BitmapConverter<Pixel>::renderGraph
 
 template <class Pixel>
 void BitmapConverter<Pixel>::renderGraphic6(
-	Pixel*      __restrict pixelPtr,
-	const byte* __restrict vramPtr0,
-	const byte* __restrict vramPtr1) __restrict
+	Pixel*      pixelPtr,
+	const byte* vramPtr0,
+	const byte* vramPtr1)
 {
 	/*for (unsigned i = 0; i < 128; ++i) {
 		unsigned data0 = vramPtr0[i];
@@ -240,9 +240,9 @@ void BitmapConverter<Pixel>::renderGraph
 
 template <class Pixel>
 void BitmapConverter<Pixel>::renderGraphic7(
-	Pixel*      __restrict pixelPtr,
-	const byte* __restrict vramPtr0,
-	const byte* __restrict vramPtr1) __restrict
+	Pixel*      pixelPtr,
+	const byte* vramPtr0,
+	const byte* vramPtr1)
 {
 	for (unsigned i = 0; i < 128; ++i) {
 		pixelPtr[2 * i + 0] = palette256[vramPtr0[i]];
@@ -252,9 +252,9 @@ void BitmapConverter<Pixel>::renderGraph
 
 template <class Pixel>
 void BitmapConverter<Pixel>::renderYJK(
-	Pixel*      __restrict pixelPtr,
-	const byte* __restrict vramPtr0,
-	const byte* __restrict vramPtr1) __restrict
+	Pixel*      pixelPtr,
+	const byte* vramPtr0,
+	const byte* vramPtr1)
 {
 	for (unsigned i = 0; i < 64; ++i) {
 		unsigned p[4];
@@ -279,9 +279,9 @@ void BitmapConverter<Pixel>::renderYJK(
 
 template <class Pixel>
 void BitmapConverter<Pixel>::renderYAE(
-	Pixel*      __restrict pixelPtr,
-	const byte* __restrict vramPtr0,
-	const byte* __restrict vramPtr1) __restrict
+	Pixel*      pixelPtr,
+	const byte* vramPtr0,
+	const byte* vramPtr1)
 {
 	for (unsigned i = 0; i < 64; ++i) {
 		unsigned p[4];
