$NetBSD: patch-media_libcubeb_src_cubeb.c,v 1.3 2020/06/15 15:44:22 nia Exp $

--- media/libcubeb/src/cubeb.c.orig	2020-06-02 14:07:57.000000000 +0000
+++ media/libcubeb/src/cubeb.c
@@ -51,6 +51,9 @@ int wasapi_init(cubeb ** context, char c
 #if defined(USE_SNDIO)
 int sndio_init(cubeb ** context, char const * context_name);
 #endif
+#if defined(USE_SUN)
+int sun_init(cubeb ** context, char const * context_name);
+#endif
 #if defined(USE_OPENSL)
 int opensl_init(cubeb ** context, char const * context_name);
 #endif
@@ -195,6 +198,9 @@ cubeb_init(cubeb ** context, char const 
 #if defined(USE_SNDIO)
     sndio_init,
 #endif
+#if defined(USE_SUN)
+    sun_init,
+#endif
 #if defined(USE_OPENSL)
     opensl_init,
 #endif
