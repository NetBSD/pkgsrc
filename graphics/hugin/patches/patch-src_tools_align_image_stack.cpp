$NetBSD: patch-src_tools_align_image_stack.cpp,v 1.1 2015/10/18 15:56:56 adam Exp $

Avoid conflict with another variable called 'lock'.

--- src/tools/align_image_stack.cpp.orig	2015-06-20 19:13:37.000000000 +0000
+++ src/tools/align_image_stack.cpp
@@ -121,7 +121,7 @@ static void usage(const char* name)
 }
 
 typedef std::multimap<double, vigra::Diff2D> MapPoints;
-static hugin_omp::Lock lock;
+static hugin_omp::Lock mylock;
 
 template <class ImageType>
 void FineTuneInterestPoints(Panorama& pano,
@@ -193,7 +193,7 @@ void FineTuneInterestPoints(Panorama& pa
                        res.maxpos.y,
                        stereo ? ControlPoint::Y : ControlPoint::X_Y);
         {
-            hugin_omp::ScopedLock sl(lock);
+            hugin_omp::ScopedLock sl(mylock);
             pano.addCtrlPoint(p);
         };
     }
