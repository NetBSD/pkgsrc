$NetBSD: patch-libstdc++-v3_libsupc++_new__opa.cc,v 1.1 2022/06/16 15:43:55 adam Exp $

Ensure we can find SunOS std::aligned_alloc if using it.

--- libstdc++-v3/libsupc++/new_opa.cc.orig	2020-03-04 08:30:03.000000000 +0000
+++ libstdc++-v3/libsupc++/new_opa.cc
@@ -57,6 +57,10 @@ extern "C"
 }
 #endif
 
+#if defined(__sun) && _GLIBCXX_HAVE_ALIGNED_ALLOC
+using std::aligned_alloc;
+#endif
+
 namespace __gnu_cxx {
 #if _GLIBCXX_HAVE_ALIGNED_ALLOC
 using ::aligned_alloc;
