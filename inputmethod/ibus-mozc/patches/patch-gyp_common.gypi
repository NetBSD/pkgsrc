$NetBSD: patch-gyp_common.gypi,v 1.1 2013/01/18 11:36:40 ryoon Exp $

--- gyp/common.gypi.orig	2012-08-31 05:36:43.000000000 +0000
+++ gyp/common.gypi
@@ -283,12 +283,12 @@
           # additional suffix except for Japanese so that multiple
           # converter processes can coexist. Note that Mozc on ChromeOS does
           # not use IPC so this kind of special treatment is not required.
-          ['language!="japanese" and target_platform=="Linux"', {
+          ['language!="japanese" and target_platform=="Linux" or target_platform=="NetBSD"', {
             'defines': [
               'MOZC_LANGUAGE_SUFFIX_FOR_LINUX="_<(language)"',
             ],
           }],
-          ['OS=="linux"', {
+          ['OS=="linux" or OS=="netbsd"', {
             'ldflags': [
               '<@(linux_ldflags)',
             ],
@@ -438,7 +438,7 @@
           },
         },
         'conditions': [
-          ['OS=="linux"', {
+          ['OS=="linux" or OS=="netbsd"', {
             'cflags': [
               '<@(debug_extra_cflags)',
             ],
@@ -476,7 +476,7 @@
           },
         },
         'conditions': [
-          ['OS=="linux"', {
+          ['OS=="linux" or OS=="netbsd"', {
             'cflags': [
               '<@(release_extra_cflags)',
             ],
@@ -789,6 +789,16 @@
           }],
         ],
       }],
+      ['OS=="netbsd"', {
+        'defines': [
+          'OS_NETBSD',
+        ],
+        'cflags': [
+          '<@(gcc_cflags)',
+          '-fPIC',
+          '-fno-exceptions',
+        ],
+      }],
       ['OS=="mac"', {
         'defines': [
           'OS_MACOSX',
