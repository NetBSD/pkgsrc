$NetBSD: patch-src_include_fst_epsnormalize.h,v 1.1 2013/05/06 14:53:16 joerg Exp $

--- src/include/fst/epsnormalize.h.orig	2013-05-03 17:30:15.000000000 +0000
+++ src/include/fst/epsnormalize.h
@@ -20,8 +20,16 @@
 #ifndef FST_LIB_EPSNORMALIZE_H__
 #define FST_LIB_EPSNORMALIZE_H__
 
+#include <ciso646>
+
+#if defined(_LIBCPP_VERSION) || __cplusplus >= 201103L
+#include <unordered_map>
+using std::unordered_map;
+#else
 #include <tr1/unordered_map>
 using std::tr1::unordered_map;
+#endif
+
 #include <fst/slist.h>
 
 #include <fst/factor-weight.h>
