$NetBSD: patch-src_pip___internal_build__env.py,v 1.8 2025/10/28 09:44:51 adam Exp $

Copy distutils distro config file to overlay.
https://github.com/pypa/pip/issues/10949

--- src/pip/_internal/build_env.py.orig	2025-10-25 00:06:22.000000000 +0000
+++ src/pip/_internal/build_env.py
@@ -10,6 +10,8 @@ import sys
 import textwrap
 from collections import OrderedDict
 from collections.abc import Iterable
+from shutil import copy
+from sysconfig import get_paths
 from types import TracebackType
 from typing import TYPE_CHECKING, Protocol, TypedDict
 
@@ -271,6 +273,9 @@ class BuildEnvironment:
         self._site_dir = os.path.join(temp_dir.path, "site")
         if not os.path.exists(self._site_dir):
             os.mkdir(self._site_dir)
+        distutils_distro_config = get_paths()["platlib"] + "/_distutils_system_mod.py"
+        if os.path.exists(distutils_distro_config):
+            copy(distutils_distro_config, self._site_dir)
         with open(
             os.path.join(self._site_dir, "sitecustomize.py"), "w", encoding="utf-8"
         ) as fp:
