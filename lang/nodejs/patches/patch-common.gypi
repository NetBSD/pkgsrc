$NetBSD: patch-common.gypi,v 1.9 2022/03/30 06:52:33 adam Exp $

Add support for NetBSD.

--- common.gypi.orig	2021-08-03 05:54:22.000000000 +0000
+++ common.gypi
@@ -376,11 +376,11 @@
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
         'cflags_cc': [ '-fno-rtti', '-fno-exceptions', '-std=gnu++14' ],
         'defines': [ '__STDC_FORMAT_MACROS' ],
