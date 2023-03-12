$NetBSD: patch-fido2_hid_____init____.py,v 1.1 2023/03/12 14:01:04 wiz Exp $

Add NetBSD support.
https://github.com/Yubico/python-fido2/pull/174

--- fido2/hid/__init__.py.orig	2022-10-17 13:36:35.000000000 +0000
+++ fido2/hid/__init__.py
@@ -49,6 +49,8 @@ elif sys.platform.startswith("darwin"):
     from . import macos as backend
 elif sys.platform.startswith("freebsd"):
     from . import freebsd as backend
+elif sys.platform.startswith('netbsd'):
+    from . import netbsd as backend
 elif sys.platform.startswith("openbsd"):
     from . import openbsd as backend
 else:
