$NetBSD: patch-common.gypi,v 1.1 2017/11/01 12:07:31 fhajny Exp $

Add support for NetBSD.

--- common.gypi.orig	2015-09-08 15:30:34.000000000 +0000
+++ common.gypi
@@ -221,7 +221,7 @@
         'cflags': [ '-pthread', ],
         'ldflags': [ '-pthread' ],
       }],
-      [ 'OS in "linux freebsd openbsd solaris android aix"', {
+      [ 'OS in "linux freebsd openbsd solaris android aix netbsd"', {
         'cflags': [ '-Wall', '-Wextra', '-Wno-unused-parameter', ],
         'cflags_cc': [ '-fno-rtti', '-fno-exceptions', '-std=gnu++0x' ],
         'ldflags': [ '-rdynamic' ],
