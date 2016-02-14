$NetBSD: patch-media_webrtc_trunk_webrtc_modules_audio__coding_neteq_neteq.gypi,v 1.1 2016/02/14 07:30:54 ryoon Exp $

--- media/webrtc/trunk/webrtc/modules/audio_coding/neteq/neteq.gypi.orig	2015-05-04 00:43:28.000000000 +0000
+++ media/webrtc/trunk/webrtc/modules/audio_coding/neteq/neteq.gypi
@@ -84,19 +84,11 @@
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
