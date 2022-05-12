$NetBSD: patch-src_cairo-quartz-surface.c,v 1.1 2022/05/12 17:13:55 tnn Exp $

Ref and destroy the cairo surface handed off to CoreGraphics.
https://gitlab.freedesktop.org/cairo/cairo/-/merge_requests/52

--- src/cairo-quartz-surface.c.orig	2018-08-17 01:10:53.000000000 +0000
+++ src/cairo-quartz-surface.c
@@ -778,20 +778,10 @@ CairoQuartzCreateGradientFunction (const
 			     &gradient_callbacks);
 }
 
-/* Obtain a CGImageRef from a #cairo_surface_t * */
-
-typedef struct {
-    cairo_surface_t *surface;
-    cairo_image_surface_t *image_out;
-    void *image_extra;
-} quartz_source_image_t;
-
 static void
 DataProviderReleaseCallback (void *info, const void *data, size_t size)
 {
-    quartz_source_image_t *source_img = info;
-    _cairo_surface_release_source_image (source_img->surface, source_img->image_out, source_img->image_extra);
-    free (source_img);
+    free (info);
 }
 
 static cairo_status_t
@@ -803,8 +793,9 @@ _cairo_surface_to_cgimage (cairo_surface
 			   CGImageRef            *image_out)
 {
     cairo_status_t status;
-    quartz_source_image_t *source_img;
     cairo_image_surface_t *image_surface;
+    void *image_data, *image_extra;
+    cairo_bool_t acquired = FALSE;
 
     if (source->backend && source->backend->type == CAIRO_SURFACE_TYPE_QUARTZ_IMAGE) {
 	cairo_quartz_image_surface_t *surface = (cairo_quartz_image_surface_t *) source;
@@ -826,19 +817,12 @@ _cairo_surface_to_cgimage (cairo_surface
 	}
     }
 
-    source_img = _cairo_malloc (sizeof (quartz_source_image_t));
-    if (unlikely (source_img == NULL))
-	return _cairo_error (CAIRO_STATUS_NO_MEMORY);
-
-    source_img->surface = source;
-
     if (source->type == CAIRO_SURFACE_TYPE_RECORDING) {
 	image_surface = (cairo_image_surface_t *)
 	    cairo_image_surface_create (format, extents->width, extents->height);
 	if (unlikely (image_surface->base.status)) {
 	    status = image_surface->base.status;
 	    cairo_surface_destroy (&image_surface->base);
-	    free (source_img);
 	    return status;
 	}
 
@@ -848,46 +832,61 @@ _cairo_surface_to_cgimage (cairo_surface
 							    NULL);
 	if (unlikely (status)) {
 	    cairo_surface_destroy (&image_surface->base);
-	    free (source_img);
 	    return status;
 	}
 
-	source_img->image_out = image_surface;
-	source_img->image_extra = NULL;
-
 	cairo_matrix_init_identity (matrix);
     }
     else {
-	status = _cairo_surface_acquire_source_image (source_img->surface,
-						      &source_img->image_out,
-						      &source_img->image_extra);
-	if (unlikely (status)) {
-	    free (source_img);
+	status = _cairo_surface_acquire_source_image (source, &image_surface,
+						      &image_extra);
+	if (unlikely (status))
 	    return status;
-	}
+	acquired = TRUE;
     }
 
-    if (source_img->image_out->width == 0 || source_img->image_out->height == 0) {
+    if (image_surface->width == 0 || image_surface->height == 0) {
 	*image_out = NULL;
-	DataProviderReleaseCallback (source_img,
-				     source_img->image_out->data,
-				     source_img->image_out->height * source_img->image_out->stride);
-    } else {
-	*image_out = CairoQuartzCreateCGImage (source_img->image_out->format,
-					       source_img->image_out->width,
-					       source_img->image_out->height,
-					       source_img->image_out->stride,
-					       source_img->image_out->data,
-					       TRUE,
-					       NULL,
-					       DataProviderReleaseCallback,
-					       source_img);
-
-	/* TODO: differentiate memory error and unsupported surface type */
-	if (unlikely (*image_out == NULL))
-	    status = CAIRO_INT_STATUS_UNSUPPORTED;
+	if (acquired)
+	    _cairo_surface_release_source_image (source, image_surface, image_extra);
+	else
+	    cairo_surface_destroy (&image_surface->base);
+
+	return status;
     }
 
+    image_data = _cairo_malloc_ab (image_surface->height, image_surface->stride);
+    if (unlikely (!image_data))
+    {
+	if (acquired)
+	    _cairo_surface_release_source_image (source, image_surface, image_extra);
+	else
+	    cairo_surface_destroy (&image_surface->base);
+
+	return _cairo_error (CAIRO_STATUS_NO_MEMORY);
+    }
+
+    memcpy (image_data, image_surface->data,
+	    image_surface->height * image_surface->stride);
+    *image_out = CairoQuartzCreateCGImage (image_surface->format,
+					   image_surface->width,
+					   image_surface->height,
+					   image_surface->stride,
+					   image_data,
+					   TRUE,
+					   NULL,
+					   DataProviderReleaseCallback,
+					   image_data);
+
+    /* TODO: differentiate memory error and unsupported surface type */
+    if (unlikely (*image_out == NULL))
+	status = CAIRO_INT_STATUS_UNSUPPORTED;
+
+    if (acquired)
+	_cairo_surface_release_source_image (source, image_surface, image_extra);
+    else
+	cairo_surface_destroy (&image_surface->base);
+
     return status;
 }
 
@@ -2273,11 +2272,13 @@ _cairo_quartz_surface_create_internal (C
     surface->extents.width = width;
     surface->extents.height = height;
     surface->virtual_extents = surface->extents;
+    surface->imageData = NULL;
+    surface->imageSurfaceEquiv = NULL;
+
 
     if (IS_EMPTY (surface)) {
 	surface->cgContext = NULL;
 	surface->cgContextBaseCTM = CGAffineTransformIdentity;
-	surface->imageData = NULL;
 	surface->base.is_clear = TRUE;
 	return surface;
     }
@@ -2290,9 +2291,6 @@ _cairo_quartz_surface_create_internal (C
     surface->cgContext = cgContext;
     surface->cgContextBaseCTM = CGContextGetCTM (cgContext);
 
-    surface->imageData = NULL;
-    surface->imageSurfaceEquiv = NULL;
-
     return surface;
 }
 
