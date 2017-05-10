$NetBSD: patch-libstdc++-v3_libsupc++_new__opa.cc,v 1.1 2017/05/10 15:00:09 jperkin Exp $

Ensure we can find std::aligned_alloc if using it.

--- libstdc++-v3/libsupc++/new_opa.cc.orig	2017-01-26 14:30:45.000000000 +0000
+++ libstdc++-v3/libsupc++/new_opa.cc
@@ -82,6 +82,8 @@ aligned_alloc (std::size_t al, std::size
   return aligned_ptr;
 }
 #endif
+#else
+using std::aligned_alloc;
 #endif
 
 _GLIBCXX_WEAK_DEFINITION void *
