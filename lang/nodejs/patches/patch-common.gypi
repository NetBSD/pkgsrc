$NetBSD: patch-common.gypi,v 1.5 2017/11/08 17:02:42 fhajny Exp $

Add support for NetBSD.

--- common.gypi.orig	2017-11-07 15:07:54.000000000 +0000
+++ common.gypi
@@ -291,7 +291,7 @@
         'cflags': [ '-pthread', ],
         'ldflags': [ '-pthread' ],
       }],
-      [ 'OS in "linux freebsd openbsd solaris android aix cloudabi"', {
+      [ 'OS in "linux freebsd openbsd netbsd solaris android aix cloudabi"', {
         'cflags': [ '-Wall', '-Wextra', '-Wno-unused-parameter', ],
         'cflags_cc': [ '-fno-rtti', '-fno-exceptions', '-std=gnu++0x' ],
         'ldflags': [ '-rdynamic' ],
