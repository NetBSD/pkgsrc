$NetBSD: patch-src-audio-libao.c,v 1.1 2020/12/31 00:34:37 js Exp $

--- src/audio/libao.c.orig	2020-09-08 21:07:47.000000000 +0000
+++ src/audio/libao.c
@@ -253,6 +253,9 @@ spd_audio_plugin_t *libao_plugin_get(voi
 }
 
 spd_audio_plugin_t *SPD_AUDIO_PLUGIN_ENTRY(void)
-    __attribute__ ((weak, alias("libao_plugin_get")));
+#ifndef __MACH__
+    __attribute__ ((weak, alias("libao_plugin_get")))
+#endif
+;
 #undef MSG
 #undef ERR
