$NetBSD: patch-setup2.py,v 1.1 2011/02/23 10:46:18 adam Exp $

Fix setup with Python 2.7.

--- setup2.py.orig	2011-02-23 10:42:28.000000000 +0000
+++ setup2.py
@@ -36,7 +36,6 @@ if (sys.version_info[0] < 3) and (sys.ve
                         'Please use capsule objects instead.',
                 category=DeprecationWarning)
 
-            import bsddb  # Import the 2.7 version, that uses CObject
         finally :
             context.__exit__()
 
