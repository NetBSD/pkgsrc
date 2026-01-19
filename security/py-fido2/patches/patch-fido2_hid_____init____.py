$NetBSD: patch-fido2_hid_____init____.py,v 1.3 2026/01/19 08:17:33 adam Exp $

Properly detect NetBSD. See docs for sys.platform.

--- fido2/hid/__init__.py.orig	1970-01-01 00:00:00.000000000 +0000
+++ fido2/hid/__init__.py
@@ -50,7 +50,7 @@ elif sys.platform == "darwin":
     from . import macos as backend
 elif sys.platform == "freebsd":
     from . import freebsd as backend
-elif sys.platform == "netbsd":
+elif sys.platform.startswith("netbsd"):
     from . import netbsd as backend
 elif sys.platform == "openbsd":
     from . import openbsd as backend
