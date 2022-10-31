$NetBSD: patch-salt_utils_rsax931.py,v 1.1 2022/10/31 17:32:46 adam Exp $

Skip hacks for finding libcrypto on Darwin.

--- salt/utils/rsax931.py.orig	2022-10-31 16:43:56.000000000 +0000
+++ salt/utils/rsax931.py
@@ -25,7 +25,7 @@ def _find_libcrypto():
     """
     if sys.platform.startswith("win"):
         lib = "libeay32"
-    elif salt.utils.platform.is_darwin():
+    elif False:
         # will look for several different location on the system,
         # Search in the following order. salts pkg, homebrew, macports, finnally
         # system.
