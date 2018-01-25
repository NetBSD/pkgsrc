$NetBSD: patch-tools_gtest-1.6.0_include_gtest_internal_gtest-port.h,v 1.3 2018/01/25 14:13:22 tnn Exp $

--- ext/gtest/include/gtest/internal/gtest-port.h.orig	2011-05-07 02:25:30.000000000 +0000
+++ ext/gtest/include/gtest/internal/gtest-port.h
@@ -481,6 +481,16 @@
 #  define BOOST_TR1_DETAIL_CONFIG_HPP_INCLUDED
 #  include <tuple>
 
+# elif __cplusplus >= 201103L
+#  include <tuple>
+namespace std {
+  namespace tr1 {
+    using ::std::tuple;
+    using ::std::tuple_element;
+    using ::std::tuple_size;
+    using ::std::get;
+  }
+}
 # elif defined(__GNUC__) && (GTEST_GCC_VER_ >= 40000)
 // GCC 4.0+ implements tr1/tuple in the <tr1/tuple> header.  This does
 // not conform to the TR1 spec, which requires the header to be <tuple>.
