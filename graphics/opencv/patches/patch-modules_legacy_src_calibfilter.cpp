$NetBSD: patch-modules_legacy_src_calibfilter.cpp,v 1.1 2014/05/27 09:57:21 joerg Exp $

--- modules/legacy/src/calibfilter.cpp.orig	2014-05-22 13:56:04.000000000 +0000
+++ modules/legacy/src/calibfilter.cpp
@@ -95,10 +95,12 @@ bool CvCalibFilter::SetEtalon( CvCalibEt
 
     Stop();
 
-    if (latestPoints != NULL)
+    for( i = 0; i < MAX_CAMERAS; i++ )
     {
-        for( i = 0; i < MAX_CAMERAS; i++ )
+        if (latestPoints[i] != NULL)
+        {
             cvFree( latestPoints + i );
+        }
     }
 
     if( type == CV_CALIB_ETALON_USER || type != etalonType )
@@ -529,7 +531,7 @@ void CvCalibFilter::DrawPoints( CvMat** 
         return;
     }
 
-    if( latestCounts )
+    if( 1 )
     {
         for( i = 0; i < cameraCount; i++ )
         {
