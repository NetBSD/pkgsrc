$NetBSD: patch-deps_uv_common.gypi,v 1.1 2019/12/09 20:05:40 adam Exp $

Add support for NetBSD.

--- deps/uv/common.gypi.orig	2018-04-24 14:41:22.000000000 +0000
+++ deps/uv/common.gypi
@@ -134,7 +134,7 @@
           }]
         ]
       }],
-      ['OS in "freebsd dragonflybsd linux openbsd solaris android aix"', {
+      ['OS in "freebsd dragonflybsd linux openbsd netbsd solaris android aix"', {
         'cflags': [ '-Wall' ],
         'cflags_cc': [ '-fno-rtti', '-fno-exceptions' ],
         'target_conditions': [
