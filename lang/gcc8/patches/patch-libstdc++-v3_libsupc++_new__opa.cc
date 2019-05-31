$NetBSD: patch-libstdc++-v3_libsupc++_new__opa.cc,v 1.2 2019/05/31 09:23:57 kamil Exp $

Ensure we can find SunOS std::aligned_alloc if using it.

--- libstdc++-v3/libsupc++/new_opa.cc.orig	2018-08-08 15:33:36.000000000 +0000
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
