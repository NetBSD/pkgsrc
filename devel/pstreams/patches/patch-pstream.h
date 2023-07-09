$NetBSD: patch-pstream.h,v 1.3 2023/07/09 14:56:58 nia Exp $

Fix building with older C++ compilers which do not understand
__has_cpp_attribute.

--- pstream.h.orig	2020-06-10 19:30:50.000000000 +0000
+++ pstream.h
@@ -1642,10 +1642,12 @@ namespace redi
    *  No longer used.
    */
   template <typename C, typename T>
-#if __cplusplus >= 201402L && __has_cpp_attribute(deprecated)
-    [[deprecated]]
-#elif __GNUC__
+#if defined(__GNUC__)
     __attribute__((deprecated))
+#elif defined(__cplusplus) && __cplusplus >= 201402L
+#if __has_cpp_attribute(deprecated)
+    [[deprecated]]
+#endif
 #endif
     inline void
     basic_pstreambuf<C,T>::init_rbuffers()
