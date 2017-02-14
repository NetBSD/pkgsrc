$NetBSD: patch-src_gmic.h,v 1.1 2017/02/14 21:29:01 joerg Exp $

--- src/gmic.h.orig	2015-12-24 22:27:45.000000000 +0000
+++ src/gmic.h
@@ -138,7 +138,7 @@ namespace cimg_library {
     CImg<T> *_data;                // Pointer to the first image of the list.
 
     // Destructor.
-    ~CImgList();
+    ~CImgList() {}
     // Empty constructor.
     CImgList():_width(0),_allocated_width(0),_data(0) {}
     // Use to allocate a new image list with specified dimension.
