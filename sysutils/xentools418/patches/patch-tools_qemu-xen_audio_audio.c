$NetBSD: patch-tools_qemu-xen_audio_audio.c,v 1.1 2023/11/21 11:37:03 bouyer Exp $

--- tools/qemu-xen/audio/audio.c.orig	2023-08-16 11:43:53.000000000 +0200
+++ tools/qemu-xen/audio/audio.c	2023-10-12 12:59:41.625600778 +0200
@@ -895,6 +895,7 @@
     if (audio_get_pdo_in(hw->s->dev)->mixing_engine) {
         return audio_pcm_sw_read(sw, buf, size);
     } else {
+#undef read
         return hw->pcm_ops->read(hw, buf, size);
     }
 }
@@ -2158,12 +2159,13 @@
 void audio_parse_option(const char *opt)
 {
     Audiodev *dev = NULL;
+    Visitor *v;
 
     if (is_help_option(opt)) {
         audio_help();
         exit(EXIT_SUCCESS);
     }
-    Visitor *v = qobject_input_visitor_new_str(opt, "driver", &error_fatal);
+    v = qobject_input_visitor_new_str(opt, "driver", &error_fatal);
     visit_type_Audiodev(v, NULL, &dev, &error_fatal);
     visit_free(v);
 
