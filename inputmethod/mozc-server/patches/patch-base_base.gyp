$NetBSD: patch-base_base.gyp,v 1.3 2014/06/15 13:08:34 ryoon Exp $

--- base/base.gyp.orig	2014-05-21 10:51:31.000000000 +0000
+++ base/base.gyp
@@ -78,7 +78,7 @@
         # shared among *host* binaries and *target* binaries. This means that
         # you should implement *host* binaries by using limited libraries
         # which are also available on NDK.
-        ['OS=="linux" and target_platform!="Android" and '
+        ['OS=="netbsd" or (OS=="linux" and target_platform!="Android") and '
          'not (target_platform=="NaCl" and _toolset=="target")', {
           'defines': [
             'HAVE_LIBRT=1',
@@ -274,23 +274,23 @@
           },
         }],
         ['use_legacy_encryptor==1 and '
-         'OS=="linux" and target_platform!="Android" and '
+         'OS=="netbsd" or (OS=="linux" and target_platform!="Android") and '
          'not (target_platform=="NaCl" and _toolset=="target")', {
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
