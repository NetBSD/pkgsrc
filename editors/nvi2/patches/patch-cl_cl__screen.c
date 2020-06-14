$NetBSD: patch-cl_cl__screen.c,v 1.1 2020/06/14 11:44:02 nia Exp $

This is only valid in ncurses

--- cl/cl_screen.c.orig	2015-04-08 21:20:21.000000000 +0000
+++ cl/cl_screen.c
@@ -409,9 +409,6 @@ cl_vi_end(GS *gp)
 	/* End curses window. */
 	(void)endwin();
 
-	/* Free the SCREEN created by newterm(3X). */
-	delscreen(set_term(NULL));
-
 	/*
 	 * XXX
 	 * The screen TE sequence just got sent.  See the comment in
