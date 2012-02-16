$NetBSD: patch-src_calibre_devices_scanner.py,v 1.1 2012/02/16 21:29:36 gls Exp $

--- src/calibre/devices/scanner.py.orig	2012-02-10 04:59:10.000000000 +0000
+++ src/calibre/devices/scanner.py
@@ -10,6 +10,8 @@ from threading import RLock
 
 from calibre.constants import iswindows, isosx, plugins, islinux, isfreebsd
 
+isnetbsd = 'netbsd' in sys.platform.lower()
+
 osx_scanner = win_scanner = linux_scanner = None
 
 if iswindows:
@@ -220,13 +222,18 @@ freebsd_scanner = None
 if isfreebsd:
     freebsd_scanner = FreeBSDScanner()
 
+netbsd_scanner = None
+
+''' NetBSD support currently not written yet '''
+if isnetbsd:
+    netbsd_scanner = None
 
 class DeviceScanner(object):
 
     def __init__(self, *args):
         if isosx and osx_scanner is None:
             raise RuntimeError('The Python extension usbobserver must be available on OS X.')
-        self.scanner = win_scanner if iswindows else osx_scanner if isosx else freebsd_scanner if isfreebsd else linux_scanner
+        self.scanner = win_scanner if iswindows else osx_scanner if isosx else freebsd_scanner if isfreebsd else netbsd_scanner if isnetbsd else linux_scanner
         self.devices = []
 
     def scan(self):
