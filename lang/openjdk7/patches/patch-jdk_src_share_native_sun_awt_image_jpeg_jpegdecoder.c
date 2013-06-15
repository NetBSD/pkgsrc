$NetBSD: patch-jdk_src_share_native_sun_awt_image_jpeg_jpegdecoder.c,v 1.1 2013/06/15 09:31:06 jperkin Exp $

Ensure we use the bundled jpeg.

--- jdk/src/share/native/sun/awt/image/jpeg/jpegdecoder.c.orig	2013-02-20 17:07:30.000000000 +0000
+++ jdk/src/share/native/sun/awt/image/jpeg/jpegdecoder.c
@@ -44,7 +44,7 @@
 /* undo "system_boolean" hack and undef FAR since we don't use it anyway */
 #undef boolean
 #undef FAR
-#include <jpeglib.h>
+#include "jpeglib.h"
 #include "jerror.h"
 
 /* The method IDs we cache. Note that the last two belongs to the
