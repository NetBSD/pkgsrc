$NetBSD: patch-src_include_fst_encode.h,v 1.1 2013/05/06 14:53:16 joerg Exp $

--- src/include/fst/encode.h.orig	2013-05-03 17:23:12.000000000 +0000
+++ src/include/fst/encode.h
@@ -20,8 +20,15 @@
 #ifndef FST_LIB_ENCODE_H__
 #define FST_LIB_ENCODE_H__
 
+#include <ciso646>
+
+#if defined(_LIBCPP_VERSION) || __cplusplus >= 201103L
+#include <unordered_map>
+using std::unordered_map;
+#else
 #include <tr1/unordered_map>
 using std::tr1::unordered_map;
+#endif
 #include <string>
 #include <vector>
 #include <fst/map.h>
