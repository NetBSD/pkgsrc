$NetBSD: patch-src_qdjvuwidget.cpp,v 1.1 2012/02/16 04:44:26 ryoon Exp $

Avoid conflicted name, swap.

--- src/qdjvuwidget.cpp.orig	2011-08-17 14:24:20.000000000 +0000
+++ src/qdjvuwidget.cpp
@@ -153,7 +153,7 @@ all_numbers(const char *s)
 }
 
 template<class T> static inline void 
-swap(T& x, T& y)
+swap_(T& x, T& y)
 {
   T tmp;
   tmp = x;
@@ -173,11 +173,12 @@ ksmallest(T *v, int n, int k)
       /* Sort v[lo], v[m], v[hi] by insertion */
       m = (lo+hi)/2;
       if (v[lo]>v[m])
-        swap(v[lo],v[m]);
+        swap_(v[lo],v[m]);
       if (v[m]>v[hi]) {
-        swap(v[m],v[hi]);
+        swap_(v[m],v[hi]);
         if (v[lo]>v[m])
-          swap(v[lo],v[m]);
+          swap_(v[lo],v[m]);
+
       }
       /* Extract pivot, place sentinel */
       pivot = v[m];
@@ -191,7 +192,7 @@ ksmallest(T *v, int n, int k)
       do ++l; while (v[l]<pivot);
       do --h; while (v[h]>pivot);
       if (l < h) { 
-        swap(v[l],v[h]); 
+        swap_(v[l],v[h]); 
         goto loop; 
       }
       /* Finish up */
