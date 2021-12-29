$NetBSD: patch-demo.c,v 1.1 2021/12/29 23:56:01 nia Exp $

Add return types. from FreeBSD Ports.

--- demo.c.orig	1994-03-18 05:12:23.000000000 +0000
+++ demo.c
@@ -6,7 +6,7 @@
  * for the game.
  */
 
-demo_seq()
+void demo_seq()
 {
    int             i, xx, yy, direction, ascent, descent, len;
    XCharStruct     chars;
@@ -127,7 +127,7 @@ demo_seq()
       if (event.xany.window != window) continue;
       switch (event.type) {
          case KeyPress:
-	    XLookupString(&event, &c_buf, 1, &last_key, &status);
+	    XLookupString((XKeyEvent *) &event, &c_buf, 1, &last_key, &status);
 	    if ((last_key == XK_q) || (last_key == XK_Q))
 	       do_exit();
 	    XFillRectangle(display, window, clearGC, 0, 0, WIN_WIDTH,
