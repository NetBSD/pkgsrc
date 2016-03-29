$NetBSD: patch-libkface_recognition-opencv-lbph_facerec_borrowed.cpp,v 1.2 2016/03/29 10:14:05 markd Exp $

opencv3 support. https://bugs.kde.org/show_bug.cgi?id=349601
opencv3.1 - https://git.reviewboard.kde.org/r/126833/ with test reversed

--- libkface/recognition-opencv-lbph/facerec_borrowed.cpp.orig	2015-09-03 21:22:44.000000000 +0000
+++ libkface/recognition-opencv-lbph/facerec_borrowed.cpp
@@ -36,6 +36,8 @@
  *
  * ============================================================ */
 
+#define QT_NO_EMIT
+
 #include "facerec_borrowed.h"
 
 // C++ includes
@@ -375,7 +377,11 @@ void LBPHFaceRecognizer::train(InputArra
     }
 }
 
+#if OPENCV_VERSION < OPENCV_MAKE_VERSION(3,1,0)
 void LBPHFaceRecognizer::predict(InputArray _src, int &minClass, double &minDist) const
+#else
+void LBPHFaceRecognizer::predict(cv::InputArray _src, cv::Ptr<cv::face::PredictCollector> collector, const int state) const
+#endif
 {
     if(m_histograms.empty())
     {
@@ -394,8 +400,12 @@ void LBPHFaceRecognizer::predict(InputAr
                                       m_grid_y,                                                          /* grid size y                 */
                                       true                                                               /* normed histograms           */
                                      );
+#if OPENCV_VERSION < OPENCV_MAKE_VERSION(3,1,0)
     minDist      = DBL_MAX;
     minClass     = -1;
+#else
+    collector->init((int)m_histograms.size(), state);
+#endif
 
     // This is the standard method
 
@@ -406,11 +416,19 @@ void LBPHFaceRecognizer::predict(InputAr
         {
             double dist = compareHist(m_histograms[sampleIdx], query, CV_COMP_CHISQR);
 
+#if OPENCV_VERSION < OPENCV_MAKE_VERSION(3,1,0)
             if((dist < minDist) && (dist < m_threshold))
             {
                 minDist  = dist;
                 minClass = m_labels.at<int>((int) sampleIdx);
             }
+#else
+            int label = m_labels.at<int>((int) sampleIdx);
+            if (!collector->emit(label, dist, state))
+            {
+                return;
+            }
+#endif
         }
     }
 
@@ -422,7 +440,7 @@ void LBPHFaceRecognizer::predict(InputAr
         // Create map "label -> vector of distances to all histograms for this label"
         std::map<int, std::vector<int> > distancesMap;
 
-        for(size_t sampleIdx = 0; sampleIdx < m_histograms.size(); sampleIdx++) 
+        for(size_t sampleIdx = 0; sampleIdx < m_histograms.size(); sampleIdx++)
         {
             double dist                 = compareHist(m_histograms[sampleIdx], query, CV_COMP_CHISQR);
             std::vector<int>& distances = distancesMap[m_labels.at<int>((int) sampleIdx)];
@@ -445,11 +463,18 @@ void LBPHFaceRecognizer::predict(InputAr
             double mean = sum / it->second.size();
             s          += QString("%1: %2 - ").arg(it->first).arg(mean);
 
+#if OPENCV_VERSION < OPENCV_MAKE_VERSION(3,1,0)
             if((mean < minDist) && (mean < m_threshold))
             {
                 minDist = mean;
                 minClass = it->first;
             }
+#else
+            if (!collector->emit(it->first, mean, state))
+            {
+                return;
+            }
+#endif
         }
 
         kDebug() << s;
@@ -462,7 +487,7 @@ void LBPHFaceRecognizer::predict(InputAr
         // map "label -> number of histograms"
         std::map<int, int> countMap;
 
-        for(size_t sampleIdx = 0; sampleIdx < m_histograms.size(); sampleIdx++) 
+        for(size_t sampleIdx = 0; sampleIdx < m_histograms.size(); sampleIdx++)
         {
             int label   = m_labels.at<int>((int) sampleIdx);
             double dist = compareHist(m_histograms[sampleIdx], query, CV_COMP_CHISQR);
@@ -480,7 +505,9 @@ void LBPHFaceRecognizer::predict(InputAr
             scoreMap[it->second]++;
         }
 
+#if OPENCV_VERSION < OPENCV_MAKE_VERSION(3,1,0)
         minDist = 0;
+#endif
         QString s("Nearest Neighbor score: ");
 
         for (std::map<int,int>::iterator it = scoreMap.begin(); it != scoreMap.end(); ++it)
@@ -488,17 +515,26 @@ void LBPHFaceRecognizer::predict(InputAr
             double score = double(it->second) / countMap.at(it->first);
             s           += QString("%1/%2 %3  ").arg(it->second).arg(countMap.at(it->first)).arg(score);
 
+#if OPENCV_VERSION < OPENCV_MAKE_VERSION(3,1,0)
             if (score > minDist)
             {
                 minDist  = score;
                 minClass = it->first;
             }
+#else
+            // large is better thus it is -score.
+            if (!collector->emit(it->first, -score, state))
+            {
+                return;
+            }
+#endif
         }
 
         kDebug() << s;
     }
 }
 
+#if OPENCV_VERSION < OPENCV_MAKE_VERSION(3,1,0)
 int LBPHFaceRecognizer::predict(InputArray _src) const
 {
     int    label;
@@ -506,6 +542,7 @@ int LBPHFaceRecognizer::predict(InputArr
     predict(_src, label, dummy);
     return label;
 }
+#endif
 
 // Static method ----------------------------------------------------
 
@@ -531,14 +568,16 @@ Ptr<LBPHFaceRecognizer> LBPHFaceRecogniz
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
