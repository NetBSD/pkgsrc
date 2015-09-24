$NetBSD: patch-libs_config_test_boost__no__range__based__for.ipp,v 1.1 2015/09/24 23:02:54 tnn Exp $

This configure test goes into an infinite loop with GCC 5.2.0 at
optimization level -O2 when -std=c++11 is not selected.
-O0 makes it segfault instead which is more appropriate as it counts
as a test failure, but is still horribly broken.
The expected result for trying to compile with c++11 features when
c++11 is not enabled should arguably be a compile error.

--- libs/config/test/boost_no_range_based_for.ipp.orig	2015-08-04 11:44:49.000000000 +0000
+++ libs/config/test/boost_no_range_based_for.ipp
@@ -9,6 +9,10 @@
 //  TITLE:         C++11 ranged-based for statement unavailable
 //  DESCRIPTION:   The compiler does not support the C++11 range-based for statement
 
+#if defined(__GNUC__) && __GNUC__ == 5
+#pragma GCC optimize ("O0")
+#endif
+
 namespace boost_no_cxx11_range_based_for {
 
 int test()
