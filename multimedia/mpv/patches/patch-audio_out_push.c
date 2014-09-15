$NetBSD: patch-audio_out_push.c,v 1.1 2014/09/15 17:31:18 wiz Exp $

https://github.com/mpv-player/mpv/issues/1080

--- audio/out/push.c.orig	2014-08-26 08:27:40.000000000 +0000
+++ audio/out/push.c
@@ -296,7 +296,7 @@ static void *playthread(void *arg)
         // Request new data from decoder if buffer goes below "full".
         // Allow a small margin of missing data for AOs that use timeouts.
         double margin = ao->driver->wait ? 0 : ao->device_buffer / 8;
-        if (!p->buffers_full && unlocked_get_space(ao) > margin) {
+        if (!p->paused && !p->buffers_full && unlocked_get_space(ao) > margin) {
             if (!p->requested_data)
                 mp_input_wakeup(ao->input_ctx);
             p->requested_data = true;
