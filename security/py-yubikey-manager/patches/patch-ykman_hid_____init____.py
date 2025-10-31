$NetBSD: patch-ykman_hid_____init____.py,v 1.1 2025/10/31 14:56:39 ryoon Exp $

* Support OTP HID for NetBSD.

--- ykman/hid/__init__.py.orig	2025-09-03 07:25:44.000000000 +0000
+++ ykman/hid/__init__.py
@@ -52,6 +52,8 @@ elif sys.platform == "darwin":
     from .macos import list_devices
 elif sys.platform == "freebsd":
     from .freebsd import list_devices
+elif sys.platform.startswith("netbsd"):
+    from .netbsd import list_devices
 else:
 
     def list_devices() -> list:
