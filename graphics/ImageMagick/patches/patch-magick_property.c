$NetBSD: patch-magick_property.c,v 1.2 2012/04/09 15:56:21 tez Exp $

* Fix for CVE-2012-0259.
* Fix for CVE-2012-1610.

--- magick/property.c.orig	2012-03-01 01:41:19.000000000 +0000
+++ magick/property.c
@@ -1286,6 +1286,8 @@ static MagickBooleanType GetEXIFProperty
         break;
       components=(ssize_t) ((int) ReadPropertyLong(endian,q+4));
       number_bytes=(size_t) components*tag_bytes[format];
+      if (number_bytes < components)
+        break; /* prevent overflow */
       if (number_bytes <= 4)
         p=q+8;
       else
@@ -1309,6 +1311,8 @@ static MagickBooleanType GetEXIFProperty
             buffer[MaxTextExtent],
             *value;
 
+	  value = NULL;
+	  *buffer = '\0';
           switch (format)
           {
             case EXIF_FMT_BYTE:
