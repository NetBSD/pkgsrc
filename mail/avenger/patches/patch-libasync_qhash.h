$NetBSD: patch-libasync_qhash.h,v 1.1 2012/01/18 14:32:10 adam Exp $

Fix C++ errors

--- libasync/qhash.h.orig	2012-01-18 14:17:45.000000000 +0000
+++ libasync/qhash.h
@@ -71,7 +71,7 @@ private:
 
   slot *getslot (const K &k) const {
     slot *s;
-    for (s = lookup_val (hash (k)); s && !eq (s->key, k); s = next_val (s))
+    for (s = this->lookup_val (hash (k)); s && !eq (s->key, k); s = this->next_val (s))
       ;
     return s;
   }
@@ -156,7 +156,7 @@ private:
 
   slot *getslot (const K &k) const {
     slot *s;
-    for (s = lookup_val (hash (k)); s && !eq (s->key, k); s = next_val (s))
+    for (s = this->lookup_val (hash (k)); s && !eq (s->key, k); s = this->next_val (s))
       ;
     return s;
   }
