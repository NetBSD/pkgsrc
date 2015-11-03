$NetBSD: patch-libkface_detection_opencvfacedetector.cpp,v 1.1 2015/11/03 20:28:57 markd Exp $

opencv3 support. https://bugs.kde.org/show_bug.cgi?id=349601

--- libkface/detection/opencvfacedetector.cpp.orig	2015-09-03 21:22:44.000000000 +0000
+++ libkface/detection/opencvfacedetector.cpp
@@ -18,7 +18,7 @@
  *         <a href="alexjironkin at gmail dot com">alexjironkin at gmail dot com</a>
  * @author Copyright (C) 2010 by Aditya Bhatt
  *         <a href="adityabhatt at gmail dot com">adityabhatt at gmail dot com</a>
- * @author Copyright (C) 2010-2014 by Gilles Caulier
+ * @author Copyright (C) 2010-2015 by Gilles Caulier
  *         <a href="mailto:caulier dot gilles at gmail dot com">caulier dot gilles at gmail dot com</a>
  * @author Copyright (C) 2010-2013 by Marcel Wiesweg
  *         <a href="mailto:marcel dot wiesweg at gmx dot de">marcel dot wiesweg at gmx dot de</a>
@@ -136,13 +136,14 @@ public:
 
     cv::Size getOriginalWindowSize() const
     {
+#if OPENCV_VERSION <= OPENCV_MAKE_VERSION(2,4,11)
         // This is a HACK which may break any time. Work around the fact that getOriginalWindowSize()
         // always returns (0,0) and we need these values.
         if (oldCascade)
         {
             return oldCascade->orig_window_size;
         }
-
+#endif
         return cv::Size(0, 0);
     }
 
