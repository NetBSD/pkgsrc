$NetBSD: patch-src_video_scalers_Scale3xScaler.cc,v 1.1 2013/09/20 23:04:59 joerg Exp $

--- src/video/scalers/Scale3xScaler.cc.orig	2013-09-20 13:51:47.000000000 +0000
+++ src/video/scalers/Scale3xScaler.cc
@@ -28,9 +28,9 @@ Scale3xScaler<Pixel>::Scale3xScaler(cons
 
 template <class Pixel>
 void Scale3xScaler<Pixel>::scaleLine1on3Half(
-	Pixel* __restrict dst, const Pixel* __restrict src0,
-	const Pixel* __restrict src1, const Pixel* __restrict src2,
-	unsigned srcWidth) __restrict
+	Pixel* dst, const Pixel* src0,
+	const Pixel* src1, const Pixel* src2,
+	unsigned srcWidth)
 {
 	/* A B C
 	 * D E F
@@ -91,9 +91,9 @@ void Scale3xScaler<Pixel>::scaleLine1on3
 
 template <class Pixel>
 void Scale3xScaler<Pixel>::scaleLine1on3Mid(
-	Pixel* __restrict dst, const Pixel* __restrict src0,
-	const Pixel* __restrict src1, const Pixel* __restrict src2,
-	unsigned srcWidth) __restrict
+	Pixel* dst, const Pixel* src0,
+	const Pixel* src1, const Pixel* src2,
+	unsigned srcWidth)
 {
 	/*
 	 * A B C
