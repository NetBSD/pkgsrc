$NetBSD: patch-src_tools_align_image_stack.cpp,v 1.2 2016/04/07 19:23:26 adam Exp $

Avoid conflict with another variable called 'lock'.

--- src/tools/align_image_stack.cpp.orig	2016-02-19 22:03:11.000000000 +0000
+++ src/tools/align_image_stack.cpp
@@ -113,7 +113,7 @@ static void usage(const char* name)
 }
 
 typedef std::multimap<double, vigra::Diff2D> MapPoints;
-static hugin_omp::Lock lock;
+static hugin_omp::Lock mylock;
 
 namespace detail
 {
@@ -202,7 +202,7 @@ void FineTuneInterestPoints(HuginBase::P
                        res.maxpos.y,
                        stereo ? HuginBase::ControlPoint::Y : HuginBase::ControlPoint::X_Y);
         {
-            hugin_omp::ScopedLock sl(lock);
+            hugin_omp::ScopedLock sl(mylock);
             pano.addCtrlPoint(p);
         };
     }
