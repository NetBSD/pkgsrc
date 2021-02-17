$NetBSD: patch-base_base.gyp,v 1.1 2021/02/17 15:29:51 ryoon Exp $

* NetBSD support

--- base/base.gyp.orig	2017-11-02 13:32:45.000000000 +0000
+++ base/base.gyp
@@ -141,7 +141,7 @@
             },
           },
         }],
-        ['target_platform=="Linux" and server_dir!=""', {
+        ['(target_platform=="Linux" or target_platform=="NetBSD") and server_dir!=""', {
           'defines': [
             'MOZC_SERVER_DIRECTORY="<(server_dir)"',
           ],
