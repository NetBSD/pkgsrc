$NetBSD: patch-RocsCore_DataStructures_Graph_GraphStructure.cpp,v 1.1.2.2 2016/05/23 05:03:37 bsiegert Exp $

Don't force the argument types for std::make_pair, GCC 4.8 has problems
figuring out the correct invocation.

--- RocsCore/DataStructures/Graph/GraphStructure.cpp.orig	2016-05-06 17:05:52.000000000 +0000
+++ RocsCore/DataStructures/Graph/GraphStructure.cpp
@@ -323,7 +323,7 @@ QMap<DataPtr,PointerList> Rocs::GraphStr
     counter = 0;
     foreach(PointerPtr p, pointerListAll) {
         edges[counter] = Edge(node_mapping[p->from()->identifier()], node_mapping[p->to()->identifier()]);
-        edge_mapping[std::make_pair < int, int > (node_mapping[p->from()->identifier()], node_mapping[p->to()->identifier()])] = p;
+        edge_mapping[std::make_pair(node_mapping[p->from()->identifier()], node_mapping[p->to()->identifier()])] = p;
         if (!p->property("value").toString().isEmpty()) {
             weights[counter] = p->property("value").toDouble();
         } else {
@@ -333,7 +333,7 @@ QMap<DataPtr,PointerList> Rocs::GraphStr
         // if graph is directed, also add back-edges
         if (p->direction() == PointerType::Bidirectional) {
             edges[counter] = Edge(node_mapping[p->to()->identifier()], node_mapping[p->from()->identifier()]);
-            edge_mapping[std::make_pair< int, int >(node_mapping[p->to()->identifier()], node_mapping[p->from()->identifier()])] = p;
+            edge_mapping[std::make_pair(node_mapping[p->to()->identifier()], node_mapping[p->from()->identifier()])] = p;
             if (!p->property("value").toString().isEmpty()) {
                 weights[counter] = p->property("value").toDouble();
             } else {
