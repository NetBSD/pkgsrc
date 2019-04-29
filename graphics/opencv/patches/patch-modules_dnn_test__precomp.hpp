$NetBSD: patch-modules_dnn_test__precomp.hpp,v 1.1 2019/04/29 03:23:53 mef Exp $

adhoc patch to build 3.4.6

[ 30%] Built target opencv_core
/export/WRKOBJDIR/graphics/opencv/work/opencv-3.4.6/build/modules/dnn/test_precomp.hpp:50:10: fatal error: test/test_common.hpp: No such file or directory
 #include "test/test_common.hpp"
          ^~~~~~~~~~~~~~~~~~~~~~
compilation terminated.

--- build/modules/dnn/test_precomp.hpp.orig	2019-04-29 10:35:50.011315095 +0900
+++ modules/dnn/test/test_precomp.hpp	2019-04-29 11:11:41.277591395 +0900
@@ -47,6 +47,6 @@
 #include "opencv2/core/ocl.hpp"
 
 #include "opencv2/dnn.hpp"
-#include "test_common.hpp"
+#include "../test/test_common.hpp"
 
 #endif
