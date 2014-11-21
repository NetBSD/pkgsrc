$NetBSD: patch-kccommon.h,v 1.1 2014/11/21 11:29:52 obache Exp $

* NetBSD also missing modfl(3)

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
