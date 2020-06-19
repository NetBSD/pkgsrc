$NetBSD: patch-boost_geometry_index_detail_rtree_visitors_insert.hpp,v 1.1 2020/06/19 13:02:39 ryoon Exp $

* Fix regression (fix build of graphics/krita-4.3.0).
  https://github.com/boostorg/geometry/commit/a74a2b5814a8753013a8966606b8472178fffd14

--- boost/geometry/index/detail/rtree/visitors/insert.hpp.orig	2020-04-22 13:35:08.000000000 +0000
+++ boost/geometry/index/detail/rtree/visitors/insert.hpp
@@ -265,7 +265,7 @@ struct insert_traverse_data
 // Default insert visitor
 template <typename Element, typename MembersHolder>
 class insert
-    : MembersHolder::visitor
+    : public MembersHolder::visitor
 {
 protected:
     typedef typename MembersHolder::box_type box_type;
