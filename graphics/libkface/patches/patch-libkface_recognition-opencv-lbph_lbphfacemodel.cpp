$NetBSD: patch-libkface_recognition-opencv-lbph_lbphfacemodel.cpp,v 1.1 2015/11/03 20:28:57 markd Exp $

opencv3 support. https://bugs.kde.org/show_bug.cgi?id=349601

--- libkface/recognition-opencv-lbph/lbphfacemodel.cpp.orig	2015-09-03 21:22:44.000000000 +0000
+++ libkface/recognition-opencv-lbph/lbphfacemodel.cpp
@@ -61,7 +61,11 @@ LBPHFaceModel::LBPHFaceModel()
     : cv::Ptr<LBPHFaceRecognizer>(LBPHFaceRecognizer::create()),
       databaseId(0)
 {
+#if OPENCV_TEST_VERSION(3,0,0)
+    ptr()->setThreshold(100.0);
+#else
     ptr()->set("threshold", 100.0);
+#endif
 }
 
 LBPHFaceModel::~LBPHFaceModel()
@@ -80,9 +84,13 @@ LBPHFaceRecognizer* LBPHFaceModel::ptr()
 
 const LBPHFaceRecognizer* LBPHFaceModel::ptr() const
 {
+#if OPENCV_TEST_VERSION(3,0,0)
+    const LBPHFaceRecognizer* const ptr = cv::Ptr<LBPHFaceRecognizer>::operator KFaceIface::LBPHFaceRecognizer*();
+#else
     const LBPHFaceRecognizer* const ptr = cv::Ptr<LBPHFaceRecognizer>::operator const KFaceIface::LBPHFaceRecognizer*();
+#endif
 
-    if (!ptr) 
+    if (!ptr)
         kWarning() << "LBPHFaceRecognizer pointer is null";
 
     return ptr;
@@ -90,47 +98,83 @@ const LBPHFaceRecognizer* LBPHFaceModel:
 
 int LBPHFaceModel::radius() const
 {
+#if OPENCV_TEST_VERSION(3,0,0)
+    return ptr()->getRadius();
+#else
     return ptr()->get<int>("radius");
+#endif
 }
 
 void LBPHFaceModel::setRadius(int radius)
 {
+#if OPENCV_TEST_VERSION(3,0,0)
+    ptr()->setRadius(radius);
+#else
     ptr()->set("radius", radius);
+#endif
 }
 
 int LBPHFaceModel::neighbors() const
 {
+#if OPENCV_TEST_VERSION(3,0,0)
+    return ptr()->getNeighbors();
+#else
     return ptr()->get<int>("neighbors");
+#endif
 }
 
 void LBPHFaceModel::setNeighbors(int neighbors)
 {
+#if OPENCV_TEST_VERSION(3,0,0)
+    ptr()->setNeighbors(neighbors);
+#else
     ptr()->set("neighbors", neighbors);
+#endif
 }
 
 int LBPHFaceModel::gridX() const
 {
+#if OPENCV_TEST_VERSION(3,0,0)
+    return ptr()->getGrid_x();
+#else
     return ptr()->get<int>("grid_x");
+#endif
 }
 
 void LBPHFaceModel::setGridX(int grid_x)
 {
+#if OPENCV_TEST_VERSION(3,0,0)
+    ptr()->setGrid_x(grid_x);
+#else
     ptr()->set("grid_x", grid_x);
+#endif
 }
 
 int LBPHFaceModel::gridY() const
 {
+#if OPENCV_TEST_VERSION(3,0,0)
+    return ptr()->getGrid_y();
+#else
     return ptr()->get<int>("grid_y");
+#endif
 }
 
 void LBPHFaceModel::setGridY(int grid_y)
 {
+#if OPENCV_TEST_VERSION(3,0,0)
+    ptr()->setGrid_y(grid_y);
+#else
     ptr()->set("grid_y", grid_y);
+#endif
 }
 
 OpenCVMatData LBPHFaceModel::histogramData(int index) const
 {
+#if OPENCV_TEST_VERSION(3,0,0)
+    return OpenCVMatData(ptr()->getHistograms().at(index));
+#else
     return OpenCVMatData(ptr()->get<std::vector<cv::Mat> >("histograms").at(index));
+#endif
 }
 
 QList<LBPHistogramMetadata> LBPHFaceModel::histogramMetadata() const
@@ -168,12 +212,24 @@ void LBPHFaceModel::setHistograms(const 
         m_histogramMetadata << metadata;
     }
 
+#if OPENCV_TEST_VERSION(3,0,0)
+    std::vector<cv::Mat> currentHistograms = ptr()->getHistograms();
+    cv::Mat currentLabels                  = ptr()->getLabels();
+#else
     std::vector<cv::Mat> currentHistograms = ptr()->get<std::vector<cv::Mat> >("histograms");
     cv::Mat currentLabels                  = ptr()->get<cv::Mat>("labels");
+#endif
+
     currentHistograms.insert(currentHistograms.end(), newHistograms.begin(), newHistograms.end());
     currentLabels.push_back(newLabels);
+
+#if OPENCV_TEST_VERSION(3,0,0)
+    ptr()->setHistograms(currentHistograms);
+    ptr()->setLabels(currentLabels);
+#else
     ptr()->set("histograms", currentHistograms);
-    ptr()->set("labels", currentLabels);
+    ptr()->set("labels",     currentLabels);
+#endif
 
 /*
     //Most cumbersome and inefficient way through a file storage which we were forced to use if we used standard OpenCV
@@ -215,7 +271,11 @@ void LBPHFaceModel::update(const std::ve
 
     // Update local information
     // We assume new labels are simply appended
+#if OPENCV_TEST_VERSION(3,0,0)
+    cv::Mat currentLabels = ptr()->getLabels();
+#else
     cv::Mat currentLabels = ptr()->get<cv::Mat>("labels");
+#endif
 
     for (int i = m_histogramMetadata.size() ; i < currentLabels.rows ; i++)
     {
