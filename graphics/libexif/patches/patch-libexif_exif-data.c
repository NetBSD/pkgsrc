$NetBSD: patch-libexif_exif-data.c,v 1.1 2018/10/13 10:17:30 leot Exp $

Backport patch to fix CVE-2017-7544 from upstream commit id
c39acd1692023b26290778a02a9232c873f9d71a:

 <https://github.com/libexif/libexif/commit/c39acd1692023b26290778a02a9232c873f9d71a>

On saving makernotes, make sure the makernote container tags has a type with 1
byte components.

Fixes (at least):
 https://sourceforge.net/p/libexif/bugs/130
 https://sourceforge.net/p/libexif/bugs/129

--- libexif/exif-data.c.orig	2012-07-12 18:31:56.000000000 +0000
+++ libexif/exif-data.c
@@ -255,6 +255,12 @@ exif_data_save_data_entry (ExifData *dat
 			exif_mnote_data_set_offset (data->priv->md, *ds - 6);
 			exif_mnote_data_save (data->priv->md, &e->data, &e->size);
 			e->components = e->size;
+			if (exif_format_get_size (e->format) != 1) {
+				/* e->format is taken from input code,
+				 * but we need to make sure it is a 1 byte
+				 * entity due to the multiplication below. */
+				e->format = EXIF_FORMAT_UNDEFINED;
+			}
 		}
 	}
 
