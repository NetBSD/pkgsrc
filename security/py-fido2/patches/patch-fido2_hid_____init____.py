$NetBSD: patch-fido2_hid_____init____.py,v 1.4 2026/01/19 08:32:04 adam Exp $

Properly detect platforms.
https://github.com/Yubico/python-fido2/pull/276

--- fido2/hid/__init__.py.orig	1970-01-01 00:00:00.000000000 +0000
+++ fido2/hid/__init__.py
@@ -48,11 +48,11 @@ elif sys.platform == "win32":
     from . import windows as backend
 elif sys.platform == "darwin":
     from . import macos as backend
-elif sys.platform == "freebsd":
+elif sys.platform.startswith("freebsd"):
     from . import freebsd as backend
-elif sys.platform == "netbsd":
+elif sys.platform.startswith("netbsd"):
     from . import netbsd as backend
-elif sys.platform == "openbsd":
+elif sys.platformstartswith("openbsd"):
     from . import openbsd as backend
 else:
     raise Exception("Unsupported platform")
