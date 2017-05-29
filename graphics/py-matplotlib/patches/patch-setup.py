$NetBSD: patch-setup.py,v 1.2 2017/05/29 20:59:21 adam Exp $

Build only selected packages (see Makefile.common).

--- setup.py.orig	2017-05-29 17:27:20.000000000 +0000
+++ setup.py
@@ -100,12 +100,6 @@ mpl_packages = [
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
@@ -175,7 +175,7 @@ if __name__ == '__main__':
 
     required_failed = []
     good_packages = []
-    for package in mpl_packages:
+    for package in @MPL_PACKAGES@:
         if isinstance(package, str):
             print_raw('')
             print_raw(package.upper())
