$NetBSD: patch-packages_CLPBN_horus_Util.h,v 1.1 2014/01/06 22:13:39 joerg Exp $

--- packages/CLPBN/horus/Util.h.orig	2014-01-06 14:34:17.000000000 +0000
+++ packages/CLPBN/horus/Util.h
@@ -370,7 +370,7 @@ template <typename T>
 void operator^=(std::vector<T>& v, int iexp)
 {
   std::transform (v.begin(), v.end(), v.begin(),
-      std::bind2nd (ptr_fun<double, int, double> (std::pow), iexp));
+      std::bind2nd (ptr_fun<double, double, double> (std::pow), (double)iexp));
 }
 
 
