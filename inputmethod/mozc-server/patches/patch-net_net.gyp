$NetBSD: patch-net_net.gyp,v 1.1 2013/04/29 09:52:18 ryoon Exp $

--- net/net.gyp.orig	2013-03-29 04:33:42.000000000 +0000
+++ net/net.gyp
@@ -61,7 +61,7 @@
                 },
               },
             }],
-            ['target_platform=="Linux"', {
+            ['target_platform=="Linux" or target_platform=="NetBSD"', {
               # Enable libcurl
               'cflags': [
                 '<!@(<(pkg_config_command) --cflags libcurl)',
