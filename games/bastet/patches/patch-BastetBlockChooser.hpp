$NetBSD: patch-BastetBlockChooser.hpp,v 1.1 2017/09/25 22:32:16 joerg Exp $

tr1 has been removed in boost.

--- BastetBlockChooser.hpp.orig	2017-09-25 11:55:27.036704403 +0000
+++ BastetBlockChooser.hpp
@@ -23,7 +23,7 @@
 
 #include "Well.hpp"
 
-#include <boost/tr1/tr1/unordered_set>
+#include <boost/unordered_set.hpp>
 #include <set>
 #include <boost/functional/hash.hpp>
 
@@ -75,7 +75,7 @@ namespace Bastet{
   public:
     Searcher(BlockType b, const Well *well, Vertex v, WellVisitor *visitor);
   private:
-    std::tr1::unordered_set<Vertex> _visited;
+    boost::unordered_set<Vertex> _visited;
     //std::set<Vertex> _visited; ^^ the above is more efficient, we need to do many inserts
     BlockType _block;
     const Well *_well;
