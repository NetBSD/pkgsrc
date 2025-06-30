$NetBSD: patch-common.gypi,v 1.2 2025/06/30 16:31:39 adam Exp $

Add support for NetBSD.

--- common.gypi.orig	2025-06-24 20:18:20.000000000 +0000
+++ common.gypi
@@ -503,11 +503,11 @@
           'NOMINMAX',
         ],
       }],
-      [ 'OS in "linux freebsd openbsd solaris aix os400 openharmony"', {
+      [ 'OS in "linux freebsd openbsd solaris aix os400 openharmony netbsd"', {
         'cflags': [ '-pthread' ],
         'ldflags': [ '-pthread' ],
       }],
-      [ 'OS in "linux freebsd openbsd solaris android aix os400 cloudabi openharmony"', {
+      [ 'OS in "linux freebsd openbsd solaris android aix os400 cloudabi openharmony netbsd"', {
         'cflags': [ '-Wall', '-Wextra', '-Wno-unused-parameter', ],
         'cflags_cc': [
           '-fno-rtti',
