$NetBSD: patch-gtest_include_gtest_internal_gtest-port.h,v 1.1 2013/05/09 20:06:09 joerg Exp $

--- gtest/include/gtest/internal/gtest-port.h.orig	2012-04-03 17:43:13.000000000 +0000
+++ gtest/include/gtest/internal/gtest-port.h
@@ -36,6 +36,8 @@
 #ifndef GTEST_INCLUDE_GTEST_INTERNAL_GTEST_PORT_H_
 #define GTEST_INCLUDE_GTEST_INTERNAL_GTEST_PORT_H_
 
+#include <unistd.h>
+
 // The user can define the following macros in the build script to
 // control Google Test's behavior.  If the user doesn't define a macro
 // in this list, Google Test will define it.
@@ -415,6 +417,16 @@
 #define BOOST_TR1_DETAIL_CONFIG_HPP_INCLUDED
 #include <tuple>
 
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
 #elif defined(__GNUC__) && (GTEST_GCC_VER_ >= 40000)
 // GCC 4.0+ implements tr1/tuple in the <tr1/tuple> header.  This does
 // not conform to the TR1 spec, which requires the header to be <tuple>.
