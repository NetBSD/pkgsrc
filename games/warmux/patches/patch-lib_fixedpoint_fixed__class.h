$NetBSD: patch-lib_fixedpoint_fixed__class.h,v 1.1 2015/03/10 13:59:29 joerg Exp $

--- lib/fixedpoint/fixed_class.h.orig	2015-03-09 22:46:53.000000000 +0000
+++ lib/fixedpoint/fixed_class.h
@@ -77,7 +77,7 @@ struct fixed_point {
   /*explicit*/ fixed_point(float f) : intValue(float2fix<p>(f)) {}
   /*explicit*/ fixed_point(double d) : intValue(float2fix<p>((float)d)) {}
   /*explicit*/ fixed_point(unsigned int u) : intValue(((fixint_t)u) << p) {}
-#if LONG_MAX != INT_MAX
+#if SIZE_MAX != INT_MAX
   /*explicit*/ fixed_point(size_t i) : intValue(((fixint_t)i) << p) {}
 #endif
 
