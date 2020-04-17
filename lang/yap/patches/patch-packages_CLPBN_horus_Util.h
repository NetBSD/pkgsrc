$NetBSD: patch-packages_CLPBN_horus_Util.h,v 1.3 2020/04/17 00:19:44 joerg Exp $

Fix C++ dialect.

--- packages/CLPBN/horus/Util.h.orig	2013-01-14 23:11:52.000000000 +0000
+++ packages/CLPBN/horus/Util.h
@@ -176,7 +176,7 @@ Util::apply_n_times (Params& v1, const P
 template <typename T> void
 Util::log (vector<T>& v)
 {
-  std::transform (v.begin(), v.end(), v.begin(), ::log);
+  std::transform (v.begin(), v.end(), v.begin(), std::pointer_to_unary_function<T,T>(std::log));
 }
 
 
@@ -184,7 +184,7 @@ Util::log (vector<T>& v)
 template <typename T> void
 Util::exp (vector<T>& v)
 {
-  std::transform (v.begin(), v.end(), v.begin(), ::exp);
+  std::transform (v.begin(), v.end(), v.begin(), std::pointer_to_unary_function<T,T>(std::exp));
 }
 
 
@@ -370,7 +370,7 @@ template <typename T>
 void operator^=(std::vector<T>& v, int iexp)
 {
   std::transform (v.begin(), v.end(), v.begin(),
-      std::bind2nd (ptr_fun<double, int, double> (std::pow), iexp));
+      std::bind2nd (ptr_fun<double, double, double> (std::pow), (double)iexp));
 }
 
 
