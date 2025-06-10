$NetBSD: patch-common.gypi,v 1.14 2025/06/10 17:12:03 adam Exp $

Add support for NetBSD.

--- common.gypi.orig	2025-06-09 16:53:41.000000000 +0000
+++ common.gypi
@@ -503,11 +503,11 @@
           'NOMINMAX',
         ],
       }],
-      [ 'OS in "linux freebsd openbsd solaris aix os400 openharmony"', {
+      [ 'OS in "linux freebsd netbsd openbsd solaris aix os400 openharmony"', {
         'cflags': [ '-pthread' ],
         'ldflags': [ '-pthread' ],
       }],
-      [ 'OS in "linux freebsd openbsd solaris android aix os400 cloudabi openharmony"', {
+      [ 'OS in "linux freebsd netbsd openbsd solaris android aix os400 cloudabi openharmony"', {
         'cflags': [ '-Wall', '-Wextra', '-Wno-unused-parameter', ],
         'cflags_cc': [
           '-fno-rtti',
