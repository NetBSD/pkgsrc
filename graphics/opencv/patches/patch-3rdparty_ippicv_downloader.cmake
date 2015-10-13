$NetBSD: patch-3rdparty_ippicv_downloader.cmake,v 1.1 2015/10/13 14:37:43 joerg Exp $

--- 3rdparty/ippicv/downloader.cmake.orig	2015-10-13 13:00:47.000000000 +0000
+++ 3rdparty/ippicv/downloader.cmake
@@ -6,6 +6,7 @@
 #
 
 function(_icv_downloader)
+  return()
   # Define actual ICV versions
   if(APPLE)
     set(OPENCV_ICV_PACKAGE_NAME "ippicv_macosx_20141027.tgz")
