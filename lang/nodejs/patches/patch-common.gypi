$NetBSD: patch-common.gypi,v 1.6 2018/02/23 19:42:04 fhajny Exp $

Add support for NetBSD.

--- common.gypi.orig	2018-02-23 02:52:51.000000000 +0000
+++ common.gypi
@@ -291,7 +291,7 @@
         'cflags': [ '-pthread' ],
         'ldflags': [ '-pthread' ],
       }],
-      [ 'OS in "linux freebsd openbsd solaris android aix cloudabi"', {
+      [ 'OS in "linux freebsd openbsd netbsd solaris android aix cloudabi"', {
         'cflags': [ '-Wall', '-Wextra', '-Wno-unused-parameter', ],
         'cflags_cc': [ '-fno-rtti', '-fno-exceptions', '-std=gnu++0x' ],
         'ldflags': [ '-rdynamic' ],
