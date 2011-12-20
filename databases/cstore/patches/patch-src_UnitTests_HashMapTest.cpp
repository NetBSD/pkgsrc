$NetBSD: patch-src_UnitTests_HashMapTest.cpp,v 1.1 2011/12/20 13:42:47 wiz Exp $

Avoid cast error.

--- src/UnitTests/HashMapTest.cpp.orig	2006-10-17 19:35:33.000000000 +0000
+++ src/UnitTests/HashMapTest.cpp
@@ -52,27 +52,27 @@ bool HashMapTest::run(Globals *g, const 
   map->put(&z, (void*)b, sizeof(int));
   
 
-  if ((int)map->get(&x) != c) return false;
-  if ((int)map->get(&y) != d) return false;
-  if ((int)map->get(&z) != b) return false;
+  if ((int64_t)map->get(&x) != c) return false;
+  if ((int64_t)map->get(&y) != d) return false;
+  if ((int64_t)map->get(&z) != b) return false;
   if (map->getDataSize() != 3*sizeof(int)) return false;
   if (map->getNumKeys() != 3) return false;
 
   map->put(&x, (void*)a, sizeof(int));
-  if ((int)map->get(&x) != a) { return false; }
+  if ((int64_t)map->get(&x) != a) { return false; }
   if (map->getDataSize() != 3*sizeof(int)) return false;
 
   if (map->getNumKeys() != 3) return false;
 
   map->put(&w, (void*)c, sizeof(int));
-  if ((int)map->get(&x) != a) return false;
-  if ((int)map->get(&w) != c) return false;
+  if ((int64_t)map->get(&x) != a) return false;
+  if ((int64_t)map->get(&w) != c) return false;
   if (map->getDataSize() != 4*sizeof(int)) return false;
   if (map->getNumKeys() != 4) return false;
 
   for (int i = 0; i < 4; i++) {
     ValPos* k = map->getKey()->clone();
-    int a = (int)map->remove(k);
+    int a = (int64_t)map->remove(k);
     cout << "HashMap: iterated over (" << *(int*)k->value << "," << a << ")\n";
     delete k;
     //cout << "NumKeys: " << map->getNumKeys() << "\n";
