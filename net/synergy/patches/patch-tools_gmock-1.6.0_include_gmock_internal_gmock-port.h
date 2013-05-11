$NetBSD: patch-tools_gmock-1.6.0_include_gmock_internal_gmock-port.h,v 1.1 2013/05/11 21:40:14 joerg Exp $

--- tools/gmock-1.6.0/include/gmock/internal/gmock-port.h.orig	2011-05-07 02:25:30.000000000 +0000
+++ tools/gmock-1.6.0/include/gmock/internal/gmock-port.h
@@ -50,6 +50,14 @@
 // tr1/tuple.  gmock-port.h does this via gtest-port.h, which is
 // guaranteed to pull in the tuple header.
 
+#if __cplusplus >= 201103L
+namespace std {
+  namespace tr1 {
+    using ::std::make_tuple;
+  }
+}
+#endif
+
 // For MS Visual C++, check the compiler version. At least VS 2003 is
 // required to compile Google Mock.
 #if defined(_MSC_VER) && _MSC_VER < 1310
