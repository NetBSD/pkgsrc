$NetBSD: patch-v8-dtoa_platform.cc,v 1.1 2016/11/16 13:13:44 fhajny Exp $

fpclassify is defined on Illumos.

--- v8-dtoa/platform.cc.orig	2011-03-31 19:08:36.000000000 +0000
+++ v8-dtoa/platform.cc
@@ -111,6 +111,7 @@ int fpclassify(double x) {
 #endif  // _MSC_VER
 
 #ifdef SOLARIS
+#ifndef fpclassify
 
 #include <ieeefp.h>
 
@@ -134,4 +135,5 @@ int fpclassify(double x) {
   }
 
 }
+#endif fpclassify
 #endif // SOLARIS
