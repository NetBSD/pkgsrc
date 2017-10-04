$NetBSD: patch-deps_uv_uv.gyp,v 1.1 2017/10/04 16:20:58 fhajny Exp $

SunOS headers need _XOPEN_SOURCE=600 with c99.

--- deps/uv/uv.gyp.orig	2017-10-03 17:11:16.000000000 +0000
+++ deps/uv/uv.gyp
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
