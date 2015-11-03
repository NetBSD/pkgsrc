$NetBSD: patch-core_tests_imgqsort_detectblur_detectblur.cpp,v 1.2 2015/11/03 20:47:48 markd Exp $

--- core/tests/imgqsort/detectblur/detectblur.cpp.orig	2014-11-17 15:36:48.000000000 +0000
+++ core/tests/imgqsort/detectblur/detectblur.cpp
@@ -53,7 +53,7 @@ void CannyThreshold(int, void*)
     blur( src_gray, detected_edges, Size(3,3) );
 
     // Canny detector
-    Canny( detected_edges, detected_edges, lowThreshold, lowThreshold*ratio_value, kernel_size );
+    Canny( detected_edges, detected_edges, lowThreshold, lowThreshold*::ratio_value, kernel_size );
 
     // Using Canny's output as a mask, we display our result
     dst = Scalar::all(0);
