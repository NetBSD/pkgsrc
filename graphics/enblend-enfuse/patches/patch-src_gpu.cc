$NetBSD: patch-src_gpu.cc,v 1.1 2012/12/09 00:11:42 adam Exp $

Fix type mismatch.

--- src/gpu.cc.orig	2012-12-08 23:53:14.000000000 +0000
+++ src/gpu.cc
@@ -155,7 +155,7 @@ CGLContextObj cgl_init()
     };
     CGLPixelFormatObj pixel_format = NULL;
     CGLContextObj cgl_context = NULL;
-    long int pixel_formats = 0L;
+    GLint pixel_formats = 0;
     CGLError cgl_error;
 
 
