$NetBSD: patch-gyptest.py,v 1.5 2022/01/27 18:42:15 wiz Exp $

* Add NetBSD 5, 6 and 7 target

--- gyptest.py.orig	2022-01-27 18:36:11.000000000 +0000
+++ gyptest.py
@@ -98,6 +98,10 @@ def main(argv=None):
       'aix5':     ['make'],
       'freebsd7': ['make'],
       'freebsd8': ['make'],
+      'freebsd9': ['make'],
+      'netbsd5':  ['make'],
+      'netbsd6':  ['make'],
+      'netbsd7':  ['make'],
       'openbsd5': ['make'],
       'cygwin':   ['msvs'],
       'win32':    ['msvs', 'ninja'],
