$NetBSD: patch-async_itree.h,v 1.1 2013/03/28 21:21:18 joerg Exp $

--- async/itree.h.orig	2013-03-25 14:16:45.000000000 +0000
+++ async/itree.h
@@ -245,12 +245,12 @@ public:
 #if 0
   template<class T> V *operator[] (const T &k) {
     int (itree::*fn) (const T *, const V *) = &kvcmp<T>;
-    return search (wrap (this, fn, &k));
+    return this->search (wrap (this, fn, &k));
   }
 #else
   V *operator[] (const K &k) {
     // return search (wrap (this, &kvcmp, &k));
-    return search (skvcmp, &kcmp, &k);
+    return this->search (skvcmp, &kcmp, &k);
   }
 #endif
 };
