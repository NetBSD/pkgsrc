$NetBSD: patch-jdk_src_share_native_sun_awt_image_jpeg_imageioJPEG.c,v 1.1 2015/02/08 08:41:25 tnn Exp $

patch-jdk_src_share_native_sun_awt_image_jpeg_imageioJPEG.c

--- jdk/src/share/native/sun/awt/image/jpeg/imageioJPEG.c.orig	2015-02-02 15:37:11.000000000 +0000
+++ jdk/src/share/native/sun/awt/image/jpeg/imageioJPEG.c
@@ -50,7 +50,7 @@
 #include "com_sun_imageio_plugins_jpeg_JPEGImageWriter.h"
 
 /* headers from the JPEG library */
-#include <jpeglib.h>
+#include "jpeglib.h"
 #include "jerror.h"
 
 #undef MAX
