$NetBSD: patch-deps_uv_common.gypi,v 1.2 2015/04/30 15:04:56 ryoon Exp $

Add support for NetBSD.

--- deps/uv/common.gypi.orig	2015-03-31 22:13:01.000000000 +0000
+++ deps/uv/common.gypi
@@ -128,7 +128,7 @@
           }]
         ]
       }],
-      ['OS in "freebsd linux openbsd solaris android"', {
+      ['OS in "freebsd linux openbsd solaris android netbsd"', {
         'cflags': [ '-Wall' ],
         'cflags_cc': [ '-fno-rtti', '-fno-exceptions' ],
         'target_conditions': [
