$NetBSD: patch-zbar_window_x.c,v 1.2 2024/11/25 11:59:23 leot Exp $

Avoid possible ctype(3) undefined behaviours.

--- zbar/window/x.c.orig	2021-03-14 16:28:01.000000000 +0000
+++ zbar/window/x.c
@@ -274,7 +274,7 @@ int _zbar_window_draw_text(zbar_window_t
     XSetForeground(w->display, xs->gc, xs->colors[rgb]);
 
     int n = 0;
-    while (n < 32 && text[n] && isprint(text[n]))
+    while (n < 32 && text[n] && isprint((unsigned char)text[n]))
 	n++;
 
     int width = XTextWidth(xs->font, text, n);
