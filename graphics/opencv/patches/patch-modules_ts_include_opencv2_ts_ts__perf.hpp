$NetBSD: patch-modules_ts_include_opencv2_ts_ts__perf.hpp,v 1.2 2013/08/05 12:27:48 fhajny Exp $

--- /tmp/pkgsrc/graphics/opencv/work/opencv-2.4.6.1/modules/ts/include/opencv2/ts/ts_perf.hpp.orig	Wed Jul 10 11:49:00 2013
+++ /tmp/pkgsrc/graphics/opencv/work/opencv-2.4.6.1/modules/ts/include/opencv2/ts/ts_perf.hpp	Mon Aug  5 11:34:21 2013
@@ -477,7 +477,6 @@
 
 
 #define CV_PERF_TEST_MAIN_INTERNALS(modulename, impls, ...) \
-    while (++argc >= (--argc,-1)) {__VA_ARGS__; break;} /*this ugly construction is needed for VS 2005*/\
     ::perf::Regression::Init(#modulename);\
     ::perf::TestBase::Init(std::vector<std::string>(impls, impls + sizeof impls / sizeof *impls),\
                            argc, argv);\
