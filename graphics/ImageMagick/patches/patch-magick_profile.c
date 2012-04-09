$NetBSD: patch-magick_profile.c,v 1.1 2012/04/09 15:56:21 tez Exp $

* Fix for CVE-2012-1610.

--- magick/profile.c.orig	2012-04-09 14:19:45.161695800 +0000
+++ magick/profile.c
@@ -6727,8 +6727,10 @@ MagickExport MagickBooleanType SyncImage
       format=(ssize_t) ReadProfileShort(endian,q+2);
       if ((format-1) >= EXIF_NUM_FORMATS)
         break;
-      components=(int) ReadProfileLong(endian,q+4);
+      components=(ssize_t) ((int) ReadProfileLong(endian,q+4));
       number_bytes=(size_t) components*format_bytes[format];
+      if (number_bytes < components)
+        break;  /* prevent overflow */
       if (number_bytes <= 4)
         p=q+8;
       else
