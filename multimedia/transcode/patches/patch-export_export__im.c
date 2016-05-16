$NetBSD: patch-export_export__im.c,v 1.1 2016/05/16 19:41:17 adam Exp $

Fix for ImageMagick v7.

--- export/export_im.c.orig	2016-05-15 12:41:44.000000000 +0000
+++ export/export_im.c
@@ -23,7 +23,7 @@
 
 /* Note: because of ImageMagick bogosity, this must be included first, so
  * we can undefine the PACKAGE_* symbols it splats into our namespace */
-#include <magick/api.h>
+#include <MagickCore/MagickCore.h>
 #undef PACKAGE_BUGREPORT
 #undef PACKAGE_NAME
 #undef PACKAGE_STRING
@@ -197,7 +197,7 @@ MOD_encode
 
     strlcpy(image->filename, buf2, MaxTextExtent);
 
-    WriteImage(image_info, image);
+    WriteImage(image_info, image, &exception_info);
     DestroyImage(image);
 
     return(0);
