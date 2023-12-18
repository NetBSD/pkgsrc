$NetBSD: patch-.._libcxx-16.0.6.src_include_____type__traits_is__convertible.h,v 1.1 2023/12/18 17:32:36 jperkin Exp $

Backport GCC 13 fix.

--- ../libcxx-16.0.6.src/include/__type_traits/is_convertible.h.orig	2023-12-15 09:59:09.541570632 +0000
+++ ../libcxx-16.0.6.src/include/__type_traits/is_convertible.h
@@ -24,7 +24,12 @@
 
 _LIBCPP_BEGIN_NAMESPACE_STD
 
-#if __has_builtin(__is_convertible_to) && !defined(_LIBCPP_USE_IS_CONVERTIBLE_FALLBACK)
+#if __has_builtin(__is_convertible) && !defined(_LIBCPP_USE_IS_CONVERTIBLE_FALLBACK)
+
+template <class _T1, class _T2>
+struct _LIBCPP_TEMPLATE_VIS is_convertible : public integral_constant<bool, __is_convertible(_T1, _T2)> {};
+
+#elif __has_builtin(__is_convertible_to) && !defined(_LIBCPP_USE_IS_CONVERTIBLE_FALLBACK)
 
 template <class _T1, class _T2> struct _LIBCPP_TEMPLATE_VIS is_convertible
     : public integral_constant<bool, __is_convertible_to(_T1, _T2)> {};
