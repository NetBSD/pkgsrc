$NetBSD: patch-common.gypi,v 1.2 2020/02/24 16:02:40 adam Exp $

Add support for NetBSD.

--- common.gypi.orig	2020-02-18 05:08:31.000000000 +0000
+++ common.gypi
@@ -354,11 +354,11 @@
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
