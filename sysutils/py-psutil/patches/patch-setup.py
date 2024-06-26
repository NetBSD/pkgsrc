$NetBSD: patch-setup.py,v 1.9 2024/06/26 16:51:33 wiz Exp $

Enable limited API on all platforms.

--- setup.py.orig	2024-06-02 23:32:26.000000000 +0000
+++ setup.py
@@ -120,7 +120,7 @@ macros.append(('PSUTIL_VERSION', int(VER
 
 # Py_LIMITED_API lets us create a single wheel which works with multiple
 # python versions, including unreleased ones.
-if bdist_wheel and CP36_PLUS and (MACOS or LINUX) and not Py_GIL_DISABLED:
+if bdist_wheel and CP36_PLUS:
     py_limited_api = {"py_limited_api": True}
     macros.append(('Py_LIMITED_API', '0x03060000'))
 elif bdist_wheel and CP37_PLUS and WINDOWS and not Py_GIL_DISABLED:
