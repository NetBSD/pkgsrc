$NetBSD: patch-src_audio.c,v 1.1 2024/02/29 14:15:41 bsiegert Exp $

Add NetBSD native audio support

--- src/audio.c.orig	2017-01-08 13:01:50.000000000 +0000
+++ src/audio.c
@@ -94,7 +94,10 @@ create_audio_device_object(const char *d
 #if defined(__APPLE__)
 	if ((object = create_coreaudio_object(device, application_name, description)) != NULL)
 		return object;
-
+#else
+#if defined(__NetBSD__)       
+	if ((object = create_netbsd_object(device, application_name, description)) != NULL)
+		return object;
 #else
 	if ((object = create_pulseaudio_object(device, application_name, description)) != NULL)
 		return object;
@@ -106,5 +109,6 @@ create_audio_device_object(const char *d
 		return object;
 #endif
 #endif
+#endif
 	return NULL;
 }
