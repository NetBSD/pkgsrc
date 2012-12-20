$NetBSD: patch-xspell.h,v 1.1 2012/12/20 22:04:14 joerg Exp $

--- xspell.h.orig	2012-12-20 17:55:01.000000000 +0000
+++ xspell.h
@@ -138,3 +138,6 @@ extern game *gameval;
 extern int turnstate;
 extern int movelist[];
 extern int blinklevel;
+
+void query_motion(struct player *py, int xpos, int ypos, int button);
+void gesture_motion(struct player *py, int xpos, int ypos, int button);
