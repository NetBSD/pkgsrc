$NetBSD: patch-libasync_ihash.h,v 1.2 2014/11/22 03:01:33 mef Exp $

Fix C++ errors

--- libasync/ihash.h.orig	2013-01-21 20:01:04.000000000 +0900
+++ libasync/ihash.h	2014-11-22 11:47:06.000000000 +0900
@@ -235,7 +235,7 @@ public:
   ihash () : eq (E ()), hash (H ()) {}
   ihash (const E &e, const H &h) : eq (e), hash (h) {}
 
-  void insert (V *elm) { ihash::insert_val (elm, hash (elm->*key)); }
+  void insert (V *elm) { this->ihash::insert_val (elm, hash (elm->*key)); }
 
 #if 0
   template<class T> V *operator[] (const T &k) const {
@@ -278,9 +278,9 @@ public:
 
   V *operator() (const K1 &k1, const K2 &k2) const {
     V *v;
-    for (v = lookup_val (hash (k1, k2));
+    for (v = this->lookup_val (hash (k1, k2));
 	 v && !(eq1 (k1, v->*key1) && eq2 (k2, v->*key2));
-	 v = next_val (v))
+	 v = this->next_val (v))
       ;
     return v;
   }
@@ -320,7 +320,7 @@ public:
 
   V *nextkeq (V *v) {
     const V &k = *v;
-    while ((v = next_val (v)) && !eq (k, *v))
+    while ((v = this->next_val (v)) && !eq (k, *v))
       ;
     return v;
   }
