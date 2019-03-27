$NetBSD: patch-intern_itasc_kdl_tree.hpp,v 1.3 2019/03/27 11:05:57 markd Exp $

Added extra "const" to satisfy the strict clang version in Xcode 9
commit ee30a4381f8989ed9f39b4baae9f74e45c9dcdc9

--- intern/itasc/kdl/tree.hpp.orig	2018-03-23 15:22:25.000000000 +0000
+++ intern/itasc/kdl/tree.hpp
@@ -34,7 +34,7 @@ namespace KDL
     //Forward declaration
     class TreeElement;
     // Eigen allocator is needed for alignment of Eigen data types
-    typedef std::map<std::string,TreeElement, std::less<std::string>, Eigen::aligned_allocator<std::pair<std::string, TreeElement> > > SegmentMap;
+    typedef std::map<std::string,TreeElement, std::less<std::string>, Eigen::aligned_allocator<std::pair<const std::string, TreeElement> > > SegmentMap;
 
     class TreeElement
     {
