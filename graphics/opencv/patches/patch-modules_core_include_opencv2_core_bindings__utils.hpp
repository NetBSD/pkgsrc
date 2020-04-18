$NetBSD: patch-modules_core_include_opencv2_core_bindings__utils.hpp,v 1.1 2020/04/18 22:01:33 joerg Exp $

--- modules/core/include/opencv2/core/bindings_utils.hpp.orig	2020-04-18 02:33:26.310026773 +0000
+++ modules/core/include/opencv2/core/bindings_utils.hpp
@@ -5,6 +5,7 @@
 #ifndef OPENCV_CORE_BINDINGS_UTILS_HPP
 #define OPENCV_CORE_BINDINGS_UTILS_HPP
 
+#include <sstream>
 #include <opencv2/core/async.hpp>
 #include <opencv2/core/detail/async_promise.hpp>
 
