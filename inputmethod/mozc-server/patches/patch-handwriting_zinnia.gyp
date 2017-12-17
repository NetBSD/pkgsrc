$NetBSD: patch-handwriting_zinnia.gyp,v 1.3 2017/12/17 14:15:43 tsutsui Exp $

* NetBSD support

--- handwriting/zinnia.gyp.orig	2017-11-02 13:32:47.000000000 +0000
+++ handwriting/zinnia.gyp
@@ -88,7 +88,7 @@
                 'ZINNIA_STATIC_LIBRARY',
               ],
             }],
-            ['target_platform=="Linux" or target_platform=="Mac"', {
+            ['target_platform=="Linux" or target_platform=="Mac" or target_platform=="NetBSD"', {
               'defines': [
                 'HAVE_CONFIG_H=1'
               ],
