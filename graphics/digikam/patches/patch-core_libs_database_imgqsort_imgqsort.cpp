$NetBSD: patch-core_libs_database_imgqsort_imgqsort.cpp,v 1.1 2015/11/03 20:47:48 markd Exp $

opencv3 support. https://bugs.kde.org/show_bug.cgi?id=349601

--- core/libs/database/imgqsort/imgqsort.cpp.orig	2015-09-03 21:22:45.000000000 +0000
+++ core/libs/database/imgqsort/imgqsort.cpp
@@ -282,10 +282,15 @@ void ImgQSort::readImage() const
 
     MixerFilter mixer(&d->image, 0L, settings);
     mixer.startFilterDirectly();
-
     d->image.putImageData(mixer.getTargetImage().bits());
+
+#if OPENCV_TEST_VERSION(3,0,0)
     d->src      = cvCreateMat(d->image.numPixels(), 3, CV_8UC3); // Create a matrix containing the pixel values of original image
     d->src_gray = cvCreateMat(d->image.numPixels(), 1, CV_8UC1); // Create a matrix containing the pixel values of grayscaled image
+#else
+    d->src      = Mat(d->image.numPixels(), 3, CV_8UC3); // Create a matrix containing the pixel values of original image
+    d->src_gray = Mat(d->image.numPixels(), 1, CV_8UC1); // Create a matrix containing the pixel values of grayscaled image
+#endif
 
     if (d->imq.detectNoise)
     {
@@ -655,7 +660,12 @@ int ImgQSort::compressiondetector() cons
     int countblocks      = 0;
     int number_of_blocks = 0;
     int sum              = 0;
+
+#if OPENCV_TEST_VERSION(3,0,0)
     vector<int> average_bottom, average_middle, average_top;
+#else
+    std::vector<int> average_bottom, average_middle, average_top;
+#endif
 
     // Go through 8 blocks at a time horizontally
     // iterating through columns.
@@ -792,7 +802,13 @@ int ImgQSort::compressiondetector() cons
 int ImgQSort::exposureamount() const
 {
     /// Separate the image in 3 places ( B, G and R )
+
+#if OPENCV_TEST_VERSION(3,0,0)
     vector<Mat> bgr_planes;
+#else
+    std::vector<Mat> bgr_planes;
+#endif
+
     split(d->src, bgr_planes);
 
     /// Establish the number of bins
