$NetBSD: patch-audio_out_ao__oss.c,v 1.7 2018/10/23 12:14:54 leot Exp $

- ioctl(..., SNDCTL_DSP_CHANNELS, &nchannels) for not supported nchannels does not
  return an error and instead set nchannels to the default value. Instead of
  failing with no audio, fallbacks to stereo.

--- audio/out/ao_oss.c.orig	2018-10-02 19:03:41.000000000 +0000
+++ audio/out/ao_oss.c
@@ -336,19 +336,23 @@ static int reopen_device(struct ao *ao, 
             mp_chmap_sel_add_map(&sel, &oss_layouts[n]);
         if (!ao_chmap_sel_adjust(ao, &sel, &channels))
             goto fail;
-        int reqchannels = channels.num;
+        int nchannels, reqchannels;
+        nchannels = reqchannels = channels.num;
         // We only use SNDCTL_DSP_CHANNELS for >2 channels, in case some drivers don't have it
         if (reqchannels > 2) {
-            int nchannels = reqchannels;
-            if (ioctl(p->audio_fd, SNDCTL_DSP_CHANNELS, &nchannels) == -1 ||
-                nchannels != reqchannels)
-            {
+            if (ioctl(p->audio_fd, SNDCTL_DSP_CHANNELS, &nchannels) == -1) {
                 MP_ERR(ao, "Failed to set audio device to %d channels.\n",
                        reqchannels);
                 goto fail;
             }
         } else {
-            int c = reqchannels - 1;
+            int c;
+            if (nchannels != reqchannels) {
+                // Fallback to stereo
+                c = 1;
+            } else {
+                c = reqchannels - 1;
+            }
             if (ioctl(p->audio_fd, SNDCTL_DSP_STEREO, &c) == -1) {
                 MP_ERR(ao, "Failed to set audio device to %d channels.\n",
                        reqchannels);
