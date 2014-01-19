$NetBSD: patch-gyp_common.gypi,v 1.4 2014/01/19 01:18:50 ryoon Exp $

--- gyp/common.gypi.orig	2014-01-06 07:10:31.000000000 +0000
+++ gyp/common.gypi
@@ -92,6 +92,7 @@
       '-include base/namespace.h',
       '-pipe',
       '-pthread',
+      '-std=c++0x',
     ],
     # linux_cflags will be used in Linux except for NaCl.
     'linux_cflags': [
@@ -137,7 +138,7 @@
         'clang_bin_dir': '/Applications/Xcode.app/Contents/Developer/Toolchains'
                          '/XcodeDefault.xctoolchain/usr/bin/',
       }],
-      ['target_platform=="Linux"', {
+      ['target_platform=="Linux" or target_platform=="NetBSD"', {
         # enable_gtk_renderer represents if mozc_renderer is supported on Linux
         # or not.
         'enable_gtk_renderer%': 1,
@@ -195,7 +196,7 @@
 
     # server_dir represents the directory where mozc_server is
     # installed. This option is only for Linux.
-    'server_dir%': '/usr/lib/mozc',
+    'server_dir%': '@PREFIX@/libexec',
 
     # Represents the directory where the source code of protobuf is
     # extracted. This value is ignored when 'use_libprotobuf' is 1.
@@ -286,7 +287,7 @@
           ['channel_dev==1', {
             'defines': ['CHANNEL_DEV'],
           }],
-          ['OS=="linux"', {
+          ['OS=="linux" or OS=="netbsd"', {
             'ldflags': [
               '<@(linux_ldflags)',
             ],
@@ -451,7 +452,7 @@
           },
         },
         'conditions': [
-          ['OS=="linux"', {
+          ['OS=="linux" or OS=="netbsd"', {
             'cflags': [
               '<@(debug_extra_cflags)',
             ],
@@ -489,7 +490,7 @@
           },
         },
         'conditions': [
-          ['OS=="linux"', {
+          ['OS=="linux" or OS=="netbsd"', {
             'cflags': [
               '<@(release_extra_cflags)',
             ],
@@ -753,6 +754,22 @@
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
