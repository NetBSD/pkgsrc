$NetBSD: patch-rsvg-image.h,v 1.2 2012/07/08 21:54:04 wiz Exp $

rsvg_get_file_path is an externally visible function.
Fixes NetBSD-5.1/amd64 build.
https://bugzilla.gnome.org/show_bug.cgi?id=679603

--- rsvg-image.h.orig	2012-02-06 19:44:12.000000000 +0000
+++ rsvg-image.h
@@ -51,7 +51,6 @@ struct _RsvgNodeImage {
 G_GNUC_INTERNAL
 void rsvg_preserve_aspect_ratio (unsigned int aspect_ratio, double width,
                                  double height, double *w, double *h, double *x, double *y);
-G_GNUC_INTERNAL
 gchar *rsvg_get_file_path (const gchar * filename, const gchar * basedir);
 G_GNUC_INTERNAL
 cairo_surface_t *rsvg_cairo_surface_new_from_href (RsvgHandle *handle, const char *href, GError ** error);
