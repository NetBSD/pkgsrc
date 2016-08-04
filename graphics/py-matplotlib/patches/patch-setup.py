$NetBSD: patch-setup.py,v 1.1 2016/08/04 00:04:19 kamil Exp $

--- setup.py.orig	2016-07-03 15:37:10.000000000 +0000
+++ setup.py
@@ -97,12 +97,12 @@ mpl_packages = [
     setupext.BackendMacOSX(),
     setupext.BackendQt5(),
     setupext.BackendQt4(),
-    setupext.BackendGtk3Agg(),
-    setupext.BackendGtk3Cairo(),
-    setupext.BackendGtkAgg(),
-    setupext.BackendTkAgg(),
-    setupext.BackendWxAgg(),
-    setupext.BackendGtk(),
+#    setupext.BackendGtk3Agg(),
+#    setupext.BackendGtk3Cairo(),
+#    setupext.BackendGtkAgg(),
+#    setupext.BackendTkAgg(),
+#    setupext.BackendWxAgg(),
+#    setupext.BackendGtk(),
     setupext.BackendAgg(),
     setupext.BackendCairo(),
     setupext.Windowing(),
