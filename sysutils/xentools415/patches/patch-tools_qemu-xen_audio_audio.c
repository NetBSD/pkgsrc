$NetBSD: patch-tools_qemu-xen_audio_audio.c,v 1.1 2021/04/18 12:31:26 bouyer Exp $

--- tools/qemu-xen/audio/audio.c.orig	2020-12-08 16:58:46.000000000 +0100
+++ tools/qemu-xen/audio/audio.c	2020-12-09 16:09:37.068801135 +0100
@@ -890,6 +890,7 @@
     if (audio_get_pdo_in(hw->s->dev)->mixing_engine) {
         return audio_pcm_sw_read(sw, buf, size);
     } else {
+#undef read
         return hw->pcm_ops->read(hw, buf, size);
     }
 }
