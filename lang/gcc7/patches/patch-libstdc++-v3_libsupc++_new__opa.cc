$NetBSD: patch-libstdc++-v3_libsupc++_new__opa.cc,v 1.3 2019/01/05 00:39:13 adam Exp $

Ensure we can find SunOS std::aligned_alloc if using it.

--- libstdc++-v3/libsupc++/new_opa.cc.orig	2019-01-04 10:50:16.000000000 +0000
+++ libstdc++-v3/libsupc++/new_opa.cc
@@ -42,6 +42,10 @@ extern "C" void *memalign(std::size_t bo
 using std::new_handler;
 using std::bad_alloc;
 
+#if defined(__sun) && _GLIBCXX_HAVE_ALIGNED_ALLOC
+using std::aligned_alloc;
+#endif
+
 namespace __gnu_cxx {
 #if _GLIBCXX_HAVE_ALIGNED_ALLOC
 using ::aligned_alloc;
