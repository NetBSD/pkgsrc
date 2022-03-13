$NetBSD: patch-installer_dcheck.py,v 1.5 2022/03/13 05:46:55 gutteridge Exp $

Locate libraries on systems without ldconfig(8)

This only looks for libraries in pkgsrc's own library folder, after the
subst framework in Makefile operates.

--- installer/dcheck.py.orig	2019-12-10 05:00:31.000000000 +0000
+++ installer/dcheck.py
@@ -99,6 +99,8 @@ def check_lib(lib, min_ver=0):
         #    pass
         #else:
         return True
+    elif check_file(lib+".so","/usr/lib"):
+        return True
     else:
         log.debug("Not found.")
         return False
