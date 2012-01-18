$NetBSD: patch-libasync_itree.h,v 1.1 2012/01/18 14:32:10 adam Exp $

Fix C++ errors

--- libasync/itree.h.orig	2012-01-18 14:08:55.000000000 +0000
+++ libasync/itree.h
@@ -250,7 +250,7 @@ public:
 #else
   V *operator[] (const K &k) {
     // return search (wrap (this, &kvcmp, &k));
-    return search (skvcmp, &kcmp, &k);
+    return this->search (skvcmp, &kcmp, &k);
   }
 #endif
 };
