$NetBSD: patch-libstdc++-v3_src_c++11_shared_ptr.cc,v 1.1 2022/12/10 10:44:59 js Exp $

--- libstdc++-v3/src/c++11/shared_ptr.cc.orig	2021-07-28 06:55:09.336315933 +0000
+++ libstdc++-v3/src/c++11/shared_ptr.cc
@@ -35,7 +35,11 @@ namespace __gnu_internal _GLIBCXX_VISIBI
   get_mutex(unsigned char i)
   {
     // increase alignment to put each lock on a separate cache line
-    struct alignas(64) M : __gnu_cxx::__mutex { };
+    struct
+#ifndef __DJGPP__
+      alignas(64)
+#endif
+      M : __gnu_cxx::__mutex { };
     static M m[mask + 1];
     return m[i];
   }
