$NetBSD: patch-media_webrtc_trunk_third__party_libyuv_libyuv.gyp,v 1.1 2013/05/19 08:47:41 ryoon Exp $

--- media/webrtc/trunk/third_party/libyuv/libyuv.gyp.orig	2013-05-11 19:19:44.000000000 +0000
+++ media/webrtc/trunk/third_party/libyuv/libyuv.gyp
@@ -9,6 +9,7 @@
 {
   'variables': {
      'use_system_libjpeg%': 0,
+     'yuv_disable_asm%': 0,
   },
   'targets': [
     {
@@ -50,6 +51,11 @@
         ],
       },
       'conditions': [
+        ['yuv_disable_asm==1', {
+          'defines': [
+            'YUV_DISABLE_ASM',
+          ],
+        }],
         ['build_with_mozilla==1', {
           'include_dirs': [
             '$(DEPTH)/dist/include',
