$NetBSD: patch-src_pip___internal_build__env.py,v 1.9 2026/02/01 18:15:55 wiz Exp $

Copy distutils distro config file to overlay.
https://github.com/pypa/pip/issues/10949

--- src/pip/_internal/build_env.py.orig	2026-01-31 01:15:05.000000000 +0000
+++ src/pip/_internal/build_env.py
@@ -10,6 +10,8 @@ from collections.abc import Iterable, Sequence
 import textwrap
 from collections import OrderedDict
 from collections.abc import Iterable, Sequence
+from shutil import copy
+from sysconfig import get_paths
 from contextlib import AbstractContextManager as ContextManager
 from contextlib import nullcontext
 from io import StringIO
@@ -460,6 +462,9 @@ class BuildEnvironment:
         self._site_dir = os.path.join(temp_dir.path, "site")
         if not os.path.exists(self._site_dir):
             os.mkdir(self._site_dir)
+        distutils_distro_config = get_paths()["platlib"] + "/_distutils_system_mod.py"
+        if os.path.exists(distutils_distro_config):
+            copy(distutils_distro_config, self._site_dir)
         with open(
             os.path.join(self._site_dir, "sitecustomize.py"), "w", encoding="utf-8"
         ) as fp:
