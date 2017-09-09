$NetBSD: patch-async_ihash.h,v 1.2 2017/09/09 19:45:46 dholland Exp $

Catch up to C++ standards drift.

--- async/ihash.h.orig	2009-02-23 16:26:42.000000000 +0000
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
@@ -287,13 +287,13 @@ public:
     : eq1 (e1), eq2 (e2), hash (h) {}
 
   void insert (V *elm)
-    { insert_val (elm, hash (elm->*key1, elm->*key2)); }
+    { this->insert_val (elm, hash (elm->*key1, elm->*key2)); }
 
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
@@ -301,7 +301,7 @@ public:
   V *nextkeq (V *v) {
     const K1 &k1 = v->*key1;
     const K1 &k2 = v->*key2;
-    while ((v = next_val (v))
+    while ((v = this->next_val (v))
 	   && !(eq1 (k1, v->*key1) && eq2 (k2, v->*key2)))
       ;
     return v;
@@ -320,20 +320,20 @@ public:
   shash () {}
   shash (const E &e, const H &h) : eq (e), hash (h) {}
 
-  void insert (V *elm) { insert_val (elm, hash (*elm)); }
+  void insert (V *elm) { this->insert_val (elm, hash (*elm)); }
 
   V *operator[] (const V &k) const {
     V *v;
-    for (v = lookup_val (hash (k));
+    for (v = this->lookup_val (hash (k));
 	 v && !eq (k, *v);
-	 v = next_val (v))
+	 v = this->next_val (v))
       ;
     return v;
   }
 
   V *nextkeq (V *v) {
     const V &k = *v;
-    while ((v = next_val (v)) && !eq (k, *v))
+    while ((v = this->next_val (v)) && !eq (k, *v))
       ;
     return v;
   }
