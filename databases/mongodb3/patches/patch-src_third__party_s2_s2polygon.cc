$NetBSD: patch-src_third__party_s2_s2polygon.cc,v 1.1 2023/02/02 14:40:33 tnn Exp $

Deal with namespace conflict.

--- src/third_party/s2/s2polygon.cc.orig	2020-01-08 16:30:41.000000000 +0000
+++ src/third_party/s2/s2polygon.cc
@@ -120,7 +120,7 @@ HASH_NAMESPACE_END
 bool S2Polygon::IsValid(const vector<S2Loop*>& loops, string* err) {
   // If a loop contains an edge AB, then no other loop may contain AB or BA.
   if (loops.size() > 1) {
-    hash_map<S2PointPair, pair<int, int> > edges;
+    s2_hash_map<S2PointPair, pair<int, int> > edges;
     for (size_t i = 0; i < loops.size(); ++i) {
       S2Loop* lp = loops[i];
       for (int j = 0; j < lp->num_vertices(); ++j) {
