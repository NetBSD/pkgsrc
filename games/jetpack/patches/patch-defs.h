$NetBSD: patch-defs.h,v 1.1 2013/01/15 15:19:05 joerg Exp $

--- defs.h.orig	2013-01-14 16:27:35.000000000 +0000
+++ defs.h
@@ -135,6 +135,8 @@ extern int			xdir[4], ydir[4];
 #define	MEXIT		5
 #define MQUIT		6
 
+void dumb_message(int kind);
+
 /*	Structure used to store the messages triggered in certain areas of a
 	level
 */
@@ -319,3 +321,13 @@ extern int	men, score, bonus, bonustimer
 */
 
 extern int	paused, leveldone, gameover, lastscore;
+extern int usecdelay;
+
+void death(void);
+void demo(void);
+void check_score(void);
+void open_scores(void);
+void place_fuel(int x, int y);
+void place_sweeper(int x, int y, int floor, int rot, int speed);
+void place_guard(int x, int y, int dir, int speed);
+void place_fireball(int x, int y, int dx, int dy);
