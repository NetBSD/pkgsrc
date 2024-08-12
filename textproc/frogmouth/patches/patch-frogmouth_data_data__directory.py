$NetBSD: patch-frogmouth_data_data__directory.py,v 1.1 2024/08/12 10:07:30 wiz Exp $

https://github.com/Textualize/frogmouth/issues/100

--- frogmouth/data/data_directory.py.orig	2024-08-12 09:56:10.984676267 +0000
+++ frogmouth/data/data_directory.py
@@ -2,7 +2,7 @@
 
 from pathlib import Path
 
-from xdg import xdg_data_home
+from xdg_base_dirs import xdg_data_home
 
 from ..utility.advertising import ORGANISATION_NAME, PACKAGE_NAME
 
