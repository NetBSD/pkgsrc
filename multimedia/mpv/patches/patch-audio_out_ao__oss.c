$NetBSD: patch-audio_out_ao__oss.c,v 1.6 2017/09/13 10:35:58 leot Exp $

- ioctl(..., SNDCTL_DSP_CHANNELS, &nchannels) for not supported nchannels does not
  return an error and instead set nchannels to the default value. Instead of
  failing with no audio, fallback to stereo or mono.
  Fallback logic inspired by `OSS v3 Programmer's guide', p. 34.

--- audio/out/ao_oss.c.orig	2017-07-22 17:01:42.955374723 +0000
+++ audio/out/ao_oss.c
@@ -332,13 +332,26 @@ static int reopen_device(struct ao *ao, 
         // We only use SNDCTL_DSP_CHANNELS for >2 channels, in case some drivers don't have it
         if (reqchannels > 2) {
             int nchannels = reqchannels;
-            if (ioctl(p->audio_fd, SNDCTL_DSP_CHANNELS, &nchannels) == -1 ||
-                nchannels != reqchannels)
-            {
+            if (ioctl(p->audio_fd, SNDCTL_DSP_CHANNELS, &nchannels) == -1) {
                 MP_ERR(ao, "Failed to set audio device to %d channels.\n",
                        reqchannels);
                 goto fail;
             }
+            if (nchannels != reqchannels) {
+                // Fallback to stereo or mono
+                int c;
+                for (nchannels = c = 2; c >= 1; c--, nchannels--) {
+                    if (ioctl(p->audio_fd, SNDCTL_DSP_CHANNELS, &c) == -1) {
+                        MP_ERR(ao, "Failed to set audio device to %d channels.\n", c);
+                        goto fail;
+                    }
+                    if (c == nchannels)
+                        break;
+                }
+                if (!ao_chmap_sel_get_def(ao, &sel, &channels, c))
+                    goto fail;
+                MP_WARN(ao, "using %d channels (requested: %d)\n", channels.num, reqchannels);
+            }
         } else {
             int c = reqchannels - 1;
             if (ioctl(p->audio_fd, SNDCTL_DSP_STEREO, &c) == -1) {
