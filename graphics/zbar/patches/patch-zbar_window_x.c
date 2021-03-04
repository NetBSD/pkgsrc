$NetBSD: patch-zbar_window_x.c,v 1.1 2021/03/04 10:34:24 leot Exp $

Avoid possible ctype(3) undefined behaviours.

--- zbar/window/x.c.orig	2021-02-13 09:39:55.000000000 +0000
+++ zbar/window/x.c
@@ -288,7 +288,7 @@ int _zbar_window_draw_text (zbar_window_
     XSetForeground(w->display, xs->gc, xs->colors[rgb]);
 
     int n = 0;
-    while(n < 32 && text[n] && isprint(text[n]))
+    while(n < 32 && text[n] && isprint((unsigned char)text[n]))
         n++;
 
     int width = XTextWidth(xs->font, text, n);
