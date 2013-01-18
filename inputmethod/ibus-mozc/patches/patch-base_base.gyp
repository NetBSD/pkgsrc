$NetBSD: patch-base_base.gyp,v 1.1 2013/01/18 11:36:40 ryoon Exp $

--- base/base.gyp.orig	2012-08-31 05:37:06.000000000 +0000
+++ base/base.gyp
@@ -98,7 +98,7 @@
         # shared among *host* binaries and *target* binaries. This means that
         # you should implement *host* binaries by using limited libraries
         # which are also available on NDK.
-        ['OS=="linux" and target_platform!="Android" and '
+        ['OS=="netbsd" or (OS=="linux" and target_platform!="Android") and '
          'not (target_platform=="NaCl" and _toolset=="target")', {
           'defines': [
             'HAVE_LIBRT=1',
@@ -260,22 +260,22 @@
             ],
           }
         }],
-        ['OS=="linux" and target_platform!="Android"', {
+        ['OS=="netbsd" or (OS=="linux" and target_platform!="Android")', {
           'cflags': [
-            '<!@(<(pkg_config_command) --cflags-only-other openssl)',
+            '@OPENSSL_CFLAGS@',
           ],
           'defines': [
             'HAVE_OPENSSL=1',
           ],
           'include_dirs': [
-            '<!@(<(pkg_config_command) --cflags-only-I openssl)',
+            '@OPENSSL_INC@',
           ],
           'link_settings': {
             'ldflags': [
-              '<!@(<(pkg_config_command) --libs-only-L openssl)',
+              '@OPENSSL_LDFLAGS@',
             ],
             'libraries': [
-              '<!@(<(pkg_config_command) --libs-only-l openssl)',
+              '@OPENSSL_LIBS@',
             ],
           },
         }],
