$NetBSD: patch-gyp_common.gypi,v 1.9 2017/12/17 14:15:43 tsutsui Exp $

* NetBSD support

--- gyp/common.gypi.orig	2017-11-02 13:32:47.000000000 +0000
+++ gyp/common.gypi
@@ -88,6 +88,12 @@
       '-fstack-protector',
       '--param=ssp-buffer-size=4',
     ],
+    # netbsd_cflags will be used for NetBSD.
+    'netbsd_cflags': [
+      '<@(gcc_cflags)',
+      '-fPIC',
+      '-fno-exceptions',
+    ],
     # nacl_cflags will be used for NaCl.
     # -fno-omit-frame-pointer flag does not work correctly.
     #   http://code.google.com/p/chromium/issues/detail?id=122623
@@ -133,6 +139,12 @@
         'compiler_host': 'clang',
         'compiler_host_version_int': 304,  # Clang 3.4 or higher
       }],
+      ['target_platform=="NetBSD"', {
+        'compiler_target': 'gcc',
+        'compiler_target_version_int': 409,  # GCC 4.9 or higher
+        'compiler_host': 'clang',
+        'compiler_host_version_int': 304,  # Clang 3.4 or higher
+      }],
     ],
   },
   'target_defaults': {
@@ -371,6 +383,24 @@
           }],
         ],
       }],
+      ['OS=="netbsd"', {
+        'defines': [
+          'OS_NETBSD',
+        ],
+        'cflags': [
+          '<@(netbsd_cflags)',
+          '-fPIC',
+          '-fno-exceptions',
+        ],
+        'cflags_cc': [
+          # We use deprecated <hash_map> and <hash_set> instead of upcoming
+          # <unordered_map> and <unordered_set>.
+          '-Wno-deprecated',
+        ],
+        'ldflags': [
+          '-pthread',
+        ],
+      }],
       ['OS=="mac"', {
         'defines': [
           'OS_MACOSX',
@@ -442,7 +472,7 @@
         ['READELF.host', '<!(which readelf)'],
       ],
     }],
-    ['target_platform=="Linux"', {
+    ['target_platform=="Linux" or target_platform=="NetBSD"', {
       'make_global_settings': [
         ['AR', '<!(which ar)'],
         ['CC', '<!(which clang)'],
