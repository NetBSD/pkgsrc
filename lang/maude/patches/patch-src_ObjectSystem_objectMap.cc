$NetBSD: patch-src_ObjectSystem_objectMap.cc,v 1.2 2015/12/29 23:34:51 dholland Exp $

Fix C++ build issues.

--- src/ObjectSystem/objectMap.cc.orig	2013-11-28 00:45:15.000000000 +0000
+++ src/ObjectSystem/objectMap.cc
@@ -50,7 +50,7 @@ ConfigSymbol::MessageQueue::markReachabl
 
 struct ConfigSymbol::dagNodeLt
 {
-  bool operator()(const DagNode* d1, const DagNode* d2)
+  bool operator()(const DagNode* d1, const DagNode* d2) const
     {
       return d1->compare(d2) < 0;
     }
