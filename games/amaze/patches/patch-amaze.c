$NetBSD: patch-amaze.c,v 1.2 2013/09/10 14:18:44 joerg Exp $

--- amaze.c.orig	2000-05-30 04:59:48.000000000 +0000
+++ amaze.c
@@ -290,7 +290,7 @@ showmap()
  * possible branches; put limits on the segment lengths etc.
  */
 void
-makemaze()
+makemaze(void)
 {
 	int maxy, maxx;
 	int i;
@@ -335,7 +335,7 @@ static int bary[MAXDIST + 2] = { 0, 2, 5
 
 /* Draw the close vertical edge of a block */
 void
-draw_vert_edge(dist, right)
+draw_vert_edge(int dist, int right)
 {
 	int y;
 	for (y = bary[dist]; y <= 22 - bary[dist]; y++)
@@ -347,7 +347,7 @@ draw_vert_edge(dist, right)
 
 /* Draw the horizontal edge of a block */
 void
-draw_horiz_front(dist, right)
+draw_horiz_front(int dist, int right)
 {
 	int x;
 
@@ -363,7 +363,7 @@ draw_horiz_front(dist, right)
 
 /* Draw the horiz edge of a wall in the way */
 void
-draw_horiz_wall(dist)
+draw_horiz_wall(int dist)
 {
 	int x;
 	for (x = barx[dist] + 1; x <= 43 - (barx[dist] + 1); x++) {
@@ -374,8 +374,7 @@ draw_horiz_wall(dist)
 
 /* Draw the (visually) diagonal edge of a block */
 void 
-draw_horiz_side(dist, right)
-	int dist, right;
+draw_horiz_side(int dist, int right)
 {
 	int y, x;
 
@@ -391,9 +390,7 @@ draw_horiz_side(dist, right)
 
 /* Draw the floor in the centre of view */
 void
-draw_floor_centre(dist, ch)
-	int dist;
-	chtype ch;
+draw_floor_centre(int dist, chtype ch)
 {
 	int y, x, xx;
 
@@ -406,10 +403,7 @@ draw_floor_centre(dist, ch)
 
 /* Draw the floor to the side */
 void
-draw_floor_side(dist, right, ch)
-	int dist;
-	int right;
-	chtype ch;
+draw_floor_side(int dist, int right, chtype ch)
 {
 	int y, x, xx;
 
@@ -698,7 +692,7 @@ amaze()
 	leaveok(msg, 1);
 	scrollok(msg, 0);
 
-	makemaze(map);
+	makemaze();
 
 	/* Show where the goal is */
 	copyumap(gy, gx, 1);
