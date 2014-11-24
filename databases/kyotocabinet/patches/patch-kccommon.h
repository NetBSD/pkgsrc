$NetBSD: patch-kccommon.h,v 1.3 2014/11/24 07:05:49 obache Exp $

* NetBSD also missing modfl(3)
* XXX: (will be removed in future update).

--- kccommon.h.orig	2012-05-24 16:27:59.000000000 +0000
+++ kccommon.h
@@ -68,7 +68,7 @@ extern "C" {
 #define snprintf  _snprintf
 #endif
 
-#if defined(__CYGWIN__)
+#if defined(__CYGWIN__) || defined(__NetBSD__)
 inline long double modfl(long double val, long double* iptr) {
   double integ;
   double fract = std::modf(val, &integ);
@@ -82,7 +82,7 @@ using ::modfl;
 using ::snprintf;
 }
 
-#if __cplusplus > 199711L || defined(__GXX_EXPERIMENTAL_CXX0X__) || defined(_MSC_VER)
+#if __cplusplus > 199711L || defined(__GXX_EXPERIMENTAL_CXX0X__) || defined(_MSC_VER) || defined(_LIBCPP_VERSION)
 
 #include <unordered_map>
 #include <unordered_set>
