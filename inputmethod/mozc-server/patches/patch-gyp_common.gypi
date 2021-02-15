$NetBSD: patch-gyp_common.gypi,v 1.10 2021/02/15 14:50:23 ryoon Exp $

* NetBSD support

--- gyp/common.gypi.orig	2021-02-15 05:04:33.000000000 +0000
+++ gyp/common.gypi
@@ -93,6 +93,13 @@
       '-fstack-protector',
       '--param=ssp-buffer-size=4',
     ],
+    # netbsd_cflags will be used for NetBSD.
+    'netbsd_cflags': [
+      '<@(gcc_cflags)',
+      '-fPIC',
+      '-D_NETBSD_SOURCE',
+      '-fno-exceptions',
+    ],
     # mac_cflags will be used in Mac.
     # Xcode 4.5 which we are currently using does not support ssp-buffer-size.
     # TODO(horo): When we can use Xcode 4.6 which supports ssp-buffer-size,
@@ -128,6 +135,12 @@
         'compiler_host': 'clang',
         'compiler_host_version_int': 304,  # Clang 3.4 or higher
       }],
+      ['target_platform=="NetBSD"', {
+        'compiler_target': 'gcc',
+        'compiler_target_version_int': 409,  # GCC 4.9 or higher
+        'compiler_host': 'gcc',
+        'compiler_host_version_int': 409,  # GCC 4.9 or higher
+      }],
     ],
   },
   'target_defaults': {
@@ -318,6 +331,24 @@
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
           '__APPLE__',
@@ -410,7 +441,7 @@
     ],
   },
   'conditions': [
-    ['target_platform=="Linux"', {
+    ['target_platform=="Linux" or target_platform=="NetBSD"', {
       'make_global_settings': [
         ['AR', '<!(which ar)'],
         ['CC', '<!(which clang)'],
