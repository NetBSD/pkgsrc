$NetBSD: patch-GLwDrawA.c,v 1.1 2022/12/21 17:26:55 vins Exp $

Fix typo, s/width/height/.

--- GLwDrawA.c.orig	2012-05-17 13:55:42.000000000 +0000
+++ GLwDrawA.c
@@ -474,7 +474,7 @@ static void Initialize(GLwDrawingAreaWid
 
   /* fix size */
   if(req->core.width==0) neww->core.width=100;
-  if(req->core.height==0) neww->core.width=100;
+  if(req->core.height==0) neww->core.height=100;
 
   /* create the attribute list if needed */
   neww->glwDrawingArea.myList=FALSE;
