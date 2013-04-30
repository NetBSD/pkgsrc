$NetBSD: patch-xylib_cache.h,v 1.1 2013/04/30 22:26:29 joerg Exp $

--- xylib/cache.h.orig	2013-04-29 18:52:26.000000000 +0000
+++ xylib/cache.h
@@ -28,7 +28,10 @@
 #define XYLIB_USE_TR1_MEMORY 1
 #endif
 
-#if XYLIB_USE_TR1_MEMORY
+#if defined(_LIBCPP_VERSION)
+# include <memory>
+using std::shared_ptr;
+#elif XYLIB_USE_TR1_MEMORY
 # include <tr1/memory>
   using std::tr1::shared_ptr;
 #else
