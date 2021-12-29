$NetBSD: patch-maze.c,v 1.1 2021/12/29 23:56:01 nia Exp $

Add return types, from FreeBSD Ports.

--- maze.c.orig	1994-03-18 05:13:16.000000000 +0000
+++ maze.c
@@ -124,7 +124,7 @@ static mazedata   mazes[] = {
 		  "z---x---x---x---x---c" } };
 
 
-read_maze(num)
+void read_maze(num)
 int num;
 {
    int          i, xx, yy;
@@ -259,7 +259,7 @@ int num;
  * The function which follows is used at the beginning of each level to
  * set up the initial parameters for all of the moving figures.
  */
-position_players()
+void position_players()
 {
    int 		i;
    XRectangle	ghost_rect[MAX_GHOSTS], pac_rect;
