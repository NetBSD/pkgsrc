$NetBSD: patch-src_tools_tca__correct.cpp,v 1.2 2016/04/07 19:23:26 adam Exp $

Avoid conflict with another variable called 'lock'.

--- src/tools/tca_correct.cpp.orig	2016-02-19 22:03:11.000000000 +0000
+++ src/tools/tca_correct.cpp
@@ -449,7 +449,7 @@ static void usage(const char* name)
          << "    commandline arguments for fulla" << std::endl;
 }
 
-static hugin_omp::Lock lock;
+static hugin_omp::Lock mylock;
 typedef std::multimap<double, vigra::Diff2D> MapPoints;
 
 template <class ImageType>
@@ -567,7 +567,7 @@ void createCtrlPoints(HuginBase::Panoram
         }
         if (!cps.empty())
         {
-            hugin_omp::ScopedLock sl(lock);
+            hugin_omp::ScopedLock sl(mylock);
             for (HuginBase::CPVector::const_iterator it = cps.begin(); it != cps.end(); ++it)
             {
                 pano.addCtrlPoint(*it);
