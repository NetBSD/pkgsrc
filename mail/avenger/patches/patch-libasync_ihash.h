$NetBSD: patch-libasync_ihash.h,v 1.1 2012/01/18 14:32:10 adam Exp $

Fix C++ errors

--- libasync/ihash.h.orig	2012-01-18 14:07:53.000000000 +0000
+++ libasync/ihash.h
@@ -235,7 +235,7 @@ public:
   ihash () : eq (E ()), hash (H ()) {}
   ihash (const E &e, const H &h) : eq (e), hash (h) {}
 
-  void insert (V *elm) { insert_val (elm, hash (elm->*key)); }
+  void insert (V *elm) { this->insert_val (elm, hash (elm->*key)); }
 
 #if 0
   template<class T> V *operator[] (const T &k) const {
@@ -243,16 +243,16 @@ public:
   V *operator[] (const K &k) const {
 #endif
     V *v;
-    for (v = lookup_val (hash (k));
+    for (v = this->lookup_val (hash (k));
 	 v && !eq (k, v->*key);
-	 v = next_val (v))
+	 v = this->next_val (v))
       ;
     return v;
   }
 
   V *nextkeq (V *v) {
     const K &k = v->*key;
-    while ((v = next_val (v)) && !eq (k, v->*key))
+    while ((v = this->next_val (v)) && !eq (k, v->*key))
       ;
     return v;
   };
