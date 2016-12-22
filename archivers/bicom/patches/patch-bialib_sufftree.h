$NetBSD: patch-bialib_sufftree.h,v 1.1 2016/12/22 20:59:54 joerg Exp $

Don't check sign of pointers.

--- bialib/sufftree.h.orig	2016-12-22 12:42:37.570864687 +0000
+++ bialib/sufftree.h
@@ -95,8 +95,8 @@ class SuffixTreeModel : public Arithmeti
     {
     public:
     bool InEdge()
-      {return(r>0);}
-    //After Canonize()ing a point, r >0 <=> proj!=0, i.e., point
+      {return(r != 0);}
+    //After Canonize()ing a point, r !=0 <=> proj!=0, i.e., point
     //is inside an edge
     INode *ins;  //parent of point
     LNode *r;    //if !=0, then child(ins,a)
