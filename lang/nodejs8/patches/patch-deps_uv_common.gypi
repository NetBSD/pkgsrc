$NetBSD: patch-deps_uv_common.gypi,v 1.2 2019/11/24 15:52:13 adam Exp $

Add support for NetBSD.

--- deps/uv/common.gypi.orig	2019-10-09 13:05:58.000000000 +0000
+++ deps/uv/common.gypi
@@ -134,7 +134,7 @@
           }]
         ]
       }],
-      ['OS in "freebsd dragonflybsd linux openbsd solaris android aix"', {
+      ['OS in "freebsd dragonflybsd linux openbsd solaris android aix netbsd"', {
         'cflags': [ '-Wall' ],
         'cflags_cc': [ '-fno-rtti', '-fno-exceptions' ],
         'target_conditions': [
