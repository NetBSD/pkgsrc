$NetBSD: patch-net_net.gyp,v 1.2 2017/12/17 14:15:43 tsutsui Exp $

* NetBSD support

--- net/net.gyp.orig	2017-11-02 13:32:47.000000000 +0000
+++ net/net.gyp
@@ -64,7 +64,7 @@
                 },
               },
             }],
-            ['target_platform=="Linux"', {
+            ['target_platform=="Linux" or target_platform=="NetBSD"', {
               # Enable libcurl
               'cflags': [
                 '<!@(pkg-config --cflags libcurl)',
