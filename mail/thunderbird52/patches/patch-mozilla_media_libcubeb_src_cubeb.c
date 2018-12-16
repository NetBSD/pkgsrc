$NetBSD: patch-mozilla_media_libcubeb_src_cubeb.c,v 1.1 2018/12/16 08:29:48 ryoon Exp $

--- mozilla/media/libcubeb/src/cubeb.c.orig	2017-04-14 04:53:18.000000000 +0000
+++ mozilla/media/libcubeb/src/cubeb.c
@@ -54,6 +54,9 @@ int audiotrack_init(cubeb ** context, ch
 #if defined(USE_KAI)
 int kai_init(cubeb ** context, char const * context_name);
 #endif
+#if defined(USE_OSS)
+int oss_init(cubeb ** context, char const * context_name);
+#endif
 
 
 static int
@@ -141,6 +144,9 @@ cubeb_init(cubeb ** context, char const 
 #if defined(USE_KAI)
     kai_init,
 #endif
+#if defined(USE_OSS)
+    oss_init,
+#endif
   };
   int i;
 
