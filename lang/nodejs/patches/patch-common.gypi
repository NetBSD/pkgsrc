$NetBSD: patch-common.gypi,v 1.13 2024/08/23 10:10:35 adam Exp $

Add support for NetBSD.

--- common.gypi.orig	2024-08-21 21:12:02.000000000 +0000
+++ common.gypi
@@ -483,11 +483,11 @@
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
         'cflags_cc': [
           '-fno-rtti',
