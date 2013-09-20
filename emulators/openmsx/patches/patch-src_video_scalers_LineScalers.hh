$NetBSD: patch-src_video_scalers_LineScalers.hh,v 1.1 2013/09/20 23:04:59 joerg Exp $

--- src/video/scalers/LineScalers.hh.orig	2013-09-20 13:46:48.000000000 +0000
+++ src/video/scalers/LineScalers.hh
@@ -402,7 +402,7 @@ extern "C"
 
 template <typename Pixel, unsigned N>
 static inline void scale_1onN(
-	const Pixel* __restrict in, Pixel* __restrict out, unsigned long width)
+	const Pixel* in, Pixel* out, unsigned long width)
 {
 	unsigned i = 0, j = 0;
 	for (/* */; i < (width - (N - 1)); i += N, j += 1) {
@@ -437,7 +437,7 @@ void Scale_1on6<Pixel>::operator()(const
 
 template <typename Pixel, bool streaming>
 void Scale_1on2<Pixel, streaming>::operator()(
-	const Pixel* __restrict in, Pixel* __restrict out, unsigned long width) __restrict
+	const Pixel* in, Pixel* out, unsigned long width)
 {
 	unsigned long width2 = 0;
 
@@ -674,7 +674,7 @@ void Scale_1on2<Pixel, streaming>::opera
 
 template <typename Pixel, bool streaming>
 void Scale_1on1<Pixel, streaming>::operator()(
-	const Pixel* __restrict in, Pixel* __restrict out, unsigned long width) __restrict
+	const Pixel* in, Pixel* out, unsigned long width)
 {
 	unsigned long nBytes = width * sizeof(Pixel);
 	unsigned long nBytes2 = 0;
@@ -826,7 +826,7 @@ Scale_2on1<Pixel>::Scale_2on1(PixelOpera
 
 template <typename Pixel>
 void Scale_2on1<Pixel>::operator()(
-	const Pixel* __restrict in, Pixel* __restrict out, unsigned long width) __restrict
+	const Pixel* in, Pixel* out, unsigned long width)
 {
 	unsigned long width2 = 0;
 
@@ -1084,7 +1084,7 @@ Scale_6on1<Pixel>::Scale_6on1(PixelOpera
 
 template <typename Pixel>
 void Scale_6on1<Pixel>::operator()(
-	const Pixel* __restrict in, Pixel* __restrict out, unsigned long width) __restrict
+	const Pixel* in, Pixel* out, unsigned long width)
 {
 	for (unsigned i = 0; i < width; ++i) {
 		out[i] = pixelOps.template blend6<1, 1, 1, 1, 1, 1>(&in[6 * i]);
@@ -1100,7 +1100,7 @@ Scale_4on1<Pixel>::Scale_4on1(PixelOpera
 
 template <typename Pixel>
 void Scale_4on1<Pixel>::operator()(
-	const Pixel* __restrict in, Pixel* __restrict out, unsigned long width) __restrict
+	const Pixel* in, Pixel* out, unsigned long width)
 {
 	for (unsigned i = 0; i < width; ++i) {
 		out[i] = pixelOps.template blend4<1, 1, 1, 1>(&in[4 * i]);
@@ -1116,7 +1116,7 @@ Scale_3on1<Pixel>::Scale_3on1(PixelOpera
 
 template <typename Pixel>
 void Scale_3on1<Pixel>::operator()(
-	const Pixel* __restrict in, Pixel* __restrict out, unsigned long width) __restrict
+	const Pixel* in, Pixel* out, unsigned long width)
 {
 	for (unsigned i = 0; i < width; ++i) {
 		out[i] = pixelOps.template blend3<1, 1, 1>(&in[3 * i]);
@@ -1132,7 +1132,7 @@ Scale_3on2<Pixel>::Scale_3on2(PixelOpera
 
 template <typename Pixel>
 void Scale_3on2<Pixel>::operator()(
-	const Pixel* __restrict in, Pixel* __restrict out, unsigned long width) __restrict
+	const Pixel* in, Pixel* out, unsigned long width)
 {
 	unsigned i = 0, j = 0;
 	for (/* */; i < (width - 1); i += 2, j += 3) {
@@ -1151,7 +1151,7 @@ Scale_3on4<Pixel>::Scale_3on4(PixelOpera
 
 template <typename Pixel>
 void Scale_3on4<Pixel>::operator()(
-	const Pixel* __restrict in, Pixel* __restrict out, unsigned long width) __restrict
+	const Pixel* in, Pixel* out, unsigned long width)
 {
 	unsigned i = 0, j = 0;
 	for (/* */; i < (width - 3); i += 4, j += 3) {
@@ -1174,7 +1174,7 @@ Scale_3on8<Pixel>::Scale_3on8(PixelOpera
 
 template <typename Pixel>
 void Scale_3on8<Pixel>::operator()(
-	const Pixel* __restrict in, Pixel* __restrict out, unsigned long width) __restrict
+	const Pixel* in, Pixel* out, unsigned long width)
 {
 	unsigned i = 0, j = 0;
 	for (/* */; i < (width - 7); i += 8, j += 3) {
@@ -1201,7 +1201,7 @@ Scale_2on3<Pixel>::Scale_2on3(PixelOpera
 
 template <typename Pixel>
 void Scale_2on3<Pixel>::operator()(
-	const Pixel* __restrict in, Pixel* __restrict out, unsigned long width) __restrict
+	const Pixel* in, Pixel* out, unsigned long width)
 {
 	unsigned i = 0, j = 0;
 	for (/* */; i < (width - 2); i += 3, j += 2) {
@@ -1222,7 +1222,7 @@ Scale_4on3<Pixel>::Scale_4on3(PixelOpera
 
 template <typename Pixel>
 void Scale_4on3<Pixel>::operator()(
-	const Pixel* __restrict in, Pixel* __restrict out, unsigned long width) __restrict
+	const Pixel* in, Pixel* out, unsigned long width)
 {
 	unsigned i = 0, j = 0;
 	for (/* */; i < (width - 2); i += 3, j += 4) {
@@ -1243,7 +1243,7 @@ Scale_8on3<Pixel>::Scale_8on3(PixelOpera
 
 template <typename Pixel>
 void Scale_8on3<Pixel>::operator()(
-	const Pixel* __restrict in, Pixel* __restrict out, unsigned long width) __restrict
+	const Pixel* in, Pixel* out, unsigned long width)
 {
 	unsigned i = 0, j = 0;
 	for (/* */; i < (width - 2); i += 3, j += 8) {
@@ -1264,7 +1264,7 @@ Scale_2on9<Pixel>::Scale_2on9(PixelOpera
 
 template <typename Pixel>
 void Scale_2on9<Pixel>::operator()(
-	const Pixel* __restrict in, Pixel* __restrict out, unsigned long width) __restrict
+	const Pixel* in, Pixel* out, unsigned long width)
 {
 	unsigned i = 0, j = 0;
 	for (/* */; i < (width - 8); i += 9, j += 2) {
@@ -1297,7 +1297,7 @@ Scale_4on9<Pixel>::Scale_4on9(PixelOpera
 
 template <typename Pixel>
 void Scale_4on9<Pixel>::operator()(
-	const Pixel* __restrict in, Pixel* __restrict out, unsigned long width) __restrict
+	const Pixel* in, Pixel* out, unsigned long width)
 {
 	unsigned i = 0, j = 0;
 	for (/* */; i < (width - 8); i += 9, j += 4) {
@@ -1330,7 +1330,7 @@ Scale_8on9<Pixel>::Scale_8on9(PixelOpera
 
 template <typename Pixel>
 void Scale_8on9<Pixel>::operator()(
-	const Pixel* __restrict in, Pixel* __restrict out, unsigned long width) __restrict
+	const Pixel* in, Pixel* out, unsigned long width)
 {
 	unsigned i = 0, j = 0;
 	for (/* */; i < width; i += 9, j += 8) {
@@ -1363,7 +1363,7 @@ Scale_4on5<Pixel>::Scale_4on5(PixelOpera
 
 template <typename Pixel>
 void Scale_4on5<Pixel>::operator()(
-	const Pixel* __restrict in, Pixel* __restrict out, unsigned long width) __restrict
+	const Pixel* in, Pixel* out, unsigned long width)
 {
 	assert((width % 5) == 0);
 	for (unsigned i = 0, j = 0; i < width; i += 5, j += 4) {
@@ -1384,7 +1384,7 @@ Scale_7on8<Pixel>::Scale_7on8(PixelOpera
 
 template <typename Pixel>
 void Scale_7on8<Pixel>::operator()(
-	const Pixel* __restrict in, Pixel* __restrict out, unsigned long width) __restrict
+	const Pixel* in, Pixel* out, unsigned long width)
 {
 	assert((width % 8) == 0);
 	for (unsigned i = 0, j = 0; i < width; i += 8, j += 7) {
@@ -1408,7 +1408,7 @@ Scale_17on20<Pixel>::Scale_17on20(PixelO
 
 template <typename Pixel>
 void Scale_17on20<Pixel>::operator()(
-	const Pixel* __restrict in, Pixel* __restrict out, unsigned long width) __restrict
+	const Pixel* in, Pixel* out, unsigned long width)
 {
 	assert((width % 20) == 0);
 	for (unsigned i = 0, j = 0; i < width; i += 20, j += 17) {
@@ -1444,7 +1444,7 @@ Scale_9on10<Pixel>::Scale_9on10(PixelOpe
 
 template <typename Pixel>
 void Scale_9on10<Pixel>::operator()(
-	const Pixel* __restrict in, Pixel* __restrict out, unsigned long width) __restrict
+	const Pixel* in, Pixel* out, unsigned long width)
 {
 	assert((width % 10) == 0);
 	for (unsigned i = 0, j = 0; i < width; i += 10, j += 9) {
@@ -1470,8 +1470,8 @@ BlendLines<Pixel, w1, w2>::BlendLines(Pi
 
 template <typename Pixel, unsigned w1, unsigned w2>
 void BlendLines<Pixel, w1, w2>::operator()(
-	const Pixel* __restrict in1, const Pixel* __restrict in2,
-	Pixel* __restrict out, unsigned width) __restrict
+	const Pixel* in1, const Pixel* in2,
+	Pixel* out, unsigned width)
 {
 	// TODO MMX/SSE optimizations
 	// pure C++ version
@@ -1513,8 +1513,8 @@ AlphaBlendLines<Pixel>::AlphaBlendLines(
 
 template <typename Pixel>
 void AlphaBlendLines<Pixel>::operator()(
-	const Pixel* __restrict in1, const Pixel* __restrict in2,
-	Pixel* __restrict out, unsigned width) __restrict
+	const Pixel* in1, const Pixel* in2,
+	Pixel* out, unsigned width)
 {
 	for (unsigned i = 0; i < width; ++i) {
 		out[i] = pixelOps.alphaBlend(in1[i], in2[i]);
@@ -1523,8 +1523,8 @@ void AlphaBlendLines<Pixel>::operator()(
 
 template <typename Pixel>
 void AlphaBlendLines<Pixel>::operator()(
-	Pixel in1, const Pixel* __restrict in2,
-	Pixel* __restrict out, unsigned width) __restrict
+	Pixel in1, const Pixel* in2,
+	Pixel* out, unsigned width)
 {
 	// ATM this routine is only called when 'in1' is not fully opaque nor
 	// fully transparent. This cannot happen in 16bpp modes.
