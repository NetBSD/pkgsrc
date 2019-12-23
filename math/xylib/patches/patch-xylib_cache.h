$NetBSD: patch-xylib_cache.h,v 1.2 2019/12/23 19:54:51 nros Exp $

* use std::shared_prt on gcc 6 and above since they implicitly use c++14

--- xylib/cache.h.orig	2012-07-25 22:25:14.000000000 +0000
+++ xylib/cache.h
@@ -28,7 +28,16 @@
 #define XYLIB_USE_TR1_MEMORY 1
 #endif
 
-#if XYLIB_USE_TR1_MEMORY
+#ifdef __GNUC__
+#if __GNUC__ >= 6
+#define __GNU_V6__
+#endif
+#endif
+
+#if defined(_LIBCPP_VERSION) || defined(__GNU_V6__)
+# include <memory>
+using std::shared_ptr;
+#elif XYLIB_USE_TR1_MEMORY
 # include <tr1/memory>
   using std::tr1::shared_ptr;
 #else
