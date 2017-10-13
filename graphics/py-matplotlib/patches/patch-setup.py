$NetBSD: patch-setup.py,v 1.3 2017/10/13 09:50:35 adam Exp $

Build only selected packages (see Makefile.common).

--- setup.py.orig	2017-10-07 19:25:46.000000000 +0000
+++ setup.py
@@ -99,12 +99,6 @@ mpl_packages = [
     setupext.BackendMacOSX(),
     setupext.BackendQt5(),
     setupext.BackendQt4(),
-    setupext.BackendGtk3Agg(),
-    setupext.BackendGtk3Cairo(),
-    setupext.BackendGtkAgg(),
-    setupext.BackendTkAgg(),
-    setupext.BackendWxAgg(),
-    setupext.BackendGtk(),
     setupext.BackendAgg(),
     setupext.BackendCairo(),
     setupext.Windowing(),
@@ -180,7 +174,7 @@ if __name__ == '__main__':
 
         required_failed = []
         good_packages = []
-        for package in mpl_packages:
+        for package in @MPL_PACKAGES@:
             if isinstance(package, str):
                 print_raw('')
                 print_raw(package.upper())
