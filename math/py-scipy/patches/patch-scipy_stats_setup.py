$NetBSD: patch-scipy_stats_setup.py,v 1.1 2021/11/02 18:51:02 adam Exp $

Boost stats are not portable, e.g. compilation fails on NetBSD.

--- scipy/stats/setup.py.orig	2021-10-28 20:02:57.000000000 +0000
+++ scipy/stats/setup.py
@@ -79,7 +79,7 @@ def configuration(parent_package='', top
     ext._pre_build_hook = pre_build_hook
 
     # add boost stats distributions
-    config.add_subpackage('_boost')
+    #config.add_subpackage('_boost')
 
     # Type stubs
     config.add_data_files('*.pyi')
