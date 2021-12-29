$NetBSD: patch-status.c,v 1.1 2021/12/29 23:56:01 nia Exp $

Add return types, from FreeBSD Ports.

--- status.c.orig	1994-03-18 05:12:46.000000000 +0000
+++ status.c
@@ -8,7 +8,7 @@
  * score, the fruit level, and the number of lives remaining.
  */
 
-print_score(incr)
+void print_score(incr)
 long incr;
 {
    static char          string[6];
@@ -48,7 +48,7 @@ int num;
 }
 
 
-display_level(slowly)
+void display_level(slowly)
 Bool slowly;
 {
    int i, xx;
@@ -73,14 +73,14 @@ Bool slowly;
 }
 
 
-display_title()
+void display_title()
 {
    XCopyPlane(display, title, window, fullcopyGC, 0, 0, TITLE_WIDTH,
       TITLE_HEIGHT, 12 * GHOST_SIZE, WIN_HEIGHT + 1, 1);
 }
 
 
-restore_status()
+void restore_status()
 {
    print_score(0L);
    (void)set_lives(lives);
