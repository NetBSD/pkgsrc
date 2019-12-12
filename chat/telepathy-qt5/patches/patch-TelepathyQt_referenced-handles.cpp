$NetBSD: patch-TelepathyQt_referenced-handles.cpp,v 1.1 2019/12/12 16:44:53 nros Exp $
* remove use of deprecated function
--- TelepathyQt/referenced-handles.cpp.orig	2019-12-10 09:43:25.272733422 +0000
+++ TelepathyQt/referenced-handles.cpp
@@ -269,7 +269,7 @@ bool ReferencedHandles::removeOne(uint h
 
 void ReferencedHandles::swap(int i, int j)
 {
-    mPriv->handles.swap(i, j);
+    mPriv->handles.swapItemsAt(i, j);
 }
 
 uint ReferencedHandles::takeAt(int i)
