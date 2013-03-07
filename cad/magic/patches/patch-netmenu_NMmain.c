$NetBSD: patch-netmenu_NMmain.c,v 1.2 2013/03/07 22:05:13 joerg Exp $

--- netmenu/NMmain.c.orig	2013-03-02 22:39:15.000000000 +0000
+++ netmenu/NMmain.c
@@ -238,13 +238,8 @@ NMreposition(window, newScreenArea, fina
  * ----------------------------------------------------------------------------
  */
 
-int
-NMredisplay(w, rootArea, clipArea)
-    MagWindow *w;			/* The window containing the area. */
-    Rect *rootArea;		/* Redisplay area in surface coordinates. */
-    Rect *clipArea;		/* Screen area to clip to.  If NULL, use
-				 * screen area of window. */
-
+void
+NMredisplay(MagWindow *w, Rect *rootArea, Rect *clipArea)
 {
     Rect clip, screenR;
     Point screenP;
@@ -356,10 +351,8 @@ NMredisplay(w, rootArea, clipArea)
  * ----------------------------------------------------------------------------
  */
 
-int
-NMcommand(w, cmd)
-    MagWindow *w;			/* Net-list menu window. */
-    TxCommand *cmd;
+void
+NMcommand(MagWindow *w, TxCommand *cmd)
 {
     NetButton *nb;
     Point surfacePoint;
