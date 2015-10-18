$NetBSD: patch-src_tools_tca__correct.cpp,v 1.1 2015/10/18 15:56:56 adam Exp $

Avoid conflict with another variable called 'lock'.

--- src/tools/tca_correct.cpp.orig	2015-06-20 19:58:52.000000000 +0000
+++ src/tools/tca_correct.cpp
@@ -465,7 +465,7 @@ static void usage(const char* name)
          << "    commandline arguments for fulla" << endl;
 }
 
-static hugin_omp::Lock lock;
+static hugin_omp::Lock mylock;
 typedef std::multimap<double, vigra::Diff2D> MapPoints;
 
 template <class ImageType>
@@ -584,7 +584,7 @@ void createCtrlPoints(Panorama& pano, co
         }
         if (!cps.empty())
         {
-            hugin_omp::ScopedLock sl(lock);
+            hugin_omp::ScopedLock sl(mylock);
             for (CPVector::const_iterator it = cps.begin(); it != cps.end(); ++it)
             {
                 pano.addCtrlPoint(*it);
