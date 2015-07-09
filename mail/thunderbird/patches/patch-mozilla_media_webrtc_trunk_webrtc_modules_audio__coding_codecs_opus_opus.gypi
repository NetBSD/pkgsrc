$NetBSD: patch-mozilla_media_webrtc_trunk_webrtc_modules_audio__coding_codecs_opus_opus.gypi,v 1.2 2015/07/09 15:17:34 ryoon Exp $

--- mozilla/media/webrtc/trunk/webrtc/modules/audio_coding/codecs/opus/opus.gypi.orig	2015-06-08 17:49:24.000000000 +0000
+++ mozilla/media/webrtc/trunk/webrtc/modules/audio_coding/codecs/opus/opus.gypi
@@ -17,18 +17,11 @@
       'conditions': [
         ['build_with_mozilla==1', {
           # Mozilla provides its own build of the opus library.
-          'include_dirs': [
-            '/media/libopus/include',
-            '/media/libopus/src',
-            '/media/libopus/celt',
+          'cflags_mozilla': [
+            '$(filter -I%, $(MOZ_CELT_CFLAGS))/celt',
+            '$(MOZ_OPUS_CFLAGS)',
+            '$(filter -I%, $(MOZ_OPUS_CFLAGS))/../src',
           ],
-          'direct_dependent_settings': {
-            'include_dirs': [
-              '/media/libopus/include',
-              '/media/libopus/src',
-              '/media/libopus/celt',
-            ],
-          },
         }, {
           'dependencies': [
             '<(DEPTH)/third_party/opus/opus.gyp:opus'
