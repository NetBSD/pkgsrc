$NetBSD: patch-src_cairo-image-surface.c,v 1.1 2023/11/14 20:43:36 prlw1 Exp $

Don't call a function which is only defined for pixman>=0.39.0 unconditionally

--- src/cairo-image-surface.c.orig	2023-09-23 14:18:32.000000000 +0000
+++ src/cairo-image-surface.c
@@ -951,8 +951,10 @@ _cairo_image_surface_paint (void			*abst
 			    const cairo_clip_t		*clip)
 {
     cairo_image_surface_t *surface = abstract_surface;
+#if PIXMAN_VERSION >= PIXMAN_VERSION_ENCODE(0,39,0)
     pixman_dither_t pixman_dither = _cairo_dither_to_pixman_dither (source->dither);
     pixman_image_set_dither (surface->pixman_image, pixman_dither);
+#endif
 
     TRACE ((stderr, "%s (surface=%d)\n",
 	    __FUNCTION__, surface->base.unique_id));
