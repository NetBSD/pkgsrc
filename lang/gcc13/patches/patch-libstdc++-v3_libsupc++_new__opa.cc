$NetBSD: patch-libstdc++-v3_libsupc++_new__opa.cc,v 1.2 2024/06/07 10:28:55 adam Exp $

Ensure we can find SunOS std::aligned_alloc if using it.

--- libstdc++-v3/libsupc++/new_opa.cc.orig	2024-05-21 07:47:42.000000000 +0000
+++ libstdc++-v3/libsupc++/new_opa.cc
@@ -62,6 +62,10 @@ extern "C"
 }
 #endif
 
+#if defined(__sun) && _GLIBCXX_HAVE_ALIGNED_ALLOC
+using std::aligned_alloc;
+#endif
+
 namespace __gnu_cxx {
 // Prefer posix_memalign if available, because it's older than aligned_alloc
 // and so more likely to be provided by replacement malloc libraries that
