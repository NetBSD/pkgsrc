$NetBSD: patch-common.gypi,v 1.2 2015/04/30 15:04:56 ryoon Exp $

Add support for NetBSD.

--- common.gypi.orig	2015-03-31 22:13:01.000000000 +0000
+++ common.gypi
@@ -171,7 +171,7 @@
         'cflags': [ '-pthread', ],
         'ldflags': [ '-pthread' ],
       }],
-      [ 'OS in "linux freebsd openbsd solaris android"', {
+      [ 'OS in "linux freebsd openbsd solaris android netbsd"', {
         'cflags': [ '-Wall', '-Wextra', '-Wno-unused-parameter', ],
         'cflags_cc': [ '-fno-rtti', '-fno-exceptions' ],
         'ldflags': [ '-rdynamic' ],
