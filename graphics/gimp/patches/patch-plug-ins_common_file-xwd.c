$NetBSD: patch-plug-ins_common_file-xwd.c,v 1.1 2014/05/21 13:50:22 he Exp $

Sanity check colormap size (CVE-2013-1913), valid range is 0 .. 256.
Sanity check # of colors and map entries (CVE-2013-1978)

The number of colors in an image shouldn't be higher than the number of
colormap entries. Additionally, consolidate post error cleanup in
load_image().

From 
https://git.gnome.org/browse/gimp/patch/?id=32ae0f83e5748299641cceaabe3f80f1b3afd03e
and
https://git.gnome.org/browse/gimp/patch/?id=23f685931e5f000dd033a45c60c1e60d7f78caf4

--- plug-ins/common/file-xwd.c.orig	2013-11-10 15:37:53.000000000 +0000
+++ plug-ins/common/file-xwd.c
@@ -424,9 +424,9 @@ static gint32
 load_image (const gchar  *filename,
             GError      **error)
 {
-  FILE            *ifp;
+  FILE            *ifp = NULL;
   gint             depth, bpp;
-  gint32           image_ID;
+  gint32           image_ID = -1;
   L_XWDFILEHEADER  xwdhdr;
   L_XWDCOLOR      *xwdcolmap = NULL;
 
@@ -436,7 +436,7 @@ load_image (const gchar  *filename,
       g_set_error (error, G_FILE_ERROR, g_file_error_from_errno (errno),
                    _("Could not open '%s' for reading: %s"),
                    gimp_filename_to_utf8 (filename), g_strerror (errno));
-      return -1;
+      goto out;
     }
 
   read_xwd_header (ifp, &xwdhdr);
@@ -445,8 +445,7 @@ load_image (const gchar  *filename,
       g_set_error (error, G_FILE_ERROR, G_FILE_ERROR_FAILED,
                    _("Could not read XWD header from '%s'"),
                    gimp_filename_to_utf8 (filename));
-      fclose (ifp);
-      return -1;
+      goto out;
     }
 
 #ifdef XWD_COL_WAIT_DEBUG
@@ -461,8 +460,25 @@ load_image (const gchar  *filename,
   /* Position to start of XWDColor structures */
   fseek (ifp, (long)xwdhdr.l_header_size, SEEK_SET);
 
+  /* Guard against insanely huge color maps -- gimp_image_set_colormap() only
+   * accepts colormaps with 0..256 colors anyway. */
+   if (xwdhdr.l_colormap_entries > 256)
+     {
+       g_message (_("'%s':\nIllegal number of colormap entries: %ld"),
+		  gimp_filename_to_utf8 (filename),
+		  (long)xwdhdr.l_colormap_entries);
+       goto out;
+     }
+
   if (xwdhdr.l_colormap_entries > 0)
     {
+      if (xwdhdr.l_colormap_entries < xwdhdr.l_ncolors)
+      {
+        g_message (_("'%s':\nNumber of colormap entries < number of colors"),
+		   gimp_filename_to_utf8 (filename));
+        goto out;
+      }
+
       xwdcolmap = g_new (L_XWDCOLOR, xwdhdr.l_colormap_entries);
 
       read_xwd_cols (ifp, &xwdhdr, xwdcolmap);
@@ -482,9 +498,7 @@ load_image (const gchar  *filename,
       if (xwdhdr.l_file_version != 7)
         {
           g_message (_("Can't read color entries"));
-          g_free (xwdcolmap);
-          fclose (ifp);
-          return (-1);
+          goto out;
         }
     }
 
@@ -492,9 +506,7 @@ load_image (const gchar  *filename,
     {
       g_message (_("'%s':\nNo image width specified"),
                  gimp_filename_to_utf8 (filename));
-      g_free (xwdcolmap);
-      fclose (ifp);
-      return (-1);
+      goto out;
     }
 
   if (xwdhdr.l_pixmap_width > GIMP_MAX_IMAGE_SIZE
@@ -502,27 +514,21 @@ load_image (const gchar  *filename,
     {
       g_message (_("'%s':\nImage width is larger than GIMP can handle"),
                  gimp_filename_to_utf8 (filename));
-      g_free (xwdcolmap);
-      fclose (ifp);
-      return (-1);
+      goto out;
     }
 
   if (xwdhdr.l_pixmap_height <= 0)
     {
       g_message (_("'%s':\nNo image height specified"),
                  gimp_filename_to_utf8 (filename));
-      g_free (xwdcolmap);
-      fclose (ifp);
-      return (-1);
+      goto out;
     }
 
   if (xwdhdr.l_pixmap_height > GIMP_MAX_IMAGE_SIZE)
     {
       g_message (_("'%s':\nImage height is larger than GIMP can handle"),
                  gimp_filename_to_utf8 (filename));
-      g_free (xwdcolmap);
-      fclose (ifp);
-      return (-1);
+      goto out;
     }
 
   gimp_progress_init_printf (_("Opening '%s'"),
@@ -571,11 +577,6 @@ load_image (const gchar  *filename,
     }
   gimp_progress_update (1.0);
 
-  fclose (ifp);
-
-  if (xwdcolmap)
-    g_free (xwdcolmap);
-
   if (image_ID == -1 && ! (error && *error))
     g_set_error (error, G_FILE_ERROR, G_FILE_ERROR_FAILED,
                  _("XWD-file %s has format %d, depth %d and bits per pixel %d. "
@@ -583,6 +584,17 @@ load_image (const gchar  *filename,
                  gimp_filename_to_utf8 (filename),
                  (gint) xwdhdr.l_pixmap_format, depth, bpp);
 
+out:
+  if (ifp)
+    {
+      fclose (ifp);
+    }
+
+  if (xwdcolmap)
+    {
+      g_free (xwdcolmap);
+    }
+
   return image_ID;
 }
 
