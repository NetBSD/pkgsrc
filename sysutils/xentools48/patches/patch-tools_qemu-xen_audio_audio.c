$NetBSD: patch-tools_qemu-xen_audio_audio.c,v 1.1 2017/03/30 09:15:10 bouyer Exp $

--- tools/qemu-xen/audio/audio.c.orig	2016-11-24 13:24:26.000000000 +0100
+++ tools/qemu-xen/audio/audio.c	2017-03-24 18:11:17.000000000 +0100
@@ -1156,6 +1156,7 @@
         return 0;
     }
 
+#undef read
     return sw->hw->pcm_ops->read(sw, buf, size);
 }
 
