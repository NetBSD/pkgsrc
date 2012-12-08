$NetBSD: patch-dpx.imageio_libdpx_DPXColorConverter.cpp,v 1.1 2012/12/08 22:47:41 adam Exp $

Define 'max' as unsigned int, because 0xFFFFFFFF does not fit in int.

--- dpx.imageio/libdpx/DPXColorConverter.cpp.orig	2012-12-07 21:29:43.000000000 +0000
+++ dpx.imageio/libdpx/DPXColorConverter.cpp
@@ -90,7 +90,7 @@ namespace dpx {
 		}
 	}
 
-	template <typename DATA, int max>
+	template <typename DATA, unsigned int max>
 	static inline void ConvertPixelYCbCrToRGB(const DATA CbYCr[3], DATA RGB[3], const float matrix[9]) {
 		float tmp;
 		for (int i = 0; i < 3; i++) {
@@ -106,7 +106,7 @@ namespace dpx {
 	}
 
 	// 4:4:4
-	template <typename DATA, int max>
+	template <typename DATA, unsigned int max>
 	static bool ConvertCbYCrToRGB(const Characteristic space, const DATA *input, DATA *output, const int pixels) {
 		const float *matrix = GetYCbCrToRGBColorMatrix(space);
 		if (matrix == NULL)
@@ -120,7 +120,7 @@ namespace dpx {
 	}
 
 	// 4:4:4:4
-	template <typename DATA, int max>
+	template <typename DATA, unsigned int max>
 	static bool ConvertCbYCrAToRGBA(const Characteristic space, const DATA *input, DATA *output, const int pixels) {
 		const float *matrix = GetYCbCrToRGBColorMatrix(space);
 		if (matrix == NULL)
@@ -135,7 +135,7 @@ namespace dpx {
 	}
 
 	// 4:2:2
-	template <typename DATA, int max>
+	template <typename DATA, unsigned int max>
 	static bool ConvertCbYCrYToRGB(const Characteristic space, const DATA *input, DATA *output, const int pixels) {
 		const float *matrix = GetYCbCrToRGBColorMatrix(space);
 		if (matrix == NULL)
@@ -154,7 +154,7 @@ namespace dpx {
 	}
 
 	// 4:2:2:4
-	template <typename DATA, int max>
+	template <typename DATA, unsigned int max>
 	static bool ConvertCbYACrYAToRGBA(const Characteristic space, const DATA *input, DATA *output, const int pixels) {
 		const float *matrix = GetYCbCrToRGBColorMatrix(space);
 		if (matrix == NULL)
@@ -390,7 +390,7 @@ namespace dpx {
 		}
 	}
 
-	template <typename DATA, int max>
+	template <typename DATA, unsigned int max>
 	static inline void ConvertPixelRGBToYCbCr(const DATA RGB[3], DATA CbYCr[3], const float matrix[9]) {
 		float tmp;
 		for (int i = 0; i < 3; i++) {
@@ -407,7 +407,7 @@ namespace dpx {
 	}
 
 	// 4:4:4
-	template <typename DATA, int max>
+	template <typename DATA, unsigned int max>
 	static bool ConvertRGBToCbYCr(const Characteristic space, const DATA *input, DATA *output, const int pixels) {
 		const float *matrix = GetRGBToYCbCrColorMatrix(space);
 		if (matrix == NULL)
@@ -421,7 +421,7 @@ namespace dpx {
 	}
 
 	// 4:4:4:4
-	template <typename DATA, int max>
+	template <typename DATA, unsigned int max>
 	static bool ConvertRGBAToCbYCrA(const Characteristic space, const DATA *input, DATA *output, const int pixels) {
 		const float *matrix = GetRGBToYCbCrColorMatrix(space);
 		if (matrix == NULL)
@@ -436,7 +436,7 @@ namespace dpx {
 	}
 
 	// 4:2:2
-	template <typename DATA, int max>
+	template <typename DATA, unsigned int max>
 	static bool ConvertRGBToCbYCrY(const Characteristic space, const DATA *input, DATA *output, const int pixels) {
 		const float *matrix = GetRGBToYCbCrColorMatrix(space);
 		if (matrix == NULL)
@@ -454,7 +454,7 @@ namespace dpx {
 	}
 
 	// 4:2:2:4
-	template <typename DATA, int max>
+	template <typename DATA, unsigned int max>
 	static bool ConvertRGBAToCbYACrYA(const Characteristic space, const DATA *input, DATA *output, const int pixels) {
 		const float *matrix = GetRGBToYCbCrColorMatrix(space);
 		if (matrix == NULL)
