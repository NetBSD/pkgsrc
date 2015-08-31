$NetBSD: patch-gdk-pixbuf_pixops_pixops.c,v 1.1 2015/08/31 12:35:53 he Exp $

Add fix for https://bugzilla.gnome.org/show_bug.cgi?id=752297,
also CVE-2015-4491, lifted from

  https://git.gnome.org/browse/gdk-pixbuf/commit/gdk-pixbuf/pixops/pixops.c?id=ffec86ed5010c5a2be14f47b33bcf4ed3169a199
and
  https://git.gnome.org/browse/gdk-pixbuf/commit/?id=8dba67cb4f38d62a47757741ad41e3f245b4a32a

Our loader code is supposed to handle out-of-memory and overflow
situations gracefully, reporting errors instead of aborting. But
if you load an image at a specific size, we also execute our
scaling code, which was not careful enough about overflow in some
places.

This commit makes the scaling code silently return if it fails to
allocate filter tables. This is the best we can do, since
gdk_pixbuf_scale() is not taking a GError.

--- gdk-pixbuf/pixops/pixops.c.orig	2014-03-06 04:36:45.000000000 +0000
+++ gdk-pixbuf/pixops/pixops.c
@@ -1192,7 +1192,20 @@ make_filter_table (PixopsFilter *filter)
   int i_offset, j_offset;
   int n_x = filter->x.n;
   int n_y = filter->y.n;
-  int *weights = g_new (int, SUBSAMPLE * SUBSAMPLE * n_x * n_y);
+  gsize n_weights;
+  int *weights;
+
+  n_weights = SUBSAMPLE * SUBSAMPLE * n_x;
+  if (n_weights / (SUBSAMPLE * SUBSAMPLE) != n_x)
+    return NULL; /* overflow, bail */
+
+  n_weights *= n_y;
+  if (n_weights / (SUBSAMPLE * SUBSAMPLE * n_x) != n_y)
+    return NULL; /* overflow, bail */
+
+  weights = g_try_new (int, n_weights);
+  if (!weights)
+    return NULL; /* overflow, bail */
 
   for (i_offset=0; i_offset < SUBSAMPLE; i_offset++)
     for (j_offset=0; j_offset < SUBSAMPLE; j_offset++)
@@ -1267,8 +1280,11 @@ pixops_process (guchar         *dest_buf
   if (x_step == 0 || y_step == 0)
     return; /* overflow, bail out */
 
-  line_bufs = g_new (guchar *, filter->y.n);
   filter_weights = make_filter_table (filter);
+  if (!filter_weights)
+    return; /* overflow, bail out */
+
+  line_bufs = g_new (guchar *, filter->y.n);
 
   check_shift = check_size ? get_check_shift (check_size) : 0;
 
@@ -1388,7 +1404,7 @@ tile_make_weights (PixopsFilterDimension
 		   double                 scale)
 {
   int n = ceil (1 / scale + 1);
-  double *pixel_weights = g_new (double, SUBSAMPLE * n);
+  double *pixel_weights = g_malloc_n (sizeof (double) * SUBSAMPLE, n);
   int offset;
   int i;
 
@@ -1446,7 +1462,7 @@ bilinear_magnify_make_weights (PixopsFil
     }
 
   dim->n = n;
-  dim->weights = g_new (double, SUBSAMPLE * n);
+  dim->weights = g_malloc_n (sizeof (double) * SUBSAMPLE, n);
 
   pixel_weights = dim->weights;
 
@@ -1537,7 +1553,7 @@ bilinear_box_make_weights (PixopsFilterD
 			   double                 scale)
 {
   int n = ceil (1/scale + 3.0);
-  double *pixel_weights = g_new (double, SUBSAMPLE * n);
+  double *pixel_weights = g_malloc_n (sizeof (double) * SUBSAMPLE, n);
   double w;
   int offset, i;
 
