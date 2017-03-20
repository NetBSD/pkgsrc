$NetBSD: patch-deps_v8__inspector_third__party_v8__inspector_platform_v8__inspector_PlatformSTL.h,v 1.1 2017/03/20 16:51:42 jperkin Exp $

Support GCC 4.8+.

--- deps/v8_inspector/third_party/v8_inspector/platform/v8_inspector/PlatformSTL.h.orig	2017-02-22 00:40:24.000000000 +0000
+++ deps/v8_inspector/third_party/v8_inspector/platform/v8_inspector/PlatformSTL.h
@@ -23,7 +23,7 @@ inline void USE(T) { }
 #define DEFINE_STATIC_LOCAL(type, name, arguments) \
     static type name;
 
-#if defined(__APPLE__) && !defined(_LIBCPP_VERSION)
+#if defined(__APPLE__) && !defined(_LIBCPP_VERSION) && (!defined(__GNUC__) || (__GNUC__ <= 4 && __GNUC_MINOR__ < 8))
 
 namespace std {
 
