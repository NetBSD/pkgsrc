$NetBSD: patch-setup.py,v 1.1 2017/12/31 18:48:57 adam Exp $

Prefer external compiler optimizations.

--- setup.py.orig	2017-12-31 18:34:27.000000000 +0000
+++ setup.py
@@ -91,7 +91,6 @@ elif compiler in ('unix', 'mingw32'):
             extra_compile_args.append(pkgconfig.cflags('liblz4'))
     else:
         extra_compile_args = [
-            '-O3',
             '-Wall',
             '-Wundef'
         ]
