$NetBSD: patch-common.gypi,v 1.1 2019/12/09 20:05:40 adam Exp $

Add support for NetBSD.

--- common.gypi.orig	2018-04-24 14:41:15.000000000 +0000
+++ common.gypi
@@ -315,11 +315,11 @@
           'BUILDING_UV_SHARED=1',
         ],
       }],
-      [ 'OS in "linux freebsd openbsd solaris aix"', {
+      [ 'OS in "linux freebsd openbsd netbsd solaris aix"', {
         'cflags': [ '-pthread' ],
         'ldflags': [ '-pthread' ],
       }],
-      [ 'OS in "linux freebsd openbsd solaris android aix cloudabi"', {
+      [ 'OS in "linux freebsd openbsd netbsd netbsd solaris android aix cloudabi"', {
         'cflags': [ '-Wall', '-Wextra', '-Wno-unused-parameter', ],
         'cflags_cc': [ '-fno-rtti', '-fno-exceptions', '-std=gnu++1y' ],
         'ldflags': [ '-rdynamic' ],
