$NetBSD: patch-gyptest.py,v 1.4 2014/08/21 14:49:43 he Exp $

* Add NetBSD 5, 6 and 7 target

--- gyptest.py.orig	2014-07-14 14:19:50.000000000 +0000
+++ gyptest.py
@@ -219,6 +219,10 @@ def main(argv=None):
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
