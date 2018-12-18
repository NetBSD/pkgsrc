$NetBSD: patch-setup.py,v 1.2 2018/12/18 12:02:34 adam Exp $

Prefer external compiler optimizations.

--- setup.py.orig	2018-12-18 02:40:14.000000000 +0000
+++ setup.py
@@ -100,7 +100,6 @@ elif compiler in ('unix', 'mingw32'):
             extra_compile_args.append(pkgconfig_cflags('liblz4'))
     else:
         extra_compile_args = [
-            '-O3',
             '-Wall',
             '-Wundef'
         ]
