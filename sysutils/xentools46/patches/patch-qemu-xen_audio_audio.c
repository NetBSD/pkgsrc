$NetBSD: patch-qemu-xen_audio_audio.c,v 1.1.1.1 2016/07/04 07:30:53 jnemeth Exp $

--- qemu-xen/audio/audio.c.orig	2014-12-02 11:41:02.000000000 +0100
+++ qemu-xen/audio/audio.c	2015-01-19 13:16:38.000000000 +0100
@@ -1173,6 +1173,7 @@
         return 0;
     }
 
+#undef read
     bytes = sw->hw->pcm_ops->read (sw, buf, size);
     return bytes;
 }
