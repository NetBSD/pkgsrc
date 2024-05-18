$NetBSD: patch-common.gypi,v 1.12 2024/05/18 07:05:23 adam Exp $

Add support for NetBSD.

--- common.gypi.orig	2024-05-15 12:34:59.000000000 +0000
+++ common.gypi
@@ -482,11 +482,11 @@
           'NOMINMAX',
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
