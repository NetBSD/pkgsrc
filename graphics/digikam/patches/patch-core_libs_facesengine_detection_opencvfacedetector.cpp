$NetBSD: patch-core_libs_facesengine_detection_opencvfacedetector.cpp,v 1.1 2020/05/24 06:09:39 markd Exp $

Build with recent opencv.  From ArchLinux.

--- core/libs/facesengine/detection/opencvfacedetector.cpp.orig	2019-11-03 09:04:00.000000000 +0000
+++ core/libs/facesengine/detection/opencvfacedetector.cpp
@@ -166,7 +166,7 @@ public:
      * of the region of interest of this cascade (still relative to whole image).
      * For frontal face cascades, returns the given parameter unchanged.
      */
-    cv::Rect faceROI(const CvRect& faceRect) const
+    cv::Rect faceROI(const cv::Rect faceRect) const
     {
         return cv::Rect(lround(faceRect.x + roi.x()      * faceRect.width),
                         lround(faceRect.y + roi.y()      * faceRect.height),
