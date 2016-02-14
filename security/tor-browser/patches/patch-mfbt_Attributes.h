$NetBSD: patch-mfbt_Attributes.h,v 1.1 2016/02/14 07:30:54 ryoon Exp $

--- mfbt/Attributes.h.orig	2015-05-04 00:43:30.000000000 +0000
+++ mfbt/Attributes.h
@@ -50,6 +50,7 @@
  * don't indicate support for them here, due to
  * http://stackoverflow.com/questions/20498142/visual-studio-2013-explicit-keyword-bug
  */
+#  define MOZ_HAVE_CXX11_ALIGNAS
 #  define MOZ_HAVE_NEVER_INLINE          __declspec(noinline)
 #  define MOZ_HAVE_NORETURN              __declspec(noreturn)
 #  ifdef __clang__
@@ -70,6 +71,9 @@
 #  ifndef __has_extension
 #    define __has_extension __has_feature /* compatibility, for older versions of clang */
 #  endif
+#  if __has_extension(cxx_alignas)
+#    define MOZ_HAVE_CXX11_ALIGNAS
+#  endif
 #  if __has_extension(cxx_constexpr)
 #    define MOZ_HAVE_CXX11_CONSTEXPR
 #  endif
@@ -84,6 +88,9 @@
 #  endif
 #elif defined(__GNUC__)
 #  if defined(__GXX_EXPERIMENTAL_CXX0X__) || __cplusplus >= 201103L
+#    if MOZ_GCC_VERSION_AT_LEAST(4, 8, 0)
+#      define MOZ_HAVE_CXX11_ALIGNAS
+#    endif
 #      define MOZ_HAVE_CXX11_CONSTEXPR
 #      define MOZ_HAVE_EXPLICIT_CONVERSION
 #  endif
