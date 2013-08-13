$NetBSD: patch-oss.c,v 1.1 2013/08/13 00:45:50 khorben Exp $

--- oss.c.orig	2006-07-13 10:13:03.000000000 +0000
+++ oss.c
@@ -336,9 +336,9 @@ oss_open_audio(AFormat fmt, int rate, in
 	if (config->oss_use_alt_audio_device && (config->oss_alt_audio_device != NULL))
 		device_name = g_strdup(config->oss_alt_audio_device);
 	else if (config->oss_audio_device > 0)
-		device_name = g_strdup_printf("/dev/dsp%d", config->oss_audio_device);
+		device_name = g_strdup_printf(DEFAULT_OSS_ALT_AUDIO_DEVICE "%d", config->oss_audio_device);
 	else
-		device_name = g_strdup("/dev/dsp");
+		device_name = g_strdup(DEFAULT_OSS_ALT_AUDIO_DEVICE);
 
 	/* HACK: Test if the device is not locked by another process. This is
 	 *       just a crude workaround to avoid complete lockup of XMMS. It is
