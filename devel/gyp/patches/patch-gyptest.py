$NetBSD: patch-gyptest.py,v 1.2 2013/09/08 16:33:25 ryoon Exp $

* Add NetBSD 5 and 6 target

--- gyptest.py.orig	2013-09-06 23:07:42.000000000 +0000
+++ gyptest.py
@@ -218,6 +218,9 @@ def main(argv=None):
     format_list = {
       'freebsd7': ['make'],
       'freebsd8': ['make'],
+      'freebsd9': ['make'],
+      'netbsd5': ['make'],
+      'netbsd6': ['make'],
       'openbsd5': ['make'],
       'cygwin':   ['msvs'],
       'win32':    ['msvs', 'ninja'],
