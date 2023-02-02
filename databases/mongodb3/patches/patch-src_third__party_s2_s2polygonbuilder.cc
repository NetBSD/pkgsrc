$NetBSD: patch-src_third__party_s2_s2polygonbuilder.cc,v 1.1 2023/02/02 14:40:33 tnn Exp $

Deal with namespace conflict.

--- src/third_party/s2/s2polygonbuilder.cc.orig	2020-01-08 16:30:41.000000000 +0000
+++ src/third_party/s2/s2polygonbuilder.cc
@@ -175,7 +175,7 @@ S2Loop* S2PolygonBuilder::AssembleLoop(S
   // This ensures that only CCW loops are constructed when possible.
 
   vector<S2Point> path;          // The path so far.
-  hash_map<S2Point, int> index;  // Maps a vertex to its index in "path".
+  s2_hash_map<S2Point, int> index;  // Maps a vertex to its index in "path".
   path.push_back(v0);
   path.push_back(v1);
   index[v1] = 1;
@@ -361,7 +361,7 @@ void S2PolygonBuilder::BuildMergeMap(Poi
 
   // First, we build the set of all the distinct vertices in the input.
   // We need to include the source and destination of every edge.
-  hash_set<S2Point> vertices;
+  s2_hash_set<S2Point> vertices;
   for (EdgeSet::const_iterator i = edges_->begin(); i != edges_->end(); ++i) {
     vertices.insert(i->first);
     VertexSet const& vset = i->second;
@@ -370,7 +370,7 @@ void S2PolygonBuilder::BuildMergeMap(Poi
   }
 
   // Build a spatial index containing all the distinct vertices.
-  for (hash_set<S2Point>::const_iterator i = vertices.begin();
+  for (s2_hash_set<S2Point>::const_iterator i = vertices.begin();
        i != vertices.end(); ++i) {
     index->Insert(*i);
   }
@@ -378,7 +378,7 @@ void S2PolygonBuilder::BuildMergeMap(Poi
   // Next, we loop through all the vertices and attempt to grow a maximial
   // mergeable group starting from each vertex.
   vector<S2Point> frontier, mergeable;
-  for (hash_set<S2Point>::const_iterator vstart = vertices.begin();
+  for (s2_hash_set<S2Point>::const_iterator vstart = vertices.begin();
        vstart != vertices.end(); ++vstart) {
     // Skip any vertices that have already been merged with another vertex.
     if (merge_map->find(*vstart) != merge_map->end()) continue;
