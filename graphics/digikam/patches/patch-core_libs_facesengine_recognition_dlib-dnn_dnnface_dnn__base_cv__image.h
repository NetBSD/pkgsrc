$NetBSD: patch-core_libs_facesengine_recognition_dlib-dnn_dnnface_dnn__base_cv__image.h,v 1.1 2020/05/24 06:09:39 markd Exp $

Build with recent opencv.  From ArchLinux.

--- core/libs/facesengine/recognition/dlib-dnn/dnnface/dnn_base/cv_image.h.orig	2019-11-03 09:04:00.000000000 +0000
+++ core/libs/facesengine/recognition/dlib-dnn/dnnface/dnn_base/cv_image.h
@@ -52,7 +52,7 @@ public:
                      << "\n\t img.channels(): " << img.channels()
                      << "\n\t img.pixel_traits<pixel_type>::num: " << pixel_traits<pixel_type>::num
                      );
-        IplImage temp = img;
+        IplImage temp = cvIplImage(img);
         init(&temp);
     }
 
@@ -125,7 +125,7 @@ public:
 
     cv_image& operator=( const cv::Mat img)
     {
-        IplImage temp = img;
+        IplImage temp = cvIplImage(img);
         init(&temp);
         return *this;
     }
