$NetBSD: patch-setup.py,v 1.3 2020/11/19 10:37:24 adam Exp $

Prefer external compiler optimizations.

--- setup.py.orig	2020-11-19 10:31:44.000000000 +0000
+++ setup.py
@@ -102,7 +102,6 @@ elif compiler in ('unix', 'mingw32'):
         extension_kwargs = pkgconfig_parse('liblz4')
     else:
         extension_kwargs['extra_compile_args'] = [
-            '-O3',
             '-Wall',
             '-Wundef'
         ]
