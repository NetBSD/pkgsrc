$NetBSD: patch-mozilla_media_webrtc_trunk_webrtc_modules_audio__coding_codecs_opus_opus.gypi,v 1.1 2015/07/13 17:49:26 ryoon Exp $

--- mozilla/media/webrtc/trunk/webrtc/modules/audio_coding/codecs/opus/opus.gypi.orig	2014-07-18 00:05:42.000000000 +0000
+++ mozilla/media/webrtc/trunk/webrtc/modules/audio_coding/codecs/opus/opus.gypi
@@ -14,9 +14,9 @@
       'conditions': [
         ['build_with_mozilla==1', {
           # Mozilla provides its own build of the opus library.
-          'include_dirs': [
-            '/media/libopus/include',
-           ]
+          'cflags_mozilla': [
+            '$(MOZ_OPUS_CFLAGS)',
+          ],
         }, {
           'dependencies': [
             '<(DEPTH)/third_party/opus/opus.gyp:opus'
