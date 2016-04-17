$NetBSD: patch-mozilla_media_webrtc_trunk_webrtc_modules_audio__coding_neteq_neteq.gypi,v 1.2 2016/04/17 18:33:50 ryoon Exp $

--- mozilla/media/webrtc/trunk/webrtc/modules/audio_coding/neteq/neteq.gypi.orig	2016-04-07 21:33:23.000000000 +0000
+++ mozilla/media/webrtc/trunk/webrtc/modules/audio_coding/neteq/neteq.gypi
@@ -85,19 +85,11 @@
           ],
 	}],
         ['build_with_mozilla==1', {
-          'include_dirs': [
-            # Need Opus header files for the audio classifier.
-            '<(DEPTH)/../../../media/opus/celt',
-#            '<(DEPTH)/third_party/opus/src/src',
+          'cflags_mozilla': [
+            '$(filter -I%, $(MOZ_CELT_CFLAGS))/celt',
+            '$(MOZ_OPUS_CFLAGS)',
+            '$(filter -I%, $(MOZ_OPUS_CFLAGS))/../src',
           ],
-          'direct_dependent_settings': {
-            'include_dirs': [
-              '../../../../../../media/opus/celt',
-              # Need Opus header files for the audio classifier.
-              '<(DEPTH)/../../../media/opus/celt',
-#              '<(DEPTH)/third_party/opus/src/src',
-            ],
-          },
         }],
       ],
       'sources': [
