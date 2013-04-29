$NetBSD: patch-gyp_common.gypi,v 1.2 2013/04/29 09:21:24 ryoon Exp $

--- gyp/common.gypi.orig	2013-03-29 04:33:42.000000000 +0000
+++ gyp/common.gypi
@@ -132,7 +132,7 @@
     'conditions': [
       # enable_gtk_renderer represents if mozc_renderer is supported on Linux
       # or not.
-      ['target_platform=="Linux" and language=="japanese"', {
+      ['(target_platform=="Linux" or target_platform=="NetBSD") and language=="japanese"', {
         'enable_gtk_renderer%': 1,
       }, { # else
         'enable_gtk_renderer%': 0,
@@ -283,12 +283,12 @@
           # additional suffix except for Japanese so that multiple
           # converter processes can coexist. Note that Mozc on ChromeOS does
           # not use IPC so this kind of special treatment is not required.
-          ['language!="japanese" and target_platform=="Linux"', {
+          ['language!="japanese" and (target_platform=="Linux" or target_platform=="NetBSD")', {
             'defines': [
               'MOZC_LANGUAGE_SUFFIX_FOR_LINUX="_<(language)"',
             ],
           }],
-          ['OS=="linux"', {
+          ['OS=="linux" or OS=="netbsd"', {
             'ldflags': [
               '<@(linux_ldflags)',
             ],
@@ -447,7 +447,7 @@
           },
         },
         'conditions': [
-          ['OS=="linux"', {
+          ['OS=="linux" or OS=="netbsd"', {
             'cflags': [
               '<@(debug_extra_cflags)',
             ],
@@ -485,7 +485,7 @@
           },
         },
         'conditions': [
-          ['OS=="linux"', {
+          ['OS=="linux" or OS=="netbsd"', {
             'cflags': [
               '<@(release_extra_cflags)',
             ],
@@ -785,6 +785,22 @@
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
