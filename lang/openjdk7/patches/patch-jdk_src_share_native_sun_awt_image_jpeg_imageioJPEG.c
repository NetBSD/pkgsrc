$NetBSD: patch-jdk_src_share_native_sun_awt_image_jpeg_imageioJPEG.c,v 1.1 2013/06/15 09:31:06 jperkin Exp $

Ensure we use the bundled jpeg.

--- jdk/src/share/native/sun/awt/image/jpeg/imageioJPEG.c.orig	2013-02-20 17:07:30.000000000 +0000
+++ jdk/src/share/native/sun/awt/image/jpeg/imageioJPEG.c
@@ -50,7 +50,7 @@
 #include "com_sun_imageio_plugins_jpeg_JPEGImageWriter.h"
 
 /* headers from the JPEG library */
-#include <jpeglib.h>
+#include "jpeglib.h"
 #include "jerror.h"
 
 #undef MAX
