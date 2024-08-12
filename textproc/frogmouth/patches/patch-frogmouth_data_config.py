$NetBSD: patch-frogmouth_data_config.py,v 1.1 2024/08/12 10:07:30 wiz Exp $

https://github.com/Textualize/frogmouth/issues/100

--- frogmouth/data/config.py.orig	2024-08-12 09:56:01.097087580 +0000
+++ frogmouth/data/config.py
@@ -7,7 +7,7 @@ from functools import lru_cache
 from json import dumps, loads
 from pathlib import Path
 
-from xdg import xdg_config_home
+from xdg_base_dirs import xdg_config_home
 
 from ..utility.advertising import ORGANISATION_NAME, PACKAGE_NAME
 
