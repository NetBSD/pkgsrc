$NetBSD: patch-tortoisehg_util_paths.py,v 1.2 2016/08/02 23:33:57 wiz Exp $

* include doc_path in paths

--- tortoisehg/util/paths.py.orig	2016-08-02 17:08:10.000000000 +0000
+++ tortoisehg/util/paths.py
@@ -7,9 +7,9 @@
 
 try:
     from tortoisehg.util.config import (icon_path, bin_path, license_path,
-                                        locale_path)
+                                        locale_path, doc_path)
 except ImportError:
-    icon_path, bin_path, license_path, locale_path = None, None, None, None
+    icon_path, bin_path, license_path, locale_path , doc_path = None, None, None, None, None
 
 import os, sys, shlex
 import mercurial
