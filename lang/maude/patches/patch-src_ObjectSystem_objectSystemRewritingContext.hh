$NetBSD: patch-src_ObjectSystem_objectSystemRewritingContext.hh,v 1.2 2015/12/29 23:34:51 dholland Exp $

Fix C++ build issues.

--- src/ObjectSystem/objectSystemRewritingContext.hh.orig	2013-11-28 00:46:15.000000000 +0000
+++ src/ObjectSystem/objectSystemRewritingContext.hh
@@ -62,7 +62,7 @@ protected:
 private:
   struct dagNodeLt
   {
-    bool operator()(const DagNode* d1, const DagNode* d2)
+    bool operator()(const DagNode* d1, const DagNode* d2) const
     {
       return d1->compare(d2) < 0;
     }
