$NetBSD: patch-qemu-xen_audio_audio.c,v 1.2 2015/08/23 16:17:12 spz Exp $

--- qemu-xen/audio/audio.c.orig	2013-10-10 14:15:47.000000000 +0000
+++ qemu-xen/audio/audio.c
@@ -1162,6 +1162,7 @@ int AUD_read (SWVoiceIn *sw, void *buf, 
         return 0;
     }
 
+#undef read
     bytes = sw->hw->pcm_ops->read (sw, buf, size);
     return bytes;
 }
