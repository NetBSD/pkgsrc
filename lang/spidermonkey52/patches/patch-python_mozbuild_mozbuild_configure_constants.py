$NetBSD: patch-python_mozbuild_mozbuild_configure_constants.py,v 1.1 2018/05/11 19:18:35 jperkin Exp $

Support SunOS.

--- python/mozbuild/mozbuild/configure/constants.py.orig	2018-04-28 01:04:05.000000000 +0000
+++ python/mozbuild/mozbuild/configure/constants.py
@@ -24,6 +24,7 @@ OS = EnumString.subclass(
     'NetBSD',
     'OpenBSD',
     'OSX',
+    'SunOS',
     'WINNT',
 )
 
@@ -35,6 +36,7 @@ Kernel = EnumString.subclass(
     'Linux',
     'NetBSD',
     'OpenBSD',
+    'SunOS',
     'WINNT',
 )
 
@@ -97,6 +99,7 @@ kernel_preprocessor_checks = {
     'Linux': '__linux__',
     'NetBSD': '__NetBSD__',
     'OpenBSD': '__OpenBSD__',
+    'SunOS': '__sun',
     'WINNT': '_WIN32 || __CYGWIN__',
 }
 
