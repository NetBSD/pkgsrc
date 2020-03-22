$NetBSD: patch-src_libOpenImageIO_imagebufalgo__opencv.cpp,v 1.1 2020/03/22 21:24:24 joerg Exp $

--- src/libOpenImageIO/imagebufalgo_opencv.cpp.orig	2020-03-22 19:49:46.854776697 +0000
+++ src/libOpenImageIO/imagebufalgo_opencv.cpp
@@ -68,17 +68,17 @@ ImageBufAlgo::from_IplImage (ImageBuf &d
 #ifdef USE_OPENCV
     TypeDesc srcformat;
     switch (ipl->depth) {
-    case int(IPL_DEPTH_8U) :
+    case IPL_DEPTH_8U :
         srcformat = TypeDesc::UINT8;  break;
-    case int(IPL_DEPTH_8S) :
+    case IPL_DEPTH_8S :
         srcformat = TypeDesc::INT8;  break;
-    case int(IPL_DEPTH_16U) :
+    case IPL_DEPTH_16U :
         srcformat = TypeDesc::UINT16;  break;
-    case int(IPL_DEPTH_16S) :
+    case IPL_DEPTH_16S :
         srcformat = TypeDesc::INT16;  break;
-    case int(IPL_DEPTH_32F) :
+    case IPL_DEPTH_32F :
         srcformat = TypeDesc::FLOAT;  break;
-    case int(IPL_DEPTH_64F) :
+    case IPL_DEPTH_64F :
         srcformat = TypeDesc::DOUBLE;  break;
     default:
         DASSERT (0 && "unknown IplImage type");
