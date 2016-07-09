$NetBSD: patch-xwin.c,v 1.2 2016/07/09 13:03:00 rillig Exp $

Correct prototype for xdrawrect.

--- xwin.c.orig	2013-01-11 14:30:59.000000000 +0000
+++ xwin.c
@@ -50,7 +50,6 @@ extern int xmainloop();
 extern int xclear();
 extern int xrepaint();
 extern int xrepaint_noclear();
-extern int xdrawrect();
 
 /* internal routines */
 static void help_popup();
@@ -377,10 +376,7 @@ xrepaint_noclear()
 	repaint(xwa.width, xwa.height);
 }
 
-xdrawrect(name, size, x, y, width, height)
-char *name;
-int size;
-int x, y, width, height;
+void xdrawrect(char *name, int size, int x, int y, int width, int height)
 {
 	int	textx, texty;
 	char	label[1024];
