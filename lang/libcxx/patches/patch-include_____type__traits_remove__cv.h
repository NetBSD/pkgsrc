$NetBSD: patch-include_____type__traits_remove__cv.h,v 1.1 2023/12/18 17:48:42 jperkin Exp $

GCC 13 build fix.

--- include/__type_traits/remove_cv.h.orig	2023-12-18 17:44:16.264527380 +0000
+++ include/__type_traits/remove_cv.h
@@ -19,7 +19,7 @@
 
 _LIBCPP_BEGIN_NAMESPACE_STD
 
-#if __has_builtin(__remove_cv)
+#if __has_builtin(__remove_cv) && !defined(_LIBCPP_COMPILER_GCC)
 template <class _Tp>
 struct remove_cv {
   using type _LIBCPP_NODEBUG = __remove_cv(_Tp);
