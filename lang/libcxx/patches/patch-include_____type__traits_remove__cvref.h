$NetBSD: patch-include_____type__traits_remove__cvref.h,v 1.1 2023/12/18 17:48:42 jperkin Exp $

GCC 13 build fix.

--- include/__type_traits/remove_cvref.h.orig	2023-12-18 17:44:39.685649726 +0000
+++ include/__type_traits/remove_cvref.h
@@ -20,7 +20,7 @@
 
 _LIBCPP_BEGIN_NAMESPACE_STD
 
-#if __has_builtin(__remove_cvref)
+#if __has_builtin(__remove_cvref) && !defined(_LIBCPP_COMPILER_GCC)
 template <class _Tp>
 using __remove_cvref_t _LIBCPP_NODEBUG = __remove_cvref(_Tp);
 #else
