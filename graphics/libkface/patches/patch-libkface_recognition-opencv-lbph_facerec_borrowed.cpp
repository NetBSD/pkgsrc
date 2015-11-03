$NetBSD: patch-libkface_recognition-opencv-lbph_facerec_borrowed.cpp,v 1.1 2015/11/03 20:28:57 markd Exp $

opencv3 support. https://bugs.kde.org/show_bug.cgi?id=349601

--- libkface/recognition-opencv-lbph/facerec_borrowed.cpp.orig	2015-09-03 21:22:44.000000000 +0000
+++ libkface/recognition-opencv-lbph/facerec_borrowed.cpp
@@ -531,14 +531,16 @@ Ptr<LBPHFaceRecognizer> LBPHFaceRecogniz
     return ptr;
 }
 
-CV_INIT_ALGORITHM(LBPHFaceRecognizer, "FaceRecognizer.LBPH-KFaceIface",
-                  obj.info()->addParam(obj, "radius",     obj.m_radius);
-                  obj.info()->addParam(obj, "neighbors",  obj.m_neighbors);
-                  obj.info()->addParam(obj, "grid_x",     obj.m_grid_x);
-                  obj.info()->addParam(obj, "grid_y",     obj.m_grid_y);
-                  obj.info()->addParam(obj, "threshold",  obj.m_threshold);
-                  obj.info()->addParam(obj, "histograms", obj.m_histograms);         // modification: Make Read/Write
-                  obj.info()->addParam(obj, "labels",     obj.m_labels);             // modification: Make Read/Write
-                  obj.info()->addParam(obj, "statistic",  obj.m_statisticsMode));    // modification: Add parameter
+#if OPENCV_VERSION <= OPENCV_MAKE_VERSION(2,4,11)
+    CV_INIT_ALGORITHM(LBPHFaceRecognizer, "FaceRecognizer.LBPH-KFaceIface",
+                      obj.info()->addParam(obj, "radius",     obj.m_radius);
+                      obj.info()->addParam(obj, "neighbors",  obj.m_neighbors);
+                      obj.info()->addParam(obj, "grid_x",     obj.m_grid_x);
+                      obj.info()->addParam(obj, "grid_y",     obj.m_grid_y);
+                      obj.info()->addParam(obj, "threshold",  obj.m_threshold);
+                      obj.info()->addParam(obj, "histograms", obj.m_histograms);         // modification: Make Read/Write
+                      obj.info()->addParam(obj, "labels",     obj.m_labels);             // modification: Make Read/Write
+                      obj.info()->addParam(obj, "statistic",  obj.m_statisticsMode));    // modification: Add parameter
+#endif
 
 } // namespace KFaceIface
