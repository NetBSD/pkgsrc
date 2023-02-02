$NetBSD: patch-src_third__party_s2_s2loop.cc,v 1.1 2023/02/02 14:40:33 tnn Exp $

Deal with namespace conflict.

--- src/third_party/s2/s2loop.cc.orig	2020-01-08 16:30:41.000000000 +0000
+++ src/third_party/s2/s2loop.cc
@@ -121,7 +121,7 @@ bool S2Loop::IsValid(string* err) const 
     }
   }
   // Loops are not allowed to have any duplicate vertices.
-  hash_map<S2Point, int> vmap;
+  s2_hash_map<S2Point, int> vmap;
   for (int i = 0; i < num_vertices(); ++i) {
     if (!vmap.insert(make_pair(vertex(i), i)).second) {
       VLOG(2) << "Duplicate vertices: " << vmap[vertex(i)] << " and " << i;
