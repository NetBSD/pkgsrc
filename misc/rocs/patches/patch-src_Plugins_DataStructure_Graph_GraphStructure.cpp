$NetBSD: patch-src_Plugins_DataStructure_Graph_GraphStructure.cpp,v 1.1 2013/02/26 23:37:32 joerg Exp $

--- src/Plugins/DataStructure/Graph/GraphStructure.cpp.orig	2013-02-26 22:55:07.000000000 +0000
+++ src/Plugins/DataStructure/Graph/GraphStructure.cpp
@@ -153,7 +153,7 @@ QScriptValue Rocs::GraphStructure::dijks
     BOOST_FOREACH( PointerPtr p, this->pointers() )
     {
          edges[counter] = Edge(node_mapping[p->from().get()], node_mapping[p->to().get()]);
-         edge_mapping[std::make_pair<int,int>(node_mapping[p->from().get()], node_mapping[p->to().get()])] = p;
+         edge_mapping[std::make_pair(node_mapping[p->from().get()], node_mapping[p->to().get()])] = p;
          if (!p->value().isEmpty()) {
               weights[counter] = p->value().toDouble();
          } else {
@@ -163,7 +163,7 @@ QScriptValue Rocs::GraphStructure::dijks
          // if graph is directed, also add back-edges
          if(!this->directed()) {
               edges[counter] = Edge(node_mapping[p->to().get()], node_mapping[p->from().get()]);
-              edge_mapping[std::make_pair<int,int>(node_mapping[p->to().get()], node_mapping[p->from().get()])] = p;
+              edge_mapping[std::make_pair(node_mapping[p->to().get()], node_mapping[p->from().get()])] = p;
               if (!p->value().isEmpty()) {
                     weights[counter] = p->value().toDouble();
               } else {
