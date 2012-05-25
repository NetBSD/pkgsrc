$NetBSD: patch-babl_babl-fish-reference.c,v 1.1 2012/05/25 07:37:21 jdc Exp $

Fix a segmentation fault when generating documentation.  See:

  https://bugzilla.gnome.org/show_bug.cgi?id=676491

--- babl/babl-fish-reference.c.dist	2012-03-18 15:51:42.000000000 +0000
+++ babl/babl-fish-reference.c	2012-05-21 12:12:38.000000000 +0000
@@ -137,10 +137,11 @@
             }
         }
 
-      babl_process (
-        assert_conversion_find (src_img->type[0], dst_img->type[0]),
-        src_img, dst_img,
-        n);
+      if (dst_img->data[0] != NULL)
+        babl_process (
+          assert_conversion_find (src_img->type[0], dst_img->type[0]),
+          src_img, dst_img,
+          n);
       src_img->data[0] += src_img->type[0]->bits / 8;
     }
   babl_free (src_img);
