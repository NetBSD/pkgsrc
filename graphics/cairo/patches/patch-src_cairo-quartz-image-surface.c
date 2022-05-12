$NetBSD: patch-src_cairo-quartz-image-surface.c,v 1.1 2022/05/12 17:13:55 tnn Exp $

Ref and destroy the cairo surface handed off to CoreGraphics.
https://gitlab.freedesktop.org/cairo/cairo/-/merge_requests/52

--- src/cairo-quartz-image-surface.c.orig	2018-08-17 01:10:53.000000000 +0000
+++ src/cairo-quartz-image-surface.c
@@ -50,10 +50,9 @@
 #define SURFACE_ERROR_INVALID_FORMAT (_cairo_surface_create_in_error(_cairo_error(CAIRO_STATUS_INVALID_FORMAT)))
 
 static void
-DataProviderReleaseCallback (void *info, const void *data, size_t size)
+DataProviderReleaseCallback (void *image_info, const void *data, size_t size)
 {
-    cairo_surface_t *surface = (cairo_surface_t *) info;
-    cairo_surface_destroy (surface);
+    free (image_info);
 }
 
 static cairo_surface_t *
@@ -88,9 +87,8 @@ _cairo_quartz_image_surface_finish (void
 {
     cairo_quartz_image_surface_t *surface = (cairo_quartz_image_surface_t *) asurface;
 
-    /* the imageSurface will be destroyed by the data provider's release callback */
     CGImageRelease (surface->image);
-
+    cairo_surface_destroy (surface->imageSurface);
     return CAIRO_STATUS_SUCCESS;
 }
 
@@ -147,24 +145,29 @@ _cairo_quartz_image_surface_flush (void 
     cairo_quartz_image_surface_t *surface = (cairo_quartz_image_surface_t *) asurface;
     CGImageRef oldImage = surface->image;
     CGImageRef newImage = NULL;
-
+    void *image_data;
+    const unsigned int size = surface->imageSurface->height * surface->imageSurface->stride;
     if (flags)
 	return CAIRO_STATUS_SUCCESS;
 
     /* XXX only flush if the image has been modified. */
 
-    /* To be released by the ReleaseCallback */
-    cairo_surface_reference ((cairo_surface_t*) surface->imageSurface);
+    image_data = _cairo_malloc_ab ( surface->imageSurface->height,
+				    surface->imageSurface->stride);
+    if (unlikely (!image_data))
+	return _cairo_error (CAIRO_STATUS_NO_MEMORY);
 
+    memcpy (image_data, surface->imageSurface->data,
+	    surface->imageSurface->height * surface->imageSurface->stride);
     newImage = CairoQuartzCreateCGImage (surface->imageSurface->format,
 					 surface->imageSurface->width,
 					 surface->imageSurface->height,
 					 surface->imageSurface->stride,
-					 surface->imageSurface->data,
+					 image_data,
 					 TRUE,
 					 NULL,
 					 DataProviderReleaseCallback,
-					 surface->imageSurface);
+					 image_data);
 
     surface->image = newImage;
     CGImageRelease (oldImage);
@@ -308,7 +311,7 @@ cairo_quartz_image_surface_create (cairo
     cairo_image_surface_t *image_surface;
     int width, height, stride;
     cairo_format_t format;
-    unsigned char *data;
+    void *image_data;
 
     if (surface->status)
 	return surface;
@@ -321,7 +324,6 @@ cairo_quartz_image_surface_create (cairo
     height = image_surface->height;
     stride = image_surface->stride;
     format = image_surface->format;
-    data = image_surface->data;
 
     if (!_cairo_quartz_verify_surface_size(width, height))
 	return SURFACE_ERROR_INVALID_SIZE;
@@ -338,20 +340,19 @@ cairo_quartz_image_surface_create (cairo
 
     memset (qisurf, 0, sizeof(cairo_quartz_image_surface_t));
 
-    /* In case the create_cgimage fails, this ref will
-     * be released via the callback (which will be called in
-     * case of failure.)
-     */
-    cairo_surface_reference (surface);
+    image_data = _cairo_malloc_ab (height, stride);
+    if (unlikely (!image_data))
+	return _cairo_error (CAIRO_STATUS_NO_MEMORY);
 
+    memcpy (image_data, image_surface->data, height * stride);
     image = CairoQuartzCreateCGImage (format,
 				      width, height,
 				      stride,
-				      data,
+				      image_data,
 				      TRUE,
 				      NULL,
 				      DataProviderReleaseCallback,
-				      image_surface);
+				      image_data);
 
     if (!image) {
 	free (qisurf);
