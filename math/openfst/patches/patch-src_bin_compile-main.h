$NetBSD: patch-src_bin_compile-main.h,v 1.1 2013/05/06 14:53:16 joerg Exp $

--- src/bin/compile-main.h.orig	2013-05-03 17:26:20.000000000 +0000
+++ src/bin/compile-main.h
@@ -22,8 +22,15 @@
 #ifndef FST_COMPILE_MAIN_H__
 #define FST_COMPILE_MAIN_H__
 
+#include <ciso646>
+
+#if defined(_LIBCPP_VERSION) || __cplusplus >= 201103L
+#include <unordered_map>
+using std::unordered_map;
+#else
 #include <tr1/unordered_map>
 using std::tr1::unordered_map;
+#endif
 #include <sstream>
 #include <string>
 #include <vector>
