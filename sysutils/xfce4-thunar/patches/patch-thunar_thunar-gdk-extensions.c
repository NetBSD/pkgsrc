$NetBSD: patch-thunar_thunar-gdk-extensions.c,v 1.1 2016/03/13 03:45:53 tnn Exp $

Fix CVE-2013-7447. Via x11/gtk2/patches/patch-gdk_gdkcairo.c.

--- thunar/thunar-gdk-extensions.c.orig	2015-05-22 13:25:36.000000000 +0000
+++ thunar/thunar-gdk-extensions.c
@@ -75,7 +75,7 @@ thunar_gdk_cairo_create_surface (const G
 
   /* prepare pixel data and surface */
   cairo_stride = cairo_format_stride_for_width (format, width);
-  cairo_pixels = g_malloc (height * cairo_stride);
+  cairo_pixels = g_malloc_n (height, cairo_stride);
   surface = cairo_image_surface_create_for_data (cairo_pixels, format,
                                                  width, height, cairo_stride);
   cairo_surface_set_user_data (surface, &cairo_key, cairo_pixels, g_free);
