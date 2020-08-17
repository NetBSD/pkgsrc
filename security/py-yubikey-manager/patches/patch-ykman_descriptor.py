$NetBSD: patch-ykman_descriptor.py,v 1.1 2020/08/17 07:02:25 riastradh Exp $

Enumerate uhidevs in case they are not available as ugen.

--- ykman/descriptor.py.orig	2020-08-17 06:36:13.378751569 +0000
+++ ykman/descriptor.py
@@ -145,6 +145,13 @@ def _gen_descriptors():
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
