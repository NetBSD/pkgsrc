$NetBSD: patch-intern_itasc_kdl_treefksolverpos__recursive.hpp,v 1.1 2014/01/10 20:06:46 joerg Exp $

--- intern/itasc/kdl/treefksolverpos_recursive.hpp.orig	2009-07-14 15:36:21.000000000 +0000
+++ intern/itasc/kdl/treefksolverpos_recursive.hpp
@@ -45,7 +45,7 @@ namespace KDL {
     private:
         const Tree tree;
         
-        Frame recursiveFk(const JntArray& q_in, const SegmentMap::const_iterator& it, const SegmentMap::const_iterator& baseit);
+        Frame recursiveFk(const JntArray& q_in, SegmentMap::value_type const* it, SegmentMap::value_type const* baseit);
     };
 
 }
