$NetBSD: patch-handwriting_zinnia.gyp,v 1.2 2016/05/16 11:51:49 ryoon Exp $

--- handwriting/zinnia.gyp.orig	2016-05-15 08:11:11.000000000 +0000
+++ handwriting/zinnia.gyp
@@ -80,7 +80,7 @@
                 'VERSION="0.06"',
               ],
             }],
-            ['target_platform=="Linux" or target_platform=="Mac"', {
+            ['target_platform=="Linux" or target_platform=="Mac" or target_platform=="NetBSD"', {
               'defines': [
                 'HAVE_CONFIG_H=1'
               ],
