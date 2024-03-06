$NetBSD: patch-salt_utils_rsax931.py,v 1.3 2024/03/06 19:11:53 adam Exp $

Skip hacks for finding libcrypto on Darwin.

--- salt/utils/rsax931.py.orig	2024-02-20 22:04:07.000000000 +0000
+++ salt/utils/rsax931.py
@@ -30,7 +30,7 @@ def _find_libcrypto():
             if lib:
                 break
 
-    elif salt.utils.platform.is_darwin():
+    elif False:
         # will look for several different location on the system,
         # Search in the following order:
         # - salt's pkg install location
