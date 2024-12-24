$NetBSD: patch-libstdc++-v3_libsupc++_new__opa.cc,v 1.2 2024/12/24 14:15:50 mef Exp $

Ensure we can find SunOS std::aligned_alloc if using it.

--- libstdc++-v3/libsupc++/new_opa.cc.orig	2024-05-21 16:47:42.000000000 +0900
+++ libstdc++-v3/libsupc++/new_opa.cc	2024-12-24 22:22:57.962123061 +0900
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
