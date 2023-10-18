$NetBSD: patch-setup.py,v 1.8 2023/10/18 08:53:08 adam Exp $

Enable limited API on all platforms.

--- setup.py.orig	2023-10-04 12:46:27.000000000 +0000
+++ setup.py
@@ -115,7 +115,7 @@ macros.append(('PSUTIL_VERSION', int(VER
 
 # Py_LIMITED_API lets us create a single wheel which works with multiple
 # python versions, including unreleased ones.
-if bdist_wheel and CP36_PLUS and (MACOS or LINUX):
+if bdist_wheel and CP36_PLUS:
     py_limited_api = {"py_limited_api": True}
     macros.append(('Py_LIMITED_API', '0x03060000'))
 elif bdist_wheel and CP37_PLUS and WINDOWS:
