$NetBSD: patch-src_common.h,v 1.1 2014/02/24 12:35:10 wiedi Exp $

needs ieeefp.h for finite()
--- src/common.h.orig	2011-01-09 18:43:38.000000000 +0000
+++ src/common.h
@@ -19,6 +19,9 @@
 #include <math.h>
 #include <assert.h>
 #include <float.h> // DBL_MAX
+#if defined(__sun)
+#include <ieeefp.h>
+#endif
 
 #include "fityk.h" //ExecuteError
 using fityk::ExecuteError;
