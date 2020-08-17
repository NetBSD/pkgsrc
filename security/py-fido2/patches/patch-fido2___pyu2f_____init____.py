$NetBSD: patch-fido2___pyu2f_____init____.py,v 1.1 2020/08/17 07:01:34 riastradh Exp $

Add NetBSD support.

--- fido2/_pyu2f/__init__.py.orig	2020-08-17 04:00:49.612333166 +0000
+++ fido2/_pyu2f/__init__.py
@@ -50,6 +50,9 @@ def InternalPlatformSwitch(funcname, *ar
   elif sys.platform.startswith('freebsd'):
     from . import freebsd
     clz = freebsd.FreeBSDHidDevice
+  elif sys.platform.startswith('netbsd'):
+    from . import netbsd
+    clz = netbsd.NetBSDHidDevice
 
   if not clz:
     raise Exception('Unsupported platform: ' + sys.platform)
