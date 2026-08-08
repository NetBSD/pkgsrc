$NetBSD: patch-src_pip___internal_build__env_virtual.py,v 1.1 2026/08/08 07:40:20 wiz Exp $

Copy distutils distro config file to overlay.
https://github.com/pypa/pip/issues/10949

--- src/pip/_internal/build_env/virtual.py.orig	2026-08-08 07:34:39.398485754 +0000
+++ src/pip/_internal/build_env/virtual.py
@@ -6,6 +6,8 @@ from collections.abc import Iterable
 import textwrap
 from collections import OrderedDict
 from collections.abc import Iterable
+from shutil import copy
+from sysconfig import get_paths
 from types import TracebackType
 from typing import TYPE_CHECKING
 
@@ -58,6 +60,9 @@ class VirtualBuildEnvironment(BuildEnvironment):
         self._site_dir = os.path.join(temp_dir.path, "site")
         if not os.path.exists(self._site_dir):
             os.mkdir(self._site_dir)
+        distutils_distro_config = get_paths()["platlib"] + "/_distutils_system_mod.py"
+        if os.path.exists(distutils_distro_config):
+            copy(distutils_distro_config, self._site_dir)
         with open(
             os.path.join(self._site_dir, "sitecustomize.py"), "w", encoding="utf-8"
         ) as fp:
