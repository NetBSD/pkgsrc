$NetBSD: patch-erase.c,v 1.1 2013/01/15 15:19:05 joerg Exp $

--- erase.c.orig	1992-03-29 19:41:20.000000000 +0000
+++ erase.c
@@ -8,9 +8,12 @@
 /*	Note: the functions and variables in this file are not used in the
 	blitting version.
 */
+static void draw_recur(int i);
+static void erase_recur(int i);
 
 #ifndef BLIT
 
+#define MAXTOUCH 10
 #define MAXOBJECTS 6+MAXLINES+MAXFIREBALLS+MAXSWEEPERS+MAXFUELPODS+MAXGUARDS+MAXHIGHSCORES/5
 
 /*	Structure for eraseable zones that minimize flicker
@@ -19,7 +22,7 @@ struct zone {
 	int	type, num;
 	int	x, y, w, h;
 	int	numtouch;
-	int	touch[MAXOBJECTS];
+	int	touch[MAXTOUCH];
 	int	erased, drawn;
 };
 
@@ -57,6 +60,10 @@ int	x, y, w, h, type, num;
 		if(zone_intersect(numzones,j)) {
 			zones[j].touch[zones[j].numtouch] = numzones;
 			zones[j].numtouch++;
+			if (zones[j].numtouch == MAXTOUCH) {
+				zones[j].numtouch = -1;
+				printf("Reached maxtouch for zone %d\n", numzones);
+			}
 			break;
 		}
 	}
@@ -115,8 +122,7 @@ erase_draw_zones()
 
 /*	erase_recur erases zone i and all the zones that touch it.
 */
-erase_recur(i)
-int	i;
+static void erase_recur(int i)
 {
 	register int	j;
 
@@ -137,8 +143,7 @@ int	i;
 /*	draw_recur draws the object associated with zone i and the objects
 	associated with all the zones that touch it.
 */
-draw_recur(i)
-int	i;
+static void draw_recur(int i)
 {
 	register int	j, tmp;
 
