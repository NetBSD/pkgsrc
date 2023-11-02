$NetBSD: patch-common.gypi,v 1.1 2023/11/02 13:16:54 adam Exp $

Add support for NetBSD.

--- common.gypi.orig	2023-03-14 15:46:14.000000000 +0000
+++ common.gypi
@@ -393,11 +393,11 @@
           'BUILDING_UV_SHARED=1',
         ],
       }],
-      [ 'OS in "linux freebsd openbsd solaris aix os400"', {
+      [ 'OS in "linux freebsd netbsd openbsd solaris aix os400"', {
         'cflags': [ '-pthread' ],
         'ldflags': [ '-pthread' ],
       }],
-      [ 'OS in "linux freebsd openbsd solaris android aix os400 cloudabi"', {
+      [ 'OS in "linux freebsd netbsd openbsd solaris android aix os400 cloudabi"', {
         'cflags': [ '-Wall', '-Wextra', '-Wno-unused-parameter', ],
         'cflags_cc': [ '-fno-rtti', '-fno-exceptions', '-std=gnu++17' ],
         'defines': [ '__STDC_FORMAT_MACROS' ],
