$NetBSD: patch-deps_cares_cares.gyp,v 1.3 2017/10/25 13:45:18 fhajny Exp $

Add support for NetBSD.
SunOS headers need _XOPEN_SOURCE=600 with c99.

--- deps/cares/cares.gyp.orig	2017-10-24 19:09:57.000000000 +0000
+++ deps/cares/cares.gyp
@@ -20,7 +20,7 @@
       ['OS=="solaris"', {
         'defines': [
           '__EXTENSIONS__',
-          '_XOPEN_SOURCE=500'
+          '_XOPEN_SOURCE=600'
         ]
       }]
     ]
@@ -136,7 +136,7 @@
         }],
         [ 'OS not in "win android"', {
           'cflags': [
-            '--std=gnu89'
+            '--std=gnu99'
           ],
         }],
         [ 'OS=="linux"', {
@@ -151,6 +151,10 @@
           'include_dirs': [ 'config/freebsd' ],
           'sources': [ 'config/freebsd/ares_config.h' ]
         }],
+        [ 'OS=="netbsd"', {
+          'include_dirs': [ 'config/netbsd' ],
+          'sources': [ 'config/netbsd/ares_config.h' ]
+        }],
         [ 'OS=="openbsd"', {
           'include_dirs': [ 'config/openbsd' ],
           'sources': [ 'config/openbsd/ares_config.h' ]
