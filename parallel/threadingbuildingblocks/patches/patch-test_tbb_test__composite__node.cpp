$NetBSD: patch-test_tbb_test__composite__node.cpp,v 1.1 2022/05/16 17:09:50 jperkin Exp $

Avoid ambiguous function call.

--- test/tbb/test_composite_node.cpp.orig	2021-06-30 08:19:55.000000000 +0000
+++ test/tbb/test_composite_node.cpp
@@ -30,6 +30,7 @@
 #include <cmath>
 #include <vector>
 
+using std::pow;
 
 //! \file test_composite_node.cpp
 //! \brief Test for [flow_graph.composite_node] specification
