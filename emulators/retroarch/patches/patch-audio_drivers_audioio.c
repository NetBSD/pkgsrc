$NetBSD: patch-audio_drivers_audioio.c,v 1.2 2020/05/30 14:26:52 nia Exp $

Proper write availability detection for NetBSD

--- audio/drivers/audioio.c.orig	2020-05-27 18:11:31.000000000 +0000
+++ audio/drivers/audioio.c
@@ -186,7 +186,17 @@ static size_t audioio_buffer_size(void *
 
 static size_t audioio_write_avail(void *data)
 {
+#ifdef AUDIO_GETBUFINFO
+   struct audio_info info;
+   int *fd = (int*)data;
+
+   if (ioctl(*fd, AUDIO_GETBUFINFO, &info) < 0)
+      return 0;
+
+   return (info.hiwat * info.blocksize) - info.play.seek;
+#else
    return audioio_buffer_size(data);
+#endif
 }
 
 static bool audioio_use_float(void *data)
