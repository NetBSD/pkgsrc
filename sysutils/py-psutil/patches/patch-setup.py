$NetBSD: patch-setup.py,v 1.6 2022/11/08 08:50:20 adam Exp $

Enable limited API on all platforms.

--- setup.py.orig	2022-11-08 08:46:24.000000000 +0000
+++ setup.py
@@ -109,7 +109,7 @@ def get_version():
 VERSION = get_version()
 macros.append(('PSUTIL_VERSION', int(VERSION.replace('.', ''))))
 
-if bdist_wheel and CP36_PLUS and (MACOS or LINUX or WINDOWS):
+if bdist_wheel and CP36_PLUS:
     py_limited_api = {"py_limited_api": True}
     macros.append(('Py_LIMITED_API', '0x03060000'))
 else:
