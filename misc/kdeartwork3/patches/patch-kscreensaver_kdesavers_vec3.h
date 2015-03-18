$NetBSD: patch-kscreensaver_kdesavers_vec3.h,v 1.1 2015/03/18 10:27:54 joerg Exp $

--- kscreensaver/kdesavers/vec3.h.orig	2015-03-17 22:44:04.000000000 +0000
+++ kscreensaver/kdesavers/vec3.h
@@ -148,7 +148,9 @@ inline vec3<T>::vec3(const std::slice_ar
 template<typename T>
 inline vec3<T> operator+(vec3<T> a, const vec3<T>& b)
 {
-   a += b;   /* valarray<T>::operator+=(const valarray<T>&) */
+   std::valarray<T> &a_ = a;
+   const std::valarray<T> &b_ = b;
+   a_ += b_;   /* valarray<T>::operator+=(const valarray<T>&) */
    return a;
 }
 
@@ -158,7 +160,9 @@ inline vec3<T> operator+(vec3<T> a, cons
 template<typename T>
 inline T operator*(vec3<T> a, const vec3<T>& b)
 {
-   a *= b;   /* valarray<T>::operator*=(const T&) */
+   std::valarray<T> &a_ = a;
+   const std::valarray<T> &b_ = b;
+   a_ *= b_;   /* valarray<T>::operator*=(const valarray<T>&) */
    return a.sum();
 }
 
