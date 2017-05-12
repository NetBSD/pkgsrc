$NetBSD: patch-libstdc++-v3_libsupc++_new__opa.cc,v 1.2 2017/05/12 18:10:56 jperkin Exp $

Ensure we can find SunOS std::aligned_alloc if using it.

--- libstdc++-v3/libsupc++/new_opa.cc.orig	2017-01-26 14:30:45.000000000 +0000
+++ libstdc++-v3/libsupc++/new_opa.cc
@@ -31,6 +31,10 @@
 using std::new_handler;
 using std::bad_alloc;
 
+#if defined(__sun) && _GLIBCXX_HAVE_ALIGNED_ALLOC
+using std::aligned_alloc;
+#endif
+
 #if !_GLIBCXX_HAVE_ALIGNED_ALLOC
 #if _GLIBCXX_HAVE__ALIGNED_MALLOC
 #define aligned_alloc(al,sz) _aligned_malloc(sz,al)
