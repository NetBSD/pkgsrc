$NetBSD: patch-pyu2f_hid_____init____.py,v 1.1 2020/08/17 20:57:44 riastradh Exp $

Add NetBSD support.

--- pyu2f/hid/__init__.py.orig	2020-08-17 20:48:34.101158593 +0000
+++ pyu2f/hid/__init__.py
@@ -41,6 +41,9 @@ def InternalPlatformSwitch(funcname, *ar
   elif sys.platform.startswith('darwin'):
     from pyu2f.hid import macos
     clz = macos.MacOsHidDevice
+  elif sys.platform.startswith('netbsd'):
+    from pyu2f.hid import netbsd
+    clz = netbsd.NetBSDHidDevice
 
   if not clz:
     raise Exception('Unsupported platform: ' + sys.platform)
