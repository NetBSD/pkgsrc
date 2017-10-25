$NetBSD: patch-deps_uv_uv.gyp,v 1.2 2017/10/25 13:45:18 fhajny Exp $

SunOS headers need _XOPEN_SOURCE=600 with c99.

--- deps/uv/uv.gyp.orig	2017-10-24 19:10:03.000000000 +0000
+++ deps/uv/uv.gyp
@@ -37,7 +37,7 @@
     'xcode_settings': {
       'GCC_SYMBOLS_PRIVATE_EXTERN': 'YES',  # -fvisibility=hidden
       'WARNING_CFLAGS': [ '-Wall', '-Wextra', '-Wno-unused-parameter' ],
-      'OTHER_CFLAGS': [ '-g', '--std=gnu89', '-pedantic' ],
+      'OTHER_CFLAGS': [ '-g', '--std=gnu99', '-pedantic' ],
     }
   },
 
@@ -205,7 +205,7 @@
           'cflags': [
             '-fvisibility=hidden',
             '-g',
-            '--std=gnu89',
+            '--std=gnu99',
             '-pedantic',
             '-Wall',
             '-Wextra',
@@ -259,7 +259,7 @@
           'sources': [ 'src/unix/sunos.c' ],
           'defines': [
             '__EXTENSIONS__',
-            '_XOPEN_SOURCE=500',
+            '_XOPEN_SOURCE=600',
           ],
           'link_settings': {
             'libraries': [
@@ -488,7 +488,7 @@
         [ 'OS=="solaris"', { # make test-fs.c compile, needs _POSIX_C_SOURCE
           'defines': [
             '__EXTENSIONS__',
-            '_XOPEN_SOURCE=500',
+            '_XOPEN_SOURCE=600',
           ],
         }],
         [ 'OS=="aix"', {     # make test-fs.c compile, needs _POSIX_C_SOURCE
