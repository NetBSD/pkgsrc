$NetBSD: patch-audio_drivers_audioio.c,v 1.1 2019/05/11 11:56:33 nia Exp $

Attempt to improve the portability of the Sun audio driver.

--- audio/drivers/audioio.c.orig	2019-05-08 06:06:22.000000000 +0000
+++ audio/drivers/audioio.c
@@ -47,6 +47,8 @@ static void *audioio_init(const char *de
 
 #ifdef AUMODE_PLAY_ALL
    info.mode = AUMODE_PLAY_ALL;
+#elif defined(AUMODE_PLAY)
+   info.mode = AUMODE_PLAY;
 #endif
    info.play.sample_rate = rate;
    info.play.channels = 2;
@@ -104,8 +106,10 @@ static bool audioio_stop(void *data)
    struct audio_info info;
    int *fd = (int*)data;
 
+#ifdef AUDIO_FLUSH
    if (ioctl(*fd, AUDIO_FLUSH, NULL) < 0)
       return false;
+#endif
 
    if (ioctl(*fd, AUDIO_GETINFO, &info) < 0)
       return false;
@@ -120,8 +124,10 @@ static bool audioio_start(void *data, bo
    struct audio_info info;
    int *fd = (int*)data;
 
+#ifdef AUDIO_FLUSH
    if (ioctl(*fd, AUDIO_FLUSH, NULL) < 0)
       return false;
+#endif
 
    if (ioctl(*fd, AUDIO_GETINFO, &info) < 0)
       return false;
@@ -159,7 +165,9 @@ static void audioio_free(void *data)
 {
    int *fd = (int*)data;
 
+#ifdef AUDIO_FLUSH
    (void)ioctl(*fd, AUDIO_FLUSH, NULL);
+#endif
 
    close(*fd);
    free(fd);
