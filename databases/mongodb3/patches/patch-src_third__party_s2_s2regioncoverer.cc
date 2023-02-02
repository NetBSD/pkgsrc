$NetBSD: patch-src_third__party_s2_s2regioncoverer.cc,v 1.1 2023/02/02 14:40:33 tnn Exp $

Deal with namespace conflict.

--- src/third_party/s2/s2regioncoverer.cc.orig	2020-01-08 16:30:41.000000000 +0000
+++ src/third_party/s2/s2regioncoverer.cc
@@ -321,7 +321,7 @@ void S2RegionCoverer::GetInteriorCellUni
 
 void S2RegionCoverer::FloodFill(
     S2Region const& region, S2CellId const& start, vector<S2CellId>* output) {
-  hash_set<S2CellId> all;
+  s2_hash_set<S2CellId> all;
   vector<S2CellId> frontier;
   output->clear();
   all.insert(start);
