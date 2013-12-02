$NetBSD: patch-Imath_ImathFun.h,v 1.1 2013/12/02 23:39:09 bsiegert Exp $

--- Imath/ImathFun.h.orig	Thu Sep 19 17:07:20 2013
+++ Imath/ImathFun.h
@@ -48,6 +48,8 @@
 #include "ImathInt64.h"
 #include "ImathNamespace.h"
 
+#undef abs
+
 IMATH_INTERNAL_NAMESPACE_HEADER_ENTER
 
 template <class T>
