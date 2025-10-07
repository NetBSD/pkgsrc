$NetBSD: patch-jdk_src_share_native_sun_awt_image_jpeg_imageioJPEG.c,v 1.3 2025/10/07 15:19:26 ryoon Exp $

Ensure we use the bundled jpeg.

Fix build with GCC 14. freeArray() requires the explicit cast.

--- jdk/src/share/native/sun/awt/image/jpeg/imageioJPEG.c.orig	2025-04-19 16:48:54.000000000 +0000
+++ jdk/src/share/native/sun/awt/image/jpeg/imageioJPEG.c
@@ -50,7 +50,7 @@
 #include "com_sun_imageio_plugins_jpeg_JPEGImageWriter.h"
 
 /* headers from the JPEG library */
-#include <jpeglib.h>
+#include "jpeglib.h"
 #include "jerror.h"
 
 #undef MAX
@@ -2854,14 +2854,14 @@ Java_com_sun_imageio_plugins_jpeg_JPEGIm
     pb = &data->pixelBuf;
 
     if (setPixelBuffer(env, pb, buffer) == NOT_OK) {
-        freeArray(scale, numBands);
+        freeArray((void **)scale, numBands);
         return data->abortFlag;  // We already threw an out of memory exception
     }
 
     // Allocate a 1-scanline buffer
     scanLinePtr = (JSAMPROW)malloc(scanLineSize);
     if (scanLinePtr == NULL) {
-        freeArray(scale, numBands);
+        freeArray((void **)scale, numBands);
         JNU_ThrowByName( env,
                          "java/lang/OutOfMemoryError",
                          "Writing JPEG Stream");
@@ -2883,7 +2883,7 @@ Java_com_sun_imageio_plugins_jpeg_JPEGIm
             JNU_ThrowByName(env, "javax/imageio/IIOException", buffer);
         }
 
-        freeArray(scale, numBands);
+        freeArray((void **)scale, numBands);
         free(scanLinePtr);
         return data->abortFlag;
     }
@@ -2932,7 +2932,7 @@ Java_com_sun_imageio_plugins_jpeg_JPEGIm
         (*env)->ReleaseIntArrayElements(env, QtableSelectors, qsels, JNI_ABORT);
     }
     if (!success) {
-        freeArray(scale, numBands);
+        freeArray((void **)scale, numBands);
         free(scanLinePtr);
         return data->abortFlag;
     }
@@ -2953,7 +2953,7 @@ Java_com_sun_imageio_plugins_jpeg_JPEGIm
     if (GET_ARRAYS(env, data,
                    (const JOCTET **)(&dest->next_output_byte)) == NOT_OK) {
         (*env)->ExceptionClear(env);
-        freeArray(scale, numBands);
+        freeArray((void **)scale, numBands);
         free(scanLinePtr);
         JNU_ThrowByName(env,
                         "javax/imageio/IIOException",
@@ -2991,7 +2991,7 @@ Java_com_sun_imageio_plugins_jpeg_JPEGIm
             scanData = (*env)->GetIntArrayElements(env, scanInfo, NULL);
             if (scanData == NULL) {
                 RELEASE_ARRAYS(env, data, (const JOCTET *)(dest->next_output_byte));
-                freeArray(scale, numBands);
+                freeArray((void **)scale, numBands);
                 free(scanLinePtr);
                 return data->abortFlag;
             }
@@ -3090,7 +3090,7 @@ Java_com_sun_imageio_plugins_jpeg_JPEGIm
         jpeg_abort((j_common_ptr)cinfo);
     }
 
-    freeArray(scale, numBands);
+    freeArray((void **)scale, numBands);
     free(scanLinePtr);
     RELEASE_ARRAYS(env, data, NULL);
     return data->abortFlag;
