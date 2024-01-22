$NetBSD: patch-salt_utils_rsax931.py,v 1.2 2024/01/22 16:35:25 adam Exp $

Skip hacks for finding libcrypto on Darwin.

--- salt/utils/rsax931.py.orig	2023-12-12 18:03:35.000000000 +0000
+++ salt/utils/rsax931.py
@@ -31,7 +31,7 @@ def _find_libcrypto():
             if lib:
                 break
 
-    elif salt.utils.platform.is_darwin():
+    elif False:
         # will look for several different location on the system,
         # Search in the following order. salts pkg, homebrew, macports, finnally
         # system.
