$NetBSD: patch-common.gypi,v 1.1 2022/03/30 06:51:30 adam Exp $

Add support for NetBSD.

--- common.gypi.orig	2020-01-07 22:07:48.000000000 +0000
+++ common.gypi
@@ -326,11 +326,11 @@
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
         'defines': [ '__STDC_FORMAT_MACROS' ],
