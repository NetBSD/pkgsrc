$NetBSD: patch-host_gtk_gtk-screen.c,v 1.1 2020/08/13 06:33:59 tsutsui Exp $

- Check also screen width and height to choose default screen size
  for modern HD and multi display environments

--- host/gtk/gtk-screen.c.orig	2009-08-30 21:39:03.000000000 +0000
+++ host/gtk/gtk-screen.c
@@ -171,6 +171,8 @@ _tme_gtk_screen_mode_change(struct tme_f
   const struct tme_fb_xlat *fb_xlat_a;
   int scale;
   unsigned long fb_area, avail_area, percentage;
+  unsigned long fb_width, fb_height, screen_width, screen_height;
+  unsigned long hpercentage, wpercentage;
   gint width, height;
   gint height_extra;
   const void *map_g_old;
@@ -207,23 +209,32 @@ _tme_gtk_screen_mode_change(struct tme_f
   scale = screen->tme_gtk_screen_fb_scale;
   if (scale < 0) {
 
+    fb_width  = conn_fb_other->tme_fb_connection_width;
+    fb_height = conn_fb_other->tme_fb_connection_height;
+    screen_width  = gdk_screen_width();
+    screen_height = gdk_screen_height();
+
     /* calulate the areas, in square pixels, of the emulated
        framebuffer and the host's screen: */
-    fb_area = (conn_fb_other->tme_fb_connection_width
-	       * conn_fb_other->tme_fb_connection_height);
-    avail_area = (gdk_screen_width()
-		  * gdk_screen_height());
+    fb_area = fb_width * fb_height;
+    avail_area = screen_width * screen_height;
 
     /* see what percentage of the host's screen would be taken up by
        an unscaled emulated framebuffer: */
     percentage = (fb_area * 100) / avail_area;
 
+    /* also check percentage of the actual host's screen width and height
+       for modern HD or multi displays */
+    wpercentage = (fb_width  * 100) / screen_width;
+    hpercentage = (fb_height * 100) / screen_height;
+
     /* if this is at least 70%, halve the emulated framebuffer, else
        if this is 30% or less, double the emulated framebuffer: */
-    if (percentage >= 70) {
+    /* also check screen width and height fit the emulated framebuffer */
+    if (percentage >= 70 || wpercentage > 100 || hpercentage > 100) {
       scale = TME_FB_XLAT_SCALE_HALF;
     }
-    else if (percentage <= 30) {
+    else if (percentage <= 30 && wpercentage <= 50 && hpercentage <= 50) {
       scale = TME_FB_XLAT_SCALE_DOUBLE;
     }
     else {
