$NetBSD: patch-xgest.c,v 1.1 2012/12/20 22:04:14 joerg Exp $

--- xgest.c.orig	2012-12-20 17:55:28.000000000 +0000
+++ xgest.c
@@ -272,10 +272,7 @@ int button;
     return ms_None;
 }
 
-int gesture_motion(py, xpos, ypos, button)
-struct player *py;
-int xpos, ypos;
-int button;
+void gesture_motion(struct player *py, int xpos, int ypos, int button)
 {
     int hitx, hity, hit;
     int posx, posy;
