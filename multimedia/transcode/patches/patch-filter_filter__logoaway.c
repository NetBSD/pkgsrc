$NetBSD: patch-filter_filter__logoaway.c,v 1.1 2016/05/16 19:41:17 adam Exp $

Fix for ImageMagick v7.

--- filter/filter_logoaway.c.orig	2016-05-15 13:00:44.000000000 +0000
+++ filter/filter_logoaway.c
@@ -70,7 +70,7 @@
 
 /* Note: because of ImageMagick bogosity, this must be included first, so
  * we can undefine the PACKAGE_* symbols it splats into our namespace */
-#include <magick/api.h>
+#include <MagickCore/MagickCore.h>
 #undef PACKAGE_BUGREPORT
 #undef PACKAGE_NAME
 #undef PACKAGE_STRING
@@ -204,7 +204,7 @@ static void work_with_rgb_frame(logoaway
     LD->dumpimage = ConstituteImage(LD->width-LD->xpos, LD->height-LD->ypos, "RGB", CharPixel, LD->dump_buf, &LD->exception_info);
     tc_snprintf(LD->dumpimage->filename, MaxTextExtent, "dump[%d].png", LD->id);
 
-    WriteImage(LD->dumpimage_info, LD->dumpimage);
+    WriteImage(LD->dumpimage_info, LD->dumpimage, &LD->exception_info);
   }
 
   switch(LD->mode) {
