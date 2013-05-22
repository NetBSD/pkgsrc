$NetBSD: patch-common.gypi,v 1.1 2013/05/22 15:17:07 mspo Exp $

Add support for NetBSD.

--- common.gypi.orig	2013-03-11 00:36:28.000000000 +0000
+++ common.gypi
@@ -159,7 +159,7 @@
           'BUILDING_UV_SHARED=1',
         ],
       }],
-      [ 'OS=="linux" or OS=="freebsd" or OS=="openbsd" or OS=="solaris"', {
+      [ 'OS=="linux" or OS=="freebsd" or OS=="openbsd" or OS=="solaris" or OS=="netbsd"', {
         'cflags': [ '-Wall', '-Wextra', '-Wno-unused-parameter', '-pthread', ],
         'cflags_cc': [ '-fno-rtti', '-fno-exceptions' ],
         'ldflags': [ '-pthread', '-rdynamic' ],
