$NetBSD: patch-netmenu_NMshowpt.c,v 1.2 2013/03/07 22:05:13 joerg Exp $

--- netmenu/NMshowpt.c.orig	2006-04-10 22:03:14.000000000 +0000
+++ netmenu/NMshowpt.c
@@ -71,12 +71,8 @@ static int nmspArrayUsed = 0;		/* Number
  * ----------------------------------------------------------------------------
  */
 
-int
-NMRedrawPoints(window, plane)
-    MagWindow *window;		/* Window in which to redisplay. */
-    Plane *plane;		/* Non-space tiles on this plane indicate
-				 * the areas where highlights must be redrawn.
-				 */
+void
+NMRedrawPoints(MagWindow *window, Plane *plane)
 {
     int i;
     Rect dbArea, screen;
