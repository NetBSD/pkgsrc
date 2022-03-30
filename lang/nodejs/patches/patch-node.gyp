$NetBSD: patch-node.gyp,v 1.3 2022/03/30 06:52:33 adam Exp $

Avoid building vendored OpenSSL.

--- node.gyp.orig	2022-03-01 10:28:22.000000000 +0000
+++ node.gyp
@@ -1393,7 +1393,7 @@
       ]
     }], # end aix section
     # TODO(RaisinTen): Enable this to build on other platforms as well.
-    ['(OS=="mac" or (OS=="linux" and target_arch=="x64")) and \
+    ['(OS=="linux" and target_arch=="x64") and \
       node_use_openssl=="true"', {
       'targets': [
         {
