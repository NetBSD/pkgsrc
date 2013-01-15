$NetBSD: patch-setup.c,v 1.1 2013/01/15 15:19:05 joerg Exp $

--- setup.c.orig	1992-03-29 19:41:23.000000000 +0000
+++ setup.c
@@ -4,6 +4,8 @@
 #include "copyright.h"
 #include "defs.h"
 
+static void random_fuel(int num);
+
 /*	make_random_level takes its huge list of arguments and creates a
 	level.
 */
@@ -115,8 +117,7 @@ random_player()
 	[dx,dy]. The coordinates are modified to so the fireball won't sit on
 	a wall.
 */
-place_fireball(x, y, dx, dy)
-int	x, y, dx, dy;
+void place_fireball(int x, int y, int dx, int dy)
 {
 	if(numfire == MAXFIREBALLS) return;
 	nx = x;
@@ -161,8 +162,7 @@ int	num, min, max;
 /*	place_guard puts a guard at maze location (x,y) with direction dir and
 	speed speed
 */
-place_guard(x, y, dir, speed)
-int	x, y, dir, speed;
+void place_guard(int x, int y, int dir, int speed)
 {
 	if(numguard == MAXGUARDS) return;
 	guardx[numguard] = x * mazescale + mazescale / 2;
@@ -205,8 +205,7 @@ int	num, min, max;
 /*	place_sweeper puts a sweeper at maze location (x,y) with a floor
 	direction of floor, rotation of rot, and speed speed
 */
-place_sweeper(x, y, floor, rot, speed)
-int	x, y, floor, rot, speed;
+void place_sweeper(int x, int y, int floor, int rot, int speed)
 {
 	if(numsweep == MAXSWEEPERS) return;
 	sweepx[numsweep] = x * mazescale + mazescale / 2 + xdir[floor] *
@@ -272,8 +271,7 @@ int	num, min, max;
 /*	place_fuel puts a fuel pod at world location (x,y). The coordinates
 	are modified so the pod won't sit on a wall.
 */
-place_fuel(x, y)
-int x, y;
+void place_fuel(int x, int y)
 {
 	if(numfuel == MAXFUELPODS) return;
 	nx = x;
@@ -288,8 +286,7 @@ int x, y;
 /*	random_fuel places num fuel pods in the maze. The coordinates are
 	generated so they don't sit on walls or too close together.
 */
-random_fuel(num)
-int	num;
+static void random_fuel(int num)
 {
 	register int	i, j, ok, radius;
 
