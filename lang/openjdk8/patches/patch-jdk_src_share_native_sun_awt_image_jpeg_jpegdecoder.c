$NetBSD: patch-jdk_src_share_native_sun_awt_image_jpeg_jpegdecoder.c,v 1.2 2015/06/10 11:38:51 tnn Exp $

Ensure we use the bundled jpeg.

--- jdk/src/share/native/sun/awt/image/jpeg/jpegdecoder.c.orig	2015-06-09 13:56:33.000000000 +0000
+++ jdk/src/share/native/sun/awt/image/jpeg/jpegdecoder.c
@@ -44,7 +44,7 @@
 /* undo "system_boolean" hack and undef FAR since we don't use it anyway */
 #undef boolean
 #undef FAR
-#include <jpeglib.h>
+#include "jpeglib.h"
 #include "jerror.h"
 
 #ifdef __APPLE__
