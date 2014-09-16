$NetBSD: patch-audio_out_ao__oss.c,v 1.2 2014/09/16 21:44:52 wiz Exp $

https://github.com/mpv-player/mpv/issues/1080

--- audio/out/ao_oss.c.orig	2014-08-26 08:27:40.000000000 +0000
+++ audio/out/ao_oss.c
@@ -450,7 +450,7 @@ static void drain(struct ao *ao)
 #endif
 }
 
-#ifndef SNDCTL_DSP_RESET
+#if !defined(SNDCTL_DSP_RESET) || defined(__NetBSD__) 
 static void close_device(struct ao *ao)
 {
     struct priv *p = ao->priv;
@@ -464,7 +464,7 @@ static void reset(struct ao *ao)
 {
     struct priv *p = ao->priv;
     int oss_format;
-#ifdef SNDCTL_DSP_RESET
+#if defined(SNDCTL_DSP_RESET) && !defined(__NetBSD__)
     ioctl(p->audio_fd, SNDCTL_DSP_RESET, NULL);
 #else
     close_device(ao);
@@ -502,6 +502,9 @@ static int get_space(struct ao *ao)
     struct priv *p = ao->priv;
     int playsize = p->outburst;
 
+    if (p->audio_fd < 0)
+    	return p->outburst / ao->sstride;
+
 #ifdef SNDCTL_DSP_GETOSPACE
     if (ioctl(p->audio_fd, SNDCTL_DSP_GETOSPACE, &p->zz) != -1) {
         // calculate exact buffer space:
@@ -531,8 +534,12 @@ static int get_space(struct ao *ao)
 static void audio_pause(struct ao *ao)
 {
     struct priv *p = ao->priv;
+
+    if (p->audio_fd < 0)
+	return;
+
     p->prepause_space = get_space(ao) * ao->sstride;
-#ifdef SNDCTL_DSP_RESET
+#if defined(SNDCTL_DSP_RESET) && !defined(__NetBSD__)
     ioctl(p->audio_fd, SNDCTL_DSP_RESET, NULL);
 #else
     close_device(ao);
@@ -552,7 +559,10 @@ static int play(struct ao *ao, void **da
         len /= p->outburst;
         len *= p->outburst;
     }
-    len = write(p->audio_fd, data[0], len);
+
+    if (p->audio_fd >= 0)
+        len = write(p->audio_fd, data[0], len);
+
     return len / ao->sstride;
 }
 
@@ -560,9 +570,15 @@ static int play(struct ao *ao, void **da
 static void audio_resume(struct ao *ao)
 {
     struct priv *p = ao->priv;
-#ifndef SNDCTL_DSP_RESET
+#if !defined (SNDCTL_DSP_RESET) || defined(__NetBSD__)
     reset(ao);
 #endif
+    if (p->audio_fd < 0) {
+	ao->untimed = true;
+	return;
+    } else
+	ao->untimed=false;
+
     int fillframes = get_space(ao) - p->prepause_space / ao->sstride;
     if (fillframes > 0)
         ao_play_silence(ao, fillframes);
@@ -572,6 +588,10 @@ static void audio_resume(struct ao *ao)
 static float get_delay(struct ao *ao)
 {
     struct priv *p = ao->priv;
+
+    if (p->audio_fd < 0)
+	return 0.0250;
+
     /* Calculate how many bytes/second is sent out */
     if (p->audio_delay_method == 2) {
 #ifdef SNDCTL_DSP_GETODELAY
