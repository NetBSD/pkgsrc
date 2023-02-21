$NetBSD: patch-src_pip___internal_build__env.py,v 1.5 2023/02/21 06:31:44 adam Exp $

Copy distutils distro config file to overlay.
https://github.com/pypa/pip/issues/10949

--- src/pip/_internal/build_env.py.orig	2023-02-17 18:31:10.000000000 +0000
+++ src/pip/_internal/build_env.py
@@ -8,6 +8,7 @@ import site
 import sys
 import textwrap
 from collections import OrderedDict
+from shutil import copy
 from types import TracebackType
 from typing import TYPE_CHECKING, Iterable, List, Optional, Set, Tuple, Type, Union
 
@@ -102,6 +103,9 @@ class BuildEnvironment:
         self._site_dir = os.path.join(temp_dir.path, "site")
         if not os.path.exists(self._site_dir):
             os.mkdir(self._site_dir)
+        distutils_distro_config = get_paths()["platlib"] + "/_distutils_system_mod.py"
+        if os.path.exists(distutils_distro_config):
+            copy(distutils_distro_config, self._site_dir)
         with open(
             os.path.join(self._site_dir, "sitecustomize.py"), "w", encoding="utf-8"
         ) as fp:
