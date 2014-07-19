$NetBSD: patch-gyptest.py,v 1.3 2014/07/19 09:08:36 ryoon Exp $

* Add NetBSD 5 and 6 target

--- gyptest.py.orig	2014-07-14 14:19:50.000000000 +0000
+++ gyptest.py
@@ -219,6 +219,9 @@ def main(argv=None):
       'aix5':     ['make'],
       'freebsd7': ['make'],
       'freebsd8': ['make'],
+      'freebsd9': ['make'],
+      'netbsd5': ['make'],
+      'netbsd6': ['make'],
       'openbsd5': ['make'],
       'cygwin':   ['msvs'],
       'win32':    ['msvs', 'ninja'],
