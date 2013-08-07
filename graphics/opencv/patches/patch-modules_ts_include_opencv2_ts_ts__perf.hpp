$NetBSD: patch-modules_ts_include_opencv2_ts_ts__perf.hpp,v 1.3 2013/08/07 13:01:20 fhajny Exp $

--- modules/ts/include/opencv2/ts/ts_perf.hpp.orig	2013-07-10 11:49:00.000000000 +0000
+++ modules/ts/include/opencv2/ts/ts_perf.hpp
@@ -477,7 +477,6 @@ CV_EXPORTS void PrintTo(const Size& sz,
 
 
 #define CV_PERF_TEST_MAIN_INTERNALS(modulename, impls, ...) \
-    while (++argc >= (--argc,-1)) {__VA_ARGS__; break;} /*this ugly construction is needed for VS 2005*/\
     ::perf::Regression::Init(#modulename);\
     ::perf::TestBase::Init(std::vector<std::string>(impls, impls + sizeof impls / sizeof *impls),\
                            argc, argv);\
