$NetBSD: patch-gyp_common.gypi,v 1.8 2016/05/16 11:51:49 ryoon Exp $

--- gyp/common.gypi.orig	2016-05-15 08:11:11.000000000 +0000
+++ gyp/common.gypi
@@ -158,7 +158,7 @@
         'compiler_host': 'clang',
         'compiler_host_version_int': 304,  # Clang 3.4 or higher
       }],
-      ['target_platform=="Linux"', {
+      ['target_platform=="Linux" or target_platform=="NetBSD"', {
         # enable_gtk_renderer represents if mozc_renderer is supported on Linux
         # or not.
         'compiler_target': 'clang',
@@ -206,7 +206,7 @@
 
     # server_dir represents the directory where mozc_server is
     # installed. This option is only for Linux.
-    'server_dir%': '/usr/lib/mozc',
+    'server_dir%': '@PREFIX@/libexec',
 
     # Represents the directory where the source code of protobuf is
     # extracted. This value is ignored when 'use_libprotobuf' is 1.
@@ -415,7 +415,7 @@
           },
         },
         'conditions': [
-          ['OS=="linux"', {
+          ['OS=="linux" or OS=="netbsd"', {
             'cflags': [
               '<@(debug_extra_cflags)',
             ],
@@ -481,7 +481,7 @@
           },
         },
         'conditions': [
-          ['OS=="linux"', {
+          ['OS=="linux" or OS=="netbsd"', {
             'cflags': [
               '<@(release_extra_cflags)',
             ],
@@ -578,7 +578,7 @@
       ['channel_dev==1', {
         'defines': ['CHANNEL_DEV'],
       }],
-      ['OS=="linux"', {
+      ['OS=="linux" or OS=="netbsd"', {
         'ldflags': [
           '<@(linux_ldflags)',
         ],
@@ -807,6 +807,22 @@
           }],
         ],
       }],
+      ['OS=="netbsd"', {
+        'defines': [
+          'OS_NETBSD',
+          'MOZC_SERVER_DIRECTORY="<@(server_dir)"',
+        ],
+        'cflags': [
+          '<@(gcc_cflags)',
+          '-fPIC',
+          '-fno-exceptions',
+        ],
+        'cflags_cc': [
+          # We use deprecated <hash_map> and <hash_set> instead of upcoming
+          # <unordered_map> and <unordered_set>.
+          '-Wno-deprecated',
+        ],
+      }],
       ['OS=="mac"', {
         'defines': [
           'OS_MACOSX',
