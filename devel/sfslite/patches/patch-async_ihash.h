$NetBSD: patch-async_ihash.h,v 1.1 2013/03/28 21:21:18 joerg Exp $

--- async/ihash.h.orig	2013-03-25 14:13:37.000000000 +0000
+++ async/ihash.h
@@ -248,7 +248,7 @@ public:
   ihash () : eq (E ()), hash (H ()) {}
   ihash (const E &e, const H &h) : eq (e), hash (h) {}
 
-  bool insert (V *elm) { return insert_val (elm, hash (elm->*key)); }
+  bool insert (V *elm) { return this->insert_val (elm, hash (elm->*key)); }
 
 #if 0
   template<class T> V *operator[] (const T &k) const {
@@ -256,16 +256,16 @@ public:
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
