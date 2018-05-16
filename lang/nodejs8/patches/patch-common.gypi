$NetBSD: patch-common.gypi,v 1.2 2018/05/16 18:41:54 fhajny Exp $

Add support for NetBSD.

--- common.gypi.orig	2018-05-15 19:09:33.000000000 +0000
+++ common.gypi
@@ -285,7 +285,7 @@
         'cflags': [ '-pthread' ],
         'ldflags': [ '-pthread' ],
       }],
-      [ 'OS in "linux freebsd openbsd solaris android aix"', {
+      [ 'OS in "linux freebsd openbsd netbsd solaris android aix"', {
         'cflags': [ '-Wall', '-Wextra', '-Wno-unused-parameter', ],
         'cflags_cc': [ '-fno-rtti', '-fno-exceptions', '-std=gnu++0x' ],
         'ldflags': [ '-rdynamic' ],
