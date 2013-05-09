$NetBSD: patch-unit-tests_googletest_include_gtest_internal_gtest-port.h,v 1.3 2013/05/09 20:05:35 joerg Exp $

--- unit-tests/googletest/include/gtest/internal/gtest-port.h.orig	2013-05-07 19:58:35.000000000 +0000
+++ unit-tests/googletest/include/gtest/internal/gtest-port.h
@@ -173,6 +173,7 @@
 #include <stdlib.h>
 #include <stdio.h>
 #include <string.h>
+#include <unistd.h>
 #ifndef _WIN32_WCE
 #include <sys/stat.h>
 #endif  // !_WIN32_WCE
@@ -432,6 +432,16 @@
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
