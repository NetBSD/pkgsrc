$NetBSD: patch-tortoisehg_util_paths.py,v 1.1 2014/07/05 15:33:03 wiz Exp $

* include doc_path in paths

--- tortoisehg/util/paths.py.orig	2014-03-05 15:40:47.000000000 +0000
+++ tortoisehg/util/paths.py
@@ -7,9 +7,9 @@
 
 try:
     from tortoisehg.util.config import (icon_path, bin_path, license_path,
-                                        locale_path)
+                                        locale_path, doc_path)
 except ImportError:
-    icon_path, bin_path, license_path, locale_path = None, None, None, None
+    icon_path, bin_path, license_path, locale_path , doc_path = None, None, None, None, None
 
 import os, sys
 import mercurial
