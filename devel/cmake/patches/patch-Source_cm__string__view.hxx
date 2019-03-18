$NetBSD: patch-Source_cm__string__view.hxx,v 1.1 2019/03/18 09:05:59 adam Exp $

<string_view> is not (yet) portable.

--- Source/cm_string_view.hxx.orig	2019-03-15 22:06:48.454327196 +0000
+++ Source/cm_string_view.hxx
@@ -5,9 +5,6 @@
 
 #include "cmConfigure.h" // IWYU pragma: keep
 
-#if __cplusplus >= 201703L || defined(_MSVC_LANG) && _MSVC_LANG >= 201703L
-#  define CMake_HAVE_CXX_STRING_VIEW
-#endif
 
 #ifdef CMake_HAVE_CXX_STRING_VIEW
 #  include <string_view>
