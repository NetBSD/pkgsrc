$NetBSD: patch-common.gypi,v 1.14.12.1 2026/10/25 09:16:51 bsiegert Exp $

Add support for NetBSD.

--- common.gypi.orig	2026-10-07 07:39:43.000000000 +0000
+++ common.gypi
@@ -588,11 +588,11 @@
           'NOMINMAX',
         ],
       }],
-      [ 'OS in "linux freebsd openbsd solaris aix os400 openharmony zos"', {
+      [ 'OS in "linux freebsd openbsd solaris aix os400 openharmony zos netbsd"', {
         'cflags': [ '-pthread' ],
         'ldflags': [ '-pthread' ],
       }],
-      [ 'OS in "linux freebsd openbsd solaris android aix os400 cloudabi openharmony zos"', {
+      [ 'OS in "linux freebsd openbsd solaris android aix os400 cloudabi openharmony zos netbsd"', {
         'cflags': [ '-Wall', '-Wextra', '-Wno-unused-parameter', ],
         'cflags_cc': [
           '-fno-rtti',
