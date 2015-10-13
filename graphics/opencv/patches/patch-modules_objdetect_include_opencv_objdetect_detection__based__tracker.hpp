$NetBSD: patch-modules_objdetect_include_opencv_objdetect_detection__based__tracker.hpp,v 1.1 2015/10/13 14:37:43 joerg Exp $

--- modules/objdetect/include/opencv2/objdetect/detection_based_tracker.hpp.orig	2015-10-13 12:31:00.000000000 +0000
+++ modules/objdetect/include/opencv2/objdetect/detection_based_tracker.hpp
@@ -45,7 +45,7 @@
 #define __OPENCV_OBJDETECT_DBT_HPP__
 
 #if defined(__linux__) || defined(LINUX) || defined(__APPLE__) || defined(__ANDROID__) || \
-  (defined(__cplusplus) &&  __cplusplus > 201103L) || (defined(_MSC_VER) && _MSC_VER >= 1700)
+  (defined(__cplusplus) &&  __cplusplus >= 201103L) || (defined(_MSC_VER) && _MSC_VER >= 1700)
 
 #include <vector>
 
