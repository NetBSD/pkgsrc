$NetBSD: patch-qemu-xen_audio_audio.c,v 1.1 2013/05/26 20:27:43 bouyer Exp $

--- qemu-xen/audio/audio.c.orig	2013-05-26 20:24:36.000000000 +0200
+++ qemu-xen/audio/audio.c	2013-05-26 20:24:39.000000000 +0200
@@ -1162,6 +1162,7 @@
         return 0;
     }
 
+#undef read
     bytes = sw->hw->pcm_ops->read (sw, buf, size);
     return bytes;
 }
