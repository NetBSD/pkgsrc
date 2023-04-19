$NetBSD: patch-deps_uv_common.gypi,v 1.2 2023/04/19 17:40:30 adam Exp $

Add support for NetBSD.

--- deps/uv/common.gypi.orig	2023-04-12 04:09:14.000000000 +0000
+++ deps/uv/common.gypi
@@ -135,7 +135,7 @@
           }]
         ]
       }],
-      ['OS in "freebsd dragonflybsd linux openbsd solaris android aix os400"', {
+      ['OS in "freebsd netbsd dragonflybsd linux openbsd solaris android aix os400"', {
         'cflags': [ '-Wall' ],
         'cflags_cc': [ '-fno-rtti', '-fno-exceptions' ],
         'target_conditions': [
