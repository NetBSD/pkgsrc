$NetBSD: patch-renderer_renderer.gyp,v 1.1 2021/02/15 14:50:23 ryoon Exp $

* Support NetBSD.

--- renderer/renderer.gyp.orig	2021-02-15 05:04:33.000000000 +0000
+++ renderer/renderer.gyp
@@ -193,7 +193,7 @@
             'win32_renderer_core_test',
           ],
         }],
-        ['target_platform=="Linux" and enable_gtk_renderer==1', {
+        ['(target_platform=="Linux" or target_platform=="NetBSD") and enable_gtk_renderer==1', {
           'dependencies': [
             'gtk_renderer_test',
           ],
@@ -518,7 +518,7 @@
         },
       ],
     }],
-    ['target_platform=="Linux" and enable_gtk_renderer==1', {
+    ['(target_platform=="Linux" or target_platform=="NetBSD") and enable_gtk_renderer==1', {
       'targets': [
         {
           # Meta target to set up build environment for gtk+-2.0.
