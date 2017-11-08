$NetBSD: patch-deps_uv_uv.gyp,v 1.3 2017/11/08 18:31:15 fhajny Exp $

SunOS headers need _XOPEN_SOURCE=600 with c99.

--- deps/uv/uv.gyp.orig	2017-11-06 22:14:03.000000000 +0000
+++ deps/uv/uv.gyp
@@ -37,7 +37,7 @@
     'xcode_settings': {
       'GCC_SYMBOLS_PRIVATE_EXTERN': 'YES',  # -fvisibility=hidden
       'WARNING_CFLAGS': [ '-Wall', '-Wextra', '-Wno-unused-parameter', '-Wstrict-prototypes' ],
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
@@ -262,7 +262,7 @@
           ],
           'defines': [
             '__EXTENSIONS__',
-            '_XOPEN_SOURCE=500',
+            '_XOPEN_SOURCE=600',
           ],
           'link_settings': {
             'libraries': [
@@ -501,7 +501,7 @@
         [ 'OS=="solaris"', { # make test-fs.c compile, needs _POSIX_C_SOURCE
           'defines': [
             '__EXTENSIONS__',
-            '_XOPEN_SOURCE=500',
+            '_XOPEN_SOURCE=600',
           ],
         }],
         [ 'OS=="aix"', {     # make test-fs.c compile, needs _POSIX_C_SOURCE
