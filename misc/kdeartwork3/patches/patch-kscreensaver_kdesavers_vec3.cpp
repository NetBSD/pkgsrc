$NetBSD: patch-kscreensaver_kdesavers_vec3.cpp,v 1.1 2015/03/18 10:27:54 joerg Exp $

--- kscreensaver/kdesavers/vec3.cpp.orig	2015-03-17 22:51:32.000000000 +0000
+++ kscreensaver/kdesavers/vec3.cpp
@@ -59,7 +59,9 @@ vec3<T>& vec3<T>::rotate(const vec3<T>& 
       // part of vector which is parallel to r
       vec3<T> par(r*(*this)/(r*r) * r);
       // part of vector which is perpendicular to r
-      vec3<T> perp(*this - par);
+      vec3<T> perp(*this);
+      std::valarray<T> &perp_ = perp;
+      perp -= std::valarray<T>(par);
       // rotation direction, size of perp
       vec3<T> rotdir(norm(perp) * normalized(crossprod(r,perp)));
       *this = par + cos(phi)*perp + sin(phi)*rotdir;
