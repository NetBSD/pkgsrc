$NetBSD: patch-setup.py,v 1.7 2023/04/18 07:37:42 adam Exp $

Enable limited API on all platforms.

--- setup.py.orig	2023-04-17 15:01:41.000000000 +0000
+++ setup.py
@@ -111,7 +111,7 @@ macros.append(('PSUTIL_VERSION', int(VER
 
 # Py_LIMITED_API lets us create a single wheel which works with multiple
 # python versions, including unreleased ones.
-if bdist_wheel and CP36_PLUS and (MACOS or LINUX or WINDOWS):
+if bdist_wheel and CP36_PLUS:
     py_limited_api = {"py_limited_api": True}
     macros.append(('Py_LIMITED_API', '0x03060000'))
 else:
