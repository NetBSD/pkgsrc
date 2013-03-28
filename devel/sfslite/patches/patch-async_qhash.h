$NetBSD: patch-async_qhash.h,v 1.1 2013/03/28 21:21:18 joerg Exp $

--- async/qhash.h.orig	2013-03-25 14:17:11.000000000 +0000
+++ async/qhash.h
@@ -71,7 +71,7 @@ private:
 
   slot *getslot (const K &k) const {
     slot *s;
-    for (s = lookup_val (hash (k)); s && !eq (s->key, k); s = next_val (s))
+    for (s = this->lookup_val (hash (k)); s && !eq (s->key, k); s = this->next_val (s))
       ;
     return s;
   }
@@ -180,7 +180,7 @@ private:
 
   slot *getslot (const K &k) const {
     slot *s;
-    for (s = lookup_val (hash (k)); s && !eq (s->key, k); s = next_val (s))
+    for (s = this->lookup_val (hash (k)); s && !eq (s->key, k); s = this->next_val (s))
       ;
     return s;
   }
