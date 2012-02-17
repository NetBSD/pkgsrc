$NetBSD: patch-amaze.c,v 1.1.1.1 2012/02/17 17:22:13 jakllsch Exp $

Fix function prototypes.

--- amaze.c.orig	2000-05-30 04:59:48.000000000 +0000
+++ amaze.c
@@ -336,6 +336,7 @@ static int bary[MAXDIST + 2] = { 0, 2, 5
 /* Draw the close vertical edge of a block */
 void
 draw_vert_edge(dist, right)
+	int dist, right;
 {
 	int y;
 	for (y = bary[dist]; y <= 22 - bary[dist]; y++)
@@ -348,6 +349,7 @@ draw_vert_edge(dist, right)
 /* Draw the horizontal edge of a block */
 void
 draw_horiz_front(dist, right)
+	int dist, right;
 {
 	int x;
 
@@ -364,6 +366,7 @@ draw_horiz_front(dist, right)
 /* Draw the horiz edge of a wall in the way */
 void
 draw_horiz_wall(dist)
+	int dist;
 {
 	int x;
 	for (x = barx[dist] + 1; x <= 43 - (barx[dist] + 1); x++) {
