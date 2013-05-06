$NetBSD: patch-src_include_fst_equivalent.h,v 1.1 2013/05/06 14:53:16 joerg Exp $

--- src/include/fst/equivalent.h.orig	2013-05-03 17:31:26.000000000 +0000
+++ src/include/fst/equivalent.h
@@ -22,8 +22,15 @@
 
 #include <algorithm>
 #include <deque>
+#include <ciso646>
+
+#if defined(_LIBCPP_VERSION) || __cplusplus >= 201103L
+#include <unordered_map>
+using std::unordered_map;
+#else
 #include <tr1/unordered_map>
 using std::tr1::unordered_map;
+#endif
 #include <utility>
 #include <vector>
 #include <fst/encode.h>
