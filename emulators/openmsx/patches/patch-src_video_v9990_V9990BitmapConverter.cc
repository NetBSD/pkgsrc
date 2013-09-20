$NetBSD: patch-src_video_v9990_V9990BitmapConverter.cc,v 1.1 2013/09/20 23:04:59 joerg Exp $

--- src/video/v9990/V9990BitmapConverter.cc.orig	2013-09-20 13:47:57.000000000 +0000
+++ src/video/v9990/V9990BitmapConverter.cc
@@ -27,8 +27,8 @@ V9990BitmapConverter<Pixel>::V9990Bitmap
 template<bool YJK, bool PAL, bool SKIP, typename Pixel>
 static inline void draw_YJK_YUV_PAL(
 	V9990VRAM& vram,
-	const Pixel* __restrict palette64, const Pixel* __restrict palette32768,
-	Pixel* __restrict pixelPtr, unsigned& address, int firstX = 0)
+	const Pixel* palette64, const Pixel* palette32768,
+	Pixel* pixelPtr, unsigned& address, int firstX = 0)
 {
 	byte data[4];
 	for (int i = 0; i < 4; ++i) {
@@ -56,7 +56,7 @@ static inline void draw_YJK_YUV_PAL(
 
 template <class Pixel>
 void V9990BitmapConverter<Pixel>::rasterBYUV(
-	Pixel* __restrict pixelPtr, unsigned x, unsigned y, int nrPixels) __restrict
+	Pixel* pixelPtr, unsigned x, unsigned y, int nrPixels)
 {
 	unsigned address = (x & ~3) + y * vdp.getImageWidth();
 	if (x & 3) {
@@ -73,7 +73,7 @@ void V9990BitmapConverter<Pixel>::raster
 
 template <class Pixel>
 void V9990BitmapConverter<Pixel>::rasterBYUVP(
-	Pixel* __restrict pixelPtr, unsigned x, unsigned y, int nrPixels) __restrict
+	Pixel* pixelPtr, unsigned x, unsigned y, int nrPixels)
 {
 	// TODO this mode cannot be shown in B4 and higher resolution modes
 	//      (So the dual palette for B4 modes is not an issue here.)
@@ -92,7 +92,7 @@ void V9990BitmapConverter<Pixel>::raster
 
 template <class Pixel>
 void V9990BitmapConverter<Pixel>::rasterBYJK(
-	Pixel* __restrict pixelPtr, unsigned x, unsigned y, int nrPixels) __restrict
+	Pixel* pixelPtr, unsigned x, unsigned y, int nrPixels)
 {
 	unsigned address = (x & ~3)+ y * vdp.getImageWidth();
 	if (x & 3) {
@@ -109,7 +109,7 @@ void V9990BitmapConverter<Pixel>::raster
 
 template <class Pixel>
 void V9990BitmapConverter<Pixel>::rasterBYJKP(
-	Pixel* __restrict pixelPtr, unsigned x, unsigned y, int nrPixels) __restrict
+	Pixel* pixelPtr, unsigned x, unsigned y, int nrPixels)
 {
 	// TODO this mode cannot be shown in B4 and higher resolution modes
 	//      (So the dual palette for B4 modes is not an issue here.)
@@ -128,7 +128,7 @@ void V9990BitmapConverter<Pixel>::raster
 
 template <class Pixel>
 void V9990BitmapConverter<Pixel>::rasterBD16(
-	Pixel* __restrict pixelPtr, unsigned x, unsigned y, int nrPixels) __restrict
+	Pixel* pixelPtr, unsigned x, unsigned y, int nrPixels)
 {
 	unsigned address = 2 * (x + y * vdp.getImageWidth());
 	if (vdp.isSuperimposing()) {
@@ -155,7 +155,7 @@ void V9990BitmapConverter<Pixel>::raster
 
 template <class Pixel>
 void V9990BitmapConverter<Pixel>::rasterBD8(
-	Pixel* __restrict pixelPtr, unsigned x, unsigned y, int nrPixels) __restrict
+	Pixel* pixelPtr, unsigned x, unsigned y, int nrPixels)
 {
 	unsigned address = x + y * vdp.getImageWidth();
 	for (/**/; nrPixels > 0; --nrPixels) {
@@ -165,7 +165,7 @@ void V9990BitmapConverter<Pixel>::raster
 
 template <class Pixel>
 void V9990BitmapConverter<Pixel>::rasterBP6(
-	Pixel* __restrict pixelPtr, unsigned x, unsigned y, int nrPixels) __restrict
+	Pixel* pixelPtr, unsigned x, unsigned y, int nrPixels)
 {
 	unsigned address = x + y * vdp.getImageWidth();
 	for (/**/; nrPixels > 0; --nrPixels) {
@@ -175,7 +175,7 @@ void V9990BitmapConverter<Pixel>::raster
 
 template <class Pixel>
 void V9990BitmapConverter<Pixel>::rasterBP4(
-	Pixel* __restrict pixelPtr, unsigned x, unsigned y, int nrPixels) __restrict
+	Pixel* pixelPtr, unsigned x, unsigned y, int nrPixels)
 {
 	assert(nrPixels > 0);
 	unsigned address = (x + y * vdp.getImageWidth()) / 2;
@@ -195,7 +195,7 @@ void V9990BitmapConverter<Pixel>::raster
 }
 template <class Pixel>
 void V9990BitmapConverter<Pixel>::rasterBP4HiRes(
-	Pixel* __restrict pixelPtr, unsigned x, unsigned y, int nrPixels) __restrict
+	Pixel* pixelPtr, unsigned x, unsigned y, int nrPixels)
 {
 	// Verified on real HW:
 	//   Bit PLT05 in palette offset is ignored, instead for even pixels
@@ -219,7 +219,7 @@ void V9990BitmapConverter<Pixel>::raster
 
 template <class Pixel>
 void V9990BitmapConverter<Pixel>::rasterBP2(
-	Pixel* __restrict pixelPtr, unsigned x, unsigned y, int nrPixels) __restrict
+	Pixel* pixelPtr, unsigned x, unsigned y, int nrPixels)
 {
 	assert(nrPixels > 0);
 	unsigned address = (x + y * vdp.getImageWidth()) / 4;
@@ -243,7 +243,7 @@ void V9990BitmapConverter<Pixel>::raster
 }
 template <class Pixel>
 void V9990BitmapConverter<Pixel>::rasterBP2HiRes(
-	Pixel* __restrict pixelPtr, unsigned x, unsigned y, int nrPixels) __restrict
+	Pixel* pixelPtr, unsigned x, unsigned y, int nrPixels)
 {
 	// Verified on real HW:
 	//   Bit PLT05 in palette offset is ignored, instead for even pixels
@@ -308,7 +308,7 @@ void V9990BitmapConverter<Pixel>::setCol
 
 template <class Pixel>
 void V9990BitmapConverter<Pixel>::drawCursor(
-	Pixel* __restrict buffer, int displayY, unsigned attrAddr, unsigned patAddr) __restrict
+	Pixel* buffer, int displayY, unsigned attrAddr, unsigned patAddr)
 {
 	int cursorY = vram.readVRAMBx(attrAddr + 0) +
 	             (vram.readVRAMBx(attrAddr + 2) & 1) * 256;
