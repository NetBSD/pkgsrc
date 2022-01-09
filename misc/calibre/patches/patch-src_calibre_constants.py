$NetBSD: patch-src_calibre_constants.py,v 1.5 2022/01/09 15:43:51 rhialto Exp $

Include netbsd conditional.

--- src/calibre/constants.py.orig	2022-01-08 12:14:13.953868037 +0000
+++ src/calibre/constants.py
@@ -197,7 +197,7 @@ class Plugins(collections.Mapping):
         if isosx:
             plugins.append('usbobserver')
             plugins.append('cocoa')
-        if isfreebsd or ishaiku or islinux or isosx:
+        if isfreebsd or ishaiku or islinux or isosx or isnetbsd:
             plugins.append('libusb')
             plugins.append('libmtp')
         self.plugins = frozenset(plugins)
