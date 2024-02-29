$NetBSD: patch-src_audio__priv.h,v 1.1 2024/02/29 14:15:41 bsiegert Exp $

Add NetBSD native audio support

--- src/audio_priv.h.orig	2021-07-30 08:54:26.000000000 +0000
+++ src/audio_priv.h
@@ -86,6 +86,15 @@ create_xaudio2_object(const char *device
         const typeof( ((type *)0)->member ) *__mptr = (ptr);    \
         (type *)( (char *)__mptr - offsetof(type,member) );})
 
+#ifdef __NetBSD__
+
+struct audio_object *
+create_netbsd_object(const char *device,
+                  const char *application_name,
+                  const char *description);
+
+#else
+
 #ifdef __APPLE__
 
 struct audio_object *
@@ -117,7 +126,8 @@ create_oss_object(const char *device,
 
 #endif
 #endif
-
+#endif
+  
 #ifdef __cplusplus
 }
 #endif
