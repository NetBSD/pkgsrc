$NetBSD: patch-deps_uv_common.gypi,v 1.1 2023/11/02 13:16:54 adam Exp $

Add support for NetBSD.

--- deps/uv/common.gypi.orig	2023-03-14 15:46:16.000000000 +0000
+++ deps/uv/common.gypi
@@ -135,7 +135,7 @@
           }]
         ]
       }],
-      ['OS in "freebsd dragonflybsd linux openbsd solaris android aix os400"', {
+      ['OS in "freebsd dragonflybsd linux netbsd openbsd solaris android aix os400"', {
         'cflags': [ '-Wall' ],
         'cflags_cc': [ '-fno-rtti', '-fno-exceptions' ],
         'target_conditions': [
