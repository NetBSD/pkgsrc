$NetBSD: patch-src_include_OpenImageIO_imagebufalgo.h,v 1.1 2017/03/17 23:40:13 markd Exp $

Build with opencv 3.2

--- src/include/OpenImageIO/imagebufalgo.h.orig	2015-06-11 17:25:58.000000000 +0000
+++ src/include/OpenImageIO/imagebufalgo.h
@@ -48,7 +48,7 @@
 
 #include <limits>
 
-#ifndef __OPENCV_CORE_TYPES_H__
+#if !defined(__OPENCV_CORE_TYPES_H__) && !defined(OPENCV_CORE_TYPES_H)
 struct IplImage;  // Forward declaration; used by Intel Image lib & OpenCV
 #endif
 
