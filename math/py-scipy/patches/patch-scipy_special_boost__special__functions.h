$NetBSD: patch-scipy_special_boost__special__functions.h,v 1.3 2026/01/11 08:15:05 adam Exp $

Fix build.

--- scipy/special/boost_special_functions.h.orig	2026-01-10 17:57:13.000000000 +0000
+++ scipy/special/boost_special_functions.h
@@ -47,6 +47,7 @@ boost::math::policies::user_evaluation_e
     return val;
 }
 
+using std::isnan;
 
 template <class RealType>
 RealType
