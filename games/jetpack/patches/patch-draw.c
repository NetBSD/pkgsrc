$NetBSD: patch-draw.c,v 1.1 2013/01/15 15:19:05 joerg Exp $

--- draw.c.orig	1992-03-29 19:41:14.000000000 +0000
+++ draw.c
@@ -4,6 +4,8 @@
 #include "copyright.h"
 #include "defs.h"
 
+static void draw_player(void);
+
 Pixmap	drawpixmap;
 
 char	fuelstring[20] = "Fuel: ";
@@ -68,7 +70,7 @@ draw_maze()
 
 /*	draw_player draws the player in the center of the window
 */
-draw_player()
+static void draw_player(void)
 {
 	if(dead) return;
 	if(exploded > -1) {
@@ -533,7 +535,7 @@ title_refresh()
         y, CGREY, fontinfo);
     y += fontinfo->descent + fontinfo->ascent;
     place_string(
-        "             center button : fire jetpack                    ",
+        "             center button : fire jetpack  T : turbo         ",
         y, CYELLOW, fontinfo);
     y += fontinfo->descent + 10 + fontinfo->ascent;
     place_string("Extra Player awarded every 10000 points", y, CGREY,
