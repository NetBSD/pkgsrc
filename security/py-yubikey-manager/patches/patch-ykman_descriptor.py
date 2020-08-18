$NetBSD: patch-ykman_descriptor.py,v 1.2 2020/08/18 13:37:50 riastradh Exp $

Enumerate uhidevs in case they are not available as ugen.

--- ykman/descriptor.py.orig	2020-01-29 07:32:03.000000000 +0000
+++ ykman/descriptor.py
@@ -75,6 +75,8 @@ class Descriptor(object):
 
     @property
     def name(self):
+        if self.version is None:
+            return self.key_type.value
         if self.key_type == YUBIKEY.SKY and self.version < (5, 0, 0):
             return 'FIDO U2F Security Key'
         elif self.key_type == YUBIKEY.YK4 and self.version >= (5, 0, 0):
@@ -132,7 +134,8 @@ class Descriptor(object):
     @classmethod
     def from_driver(cls, driver):
         fp = (driver.key_type, driver.mode)
-        return cls(driver.key_type, driver.mode, None, fp)
+        version = driver.read_version()
+        return cls(driver.key_type, driver.mode, version, fp)
 
 
 def _gen_descriptors():
@@ -145,6 +148,13 @@ def _gen_descriptors():
             desc = Descriptor.from_usb(dev, backend)
             if desc:
                 yield desc
+    # No generic USB devices found, but there may be some USB HID
+    # devices available only as such and not as generic USB devices.
+    if not found:
+        for d in _list_drivers(TRANSPORT.OTP | TRANSPORT.FIDO):
+            desc = Descriptor.from_driver(d)
+            if desc:
+                yield desc
 
 
 def get_descriptors():
