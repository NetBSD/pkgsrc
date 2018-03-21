$NetBSD: patch-src_console_x11.cc,v 1.1 2018/03/21 17:39:42 kamil Exp $

Fix C++11 literals.

--- src/console/x11.cc.orig	2014-08-17 08:45:15.000000000 +0000
+++ src/console/x11.cc
@@ -374,7 +374,7 @@ void x11_fb_resize(struct fb_window *win
 void x11_set_standard_properties(struct fb_window *fb_window, char *name)
 {
 	XSetStandardProperties(fb_window->x11_display,
-	    fb_window->x11_fb_window, name, "GXemul "VERSION,
+	    fb_window->x11_fb_window, name, "GXemul " VERSION,
 	    None, NULL, 0, NULL);
 }
 
