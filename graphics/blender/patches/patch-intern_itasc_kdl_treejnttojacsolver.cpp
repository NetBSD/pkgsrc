$NetBSD: patch-intern_itasc_kdl_treejnttojacsolver.cpp,v 1.1 2014/01/10 20:06:46 joerg Exp $

--- intern/itasc/kdl/treejnttojacsolver.cpp.orig	2011-10-23 18:38:16.000000000 +0000
+++ intern/itasc/kdl/treejnttojacsolver.cpp
@@ -28,16 +28,16 @@ int TreeJntToJacSolver::JntToJac(const J
         return -1;
 
     //Lets search the tree-element
-    SegmentMap::const_iterator it = tree.getSegments().find(segmentname);
+    SegmentMap::value_type const* it = tree.getSegmentPtr(segmentname);
 
     //If segmentname is not inside the tree, back out:
-    if (it == tree.getSegments().end())
+    if (!it)
         return -2;
 
     //Let's make the jacobian zero:
     SetToZero(jac);
 
-    SegmentMap::const_iterator root = tree.getSegments().find("root");
+    SegmentMap::value_type const* root = tree.getSegmentPtr("root");
 
     Frame T_total = Frame::Identity();
 	Frame T_local, T_joint;
