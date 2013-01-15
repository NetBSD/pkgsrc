$NetBSD: patch-update.c,v 1.1 2013/01/15 15:19:05 joerg Exp $

--- update.c.orig	2013-01-14 16:42:03.000000000 +0000
+++ update.c
@@ -4,6 +4,8 @@
 #include "copyright.h"
 #include "defs.h"
 
+static void update_player(void);
+
 int	plx, ply, burn, playerphase, playerdir, playervert, playerfuel,
 	walk, waiting, exploded, explodetimer;
 
@@ -39,7 +41,7 @@ update()
 
 /*	update_player updates the player
 */
-update_player()
+static void update_player(void)
 {
 	register int	flags;
 
