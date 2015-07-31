$NetBSD: patch-gyp_common.gypi,v 1.7 2015/07/31 13:07:05 ryoon Exp $

--- gyp/common.gypi.orig	2015-06-07 07:16:23.000000000 +0000
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
@@ -300,7 +300,7 @@
           ['channel_dev==1', {
             'defines': ['CHANNEL_DEV'],
           }],
-          ['OS=="linux"', {
+          ['OS=="linux" or OS=="netbsd"', {
             'ldflags': [
               '<@(linux_ldflags)',
             ],
@@ -523,7 +523,7 @@
           },
         },
         'conditions': [
-          ['OS=="linux"', {
+          ['OS=="linux" or OS=="netbsd"', {
             'cflags': [
               '<@(debug_extra_cflags)',
             ],
@@ -589,7 +589,7 @@
           },
         },
         'conditions': [
-          ['OS=="linux"', {
+          ['OS=="linux" or OS=="netbsd"', {
             'cflags': [
               '<@(release_extra_cflags)',
             ],
@@ -814,6 +814,22 @@
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
