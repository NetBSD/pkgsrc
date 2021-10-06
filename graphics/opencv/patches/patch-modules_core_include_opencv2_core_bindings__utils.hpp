$NetBSD: patch-modules_core_include_opencv2_core_bindings__utils.hpp,v 1.2 2021/10/06 21:10:24 adam Exp $

--- modules/core/include/opencv2/core/bindings_utils.hpp.orig	2021-07-04 21:10:13.000000000 +0000
+++ modules/core/include/opencv2/core/bindings_utils.hpp
@@ -5,6 +5,7 @@
 #ifndef OPENCV_CORE_BINDINGS_UTILS_HPP
 #define OPENCV_CORE_BINDINGS_UTILS_HPP
 
+#include <sstream>
 #include <opencv2/core/async.hpp>
 #include <opencv2/core/detail/async_promise.hpp>
 #include <opencv2/core/utils/logger.hpp>
