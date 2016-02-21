$NetBSD: patch-modules_objdetect_include_opencv_objdetect_detection__based__tracker.hpp,v 1.2 2016/02/21 14:10:46 fhajny Exp $

--- modules/objdetect/include/opencv2/objdetect/detection_based_tracker.hpp.orig	2015-12-18 15:02:16.000000000 +0000
+++ modules/objdetect/include/opencv2/objdetect/detection_based_tracker.hpp
@@ -46,7 +46,7 @@
 
 // After this condition removal update blacklist for bindings: modules/python/common.cmake
 #if defined(__linux__) || defined(LINUX) || defined(__APPLE__) || defined(__ANDROID__) || \
-  (defined(__cplusplus) &&  __cplusplus > 201103L) || (defined(_MSC_VER) && _MSC_VER >= 1700)
+  (defined(__cplusplus) &&  __cplusplus >= 201103L) || (defined(_MSC_VER) && _MSC_VER >= 1700)
 
 #include <vector>
 
