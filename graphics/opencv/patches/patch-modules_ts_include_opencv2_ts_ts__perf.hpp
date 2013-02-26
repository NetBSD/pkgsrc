$NetBSD: patch-modules_ts_include_opencv2_ts_ts__perf.hpp,v 1.1 2013/02/26 23:38:08 joerg Exp $

--- modules/ts/include/opencv2/ts/ts_perf.hpp.orig	2013-02-26 16:47:16.000000000 +0000
+++ modules/ts/include/opencv2/ts/ts_perf.hpp
@@ -478,7 +478,6 @@ CV_EXPORTS void PrintTo(const Size& sz, 
 #define CV_PERF_TEST_MAIN(testsuitname, ...) \
 int main(int argc, char **argv)\
 {\
-    while (++argc >= (--argc,-1)) {__VA_ARGS__; break;} /*this ugly construction is needed for VS 2005*/\
     ::perf::Regression::Init(#testsuitname);\
     ::perf::TestBase::Init(argc, argv);\
     ::testing::InitGoogleTest(&argc, argv);\
