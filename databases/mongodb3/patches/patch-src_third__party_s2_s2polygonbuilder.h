$NetBSD: patch-src_third__party_s2_s2polygonbuilder.h,v 1.1 2023/02/02 14:40:33 tnn Exp $

Deal with namespace conflict.

--- src/third_party/s2/s2polygonbuilder.h.orig	2020-01-08 16:30:41.000000000 +0000
+++ src/third_party/s2/s2polygonbuilder.h
@@ -262,7 +262,7 @@ class S2PolygonBuilder {
   // current position to a new position, and also returns a spatial index
   // containing all of the vertices that do not need to be moved.
   class PointIndex;
-  typedef hash_map<S2Point, S2Point> MergeMap;
+  typedef s2_hash_map<S2Point, S2Point> MergeMap;
   void BuildMergeMap(PointIndex* index, MergeMap* merge_map);
 
   // Moves a set of vertices from old to new positions.
@@ -282,7 +282,7 @@ class S2PolygonBuilder {
   // once.  We could have also used a multiset<pair<S2Point, S2Point> >,
   // but this representation is a bit more convenient.
   typedef multiset<S2Point> VertexSet;
-  typedef hash_map<S2Point, VertexSet> EdgeSet;
+  typedef s2_hash_map<S2Point, VertexSet> EdgeSet;
   scoped_ptr<EdgeSet> edges_;
 
   // Unique collection of the starting (first) vertex of all edges,
