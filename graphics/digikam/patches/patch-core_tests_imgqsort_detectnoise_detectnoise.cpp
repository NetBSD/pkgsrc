$NetBSD: patch-core_tests_imgqsort_detectnoise_detectnoise.cpp,v 1.2 2015/11/03 20:47:48 markd Exp $

--- core/tests/imgqsort/detectnoise/detectnoise.cpp.orig	2014-11-17 15:37:46.000000000 +0000
+++ core/tests/imgqsort/detectnoise/detectnoise.cpp
@@ -48,7 +48,7 @@ void CannyThreshold(int, void*)
     blur( src_gray, detected_edges, Size(3,3) );
 
     // Canny detector
-    Canny( detected_edges, detected_edges, lowThreshold, lowThreshold*ratio_value, kernel_size );
+    Canny( detected_edges, detected_edges, lowThreshold, lowThreshold*::ratio_value, kernel_size );
 
     // Using Canny's output as a mask, we display our result
     dst = Scalar::all(0);
