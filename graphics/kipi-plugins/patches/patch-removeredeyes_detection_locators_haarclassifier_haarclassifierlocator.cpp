$NetBSD: patch-removeredeyes_detection_locators_haarclassifier_haarclassifierlocator.cpp,v 1.1 2015/12/12 19:32:45 markd Exp $

opencv3 support. https://bugs.kde.org/show_bug.cgi?id=349601

--- removeredeyes/detection/locators/haarclassifier/haarclassifierlocator.cpp.orig	2015-09-03 21:22:45.000000000 +0000
+++ removeredeyes/detection/locators/haarclassifier/haarclassifierlocator.cpp
@@ -90,6 +90,15 @@ const QString HaarClassifierLocator::Pri
 
 // --------------------------------------------------------
 
+#if !(OPENCV_TEST_VERSION(2,5,0))
+
+static void cvFillImage(CvArr* const mat, double color)
+{
+    cvSet(mat, cvColorToScalar(color, cvGetElemType(mat)), 0);
+}
+
+#endif
+
 int HaarClassifierLocator::findPossibleEyes(double csf, int ngf, const char* classifierFile)
 {
     // eyes sequence will reside in the storage
