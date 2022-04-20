$NetBSD: patch-src_pip___internal_build__env.py,v 1.2 2022/04/20 21:04:12 wiz Exp $

Copy distutils distro config file to overlay.
https://github.com/pypa/pip/issues/10949

--- src/pip/_internal/build_env.py.orig	2022-03-07 07:42:01.000000000 +0000
+++ src/pip/_internal/build_env.py
@@ -9,6 +9,7 @@ import sys
 import textwrap
 import zipfile
 from collections import OrderedDict
+from shutil import copy
 from sysconfig import get_paths
 from types import TracebackType
 from typing import TYPE_CHECKING, Iterable, Iterator, List, Optional, Set, Tuple, Type
@@ -93,6 +94,9 @@ class BuildEnvironment:
         self._site_dir = os.path.join(temp_dir.path, "site")
         if not os.path.exists(self._site_dir):
             os.mkdir(self._site_dir)
+        distutils_distro_config = get_paths()["platlib"] + "/_distutils_system_mod.py"
+        if os.path.exists(distutils_distro_config):
+            copy(distutils_distro_config, self._site_dir)
         with open(
             os.path.join(self._site_dir, "sitecustomize.py"), "w", encoding="utf-8"
         ) as fp:
