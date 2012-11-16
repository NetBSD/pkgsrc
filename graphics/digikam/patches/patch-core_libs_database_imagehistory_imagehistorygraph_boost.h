$NetBSD: patch-core_libs_database_imagehistory_imagehistorygraph_boost.h,v 1.2 2012/11/16 20:06:08 joerg Exp $

boost148.patch from ArchLinux - build with recent boost.

--- core/libs/database/imagehistory/imagehistorygraph_boost.h.orig	2012-01-03 00:32:26.000000000 +0000
+++ core/libs/database/imagehistory/imagehistorygraph_boost.h
@@ -1198,7 +1198,7 @@ protected:
             {
                 boost::dag_shortest_paths(graph, v,
                                           // we provide a constant weight of 1
-                                          weight_map(boost::ref_property_map<edge_t,int>(weight)).
+                                          weight_map(boost::ref_property_map<typename boost::graph_traits<GraphType>::edge_descriptor,int>(weight)).
                                           // Store distance and predecessors in QMaps, wrapped to serve as property maps
                                           distance_map(VertexIntMapAdaptor(distances)).
                                           predecessor_map(VertexVertexMapAdaptor(predecessors))
@@ -1218,7 +1218,7 @@ protected:
             {
                 boost::dag_shortest_paths(graph, v,
                                           // we provide a constant weight of 1
-                                          weight_map(boost::ref_property_map<edge_t,int>(weight)).
+                                          weight_map(boost::ref_property_map<typename boost::graph_traits<GraphType>::edge_descriptor,int>(weight)).
                                           // Invert the default compare method: With greater, we get the longest path
                                           distance_compare(std::greater<int>()).
                                           // will be returned if a node is unreachable
@@ -1362,7 +1362,7 @@ protected:
             template <typename VertexType, typename GraphType>
             void discover_vertex(VertexType u, const GraphType&) const
             {
-                record(u);
+                this->record(u);
             }
         };
 
@@ -1373,7 +1373,7 @@ protected:
             template <typename VertexType, typename GraphType>
             void discover_vertex(VertexType u, const GraphType&) const
             {
-                record(u);
+                this->record(u);
             }
         };
 
@@ -1384,14 +1384,15 @@ protected:
         template <class GraphType, typename VertexLessThan>
         class lessThanMapEdgeToTarget
         {
+            typedef typename boost::graph_traits<GraphType>::edge_descriptor edge_descriptor;
         public:
             lessThanMapEdgeToTarget(const GraphType& g, VertexLessThan vertexLessThan)
                 : g(g), vertexLessThan(vertexLessThan) {}
             const GraphType& g;
             VertexLessThan vertexLessThan;
-            bool operator()(const Edge& a, const Edge& b)
+            bool operator()(const edge_descriptor& a, const edge_descriptor& b)
             {
-                return vertexLessThan(boost::target(a.toEdge(), g), boost::target(b.toEdge(), g));
+                return vertexLessThan(boost::target(a, g), boost::target(b, g));
             }
         };
 
@@ -1402,20 +1403,21 @@ protected:
         {
             typedef std::pair<Vertex, QList<Edge> > VertexInfo;
 
-            QList<Edge>             outEdges;
+            typedef typename boost::graph_traits<IncidenceGraph>::edge_descriptor edge_descriptor;
+            QList<edge_descriptor> outEdges;
             std::vector<VertexInfo> stack;
 
             boost::put(color, u, boost::gray_color);
             vis.discover_vertex(u, g);
 
-            outEdges = toEdgeList(boost::out_edges(u, g));
+            outEdges = toList<edge_descriptor>(boost::out_edges(u, g));
             // Sort edges. The lessThan we have takes vertices, so we use a lessThan which
             // maps the given edges to their targets, and calls our vertex lessThan.
             qSort(outEdges.begin(), outEdges.end(), lessThanMapEdgeToTarget<IncidenceGraph, LessThan>(g, lessThan));
 
-            foreach(const Edge& e, outEdges)
+            foreach(const edge_descriptor& e, outEdges)
             {
-                Vertex v = boost::target(e.toEdge(), g);
+                Vertex v = boost::target(e, g);
                 vis.examine_edge(e, g);
                 boost::default_color_type v_color = boost::get(color, v);
                 if (v_color == boost::white_color)
