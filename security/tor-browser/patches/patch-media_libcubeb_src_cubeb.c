$NetBSD: patch-media_libcubeb_src_cubeb.c,v 1.1 2016/02/14 07:30:54 ryoon Exp $

--- media/libcubeb/src/cubeb.c.orig	2014-10-11 09:06:39.000000000 +0000
+++ media/libcubeb/src/cubeb.c
@@ -54,6 +54,9 @@ int opensl_init(cubeb ** context, char c
 #if defined(USE_AUDIOTRACK)
 int audiotrack_init(cubeb ** context, char const * context_name);
 #endif
+#if defined(USE_OSS)
+int oss_init(cubeb ** context, char const * context_name);
+#endif
 
 int
 validate_stream_params(cubeb_stream_params stream_params)
@@ -120,6 +123,9 @@ cubeb_init(cubeb ** context, char const 
 #if defined(USE_AUDIOTRACK)
     audiotrack_init,
 #endif
+#if defined(USE_OSS)
+    oss_init,
+#endif
   };
   int i;
 
