$NetBSD: patch-xgraphics.c,v 1.1 2012/11/01 19:55:37 joerg Exp $

--- xgraphics.c.orig	2012-10-30 22:05:56.000000000 +0000
+++ xgraphics.c
@@ -289,7 +289,7 @@ void placate_x()
 
 int get_mouse_x()
 {
-  checkX;
+  checkX2(-1);
 
   placate_x();
 
@@ -299,7 +299,7 @@ int get_mouse_x()
 
 int get_mouse_y()
 {
-  checkX;
+  checkX2(-1);
 
   placate_x();
 
