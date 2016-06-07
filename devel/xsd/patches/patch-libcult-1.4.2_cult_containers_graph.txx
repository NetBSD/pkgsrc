$NetBSD: patch-libcult-1.4.2_cult_containers_graph.txx,v 1.2 2016/06/07 17:59:51 joerg Exp $

--- libcult-1.4.2/cult/containers/graph.txx.orig	2013-05-14 20:04:32.000000000 +0000
+++ libcult-1.4.2/cult/containers/graph.txx
@@ -294,7 +294,7 @@ namespace Cult
     Void Graph<N, E>::
     delete_edge (Left& l, Right& r, T& edge)
     {
-      typename Edges::Iterator i (edges_.find (&edge));
+      typename Edges::EraseIterator i (edges_.find (&edge));
 
       if (i == edges_.end () ||
           nodes_.find (&l) == nodes_.end () ||
