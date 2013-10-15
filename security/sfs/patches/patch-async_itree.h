$NetBSD: patch-async_itree.h,v 1.1 2013/10/15 14:48:38 joerg Exp $

--- async/itree.h.orig	2013-10-14 20:52:43.000000000 +0000
+++ async/itree.h
@@ -86,7 +86,7 @@ class itree_core {
   itree_core (const itree_core &);
   itree_core &operator = (const itree_core &);
 
-#define eos ((int) &(((T *) 0)->*field).p)
+#define eos ((int)(size_t) &(((T *) 0)->*field).p)
 #define cmpfn scmp, (void *) this
 
 public:
@@ -217,7 +217,7 @@ public:
 #else
   V *operator[] (const K &k) {
     // return search (wrap (this, &kvcmp, &k));
-    return search (skvcmp, &kcmp, &k);
+    return this->search (skvcmp, &kcmp, &k);
   }
 #endif
 };
