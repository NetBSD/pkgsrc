$NetBSD: patch-src_virtualenv_create_via__global__ref_api.py,v 1.5 2024/02/23 07:56:03 adam Exp $

Copy distutils distro config file to virtualenv.
https://github.com/pypa/virtualenv/issues/2313

--- src/virtualenv/create/via_global_ref/api.py.orig	2020-02-02 00:00:00.000000000 +0000
+++ src/virtualenv/create/via_global_ref/api.py
@@ -4,6 +4,8 @@ import logging
 import os
 from abc import ABC
 from pathlib import Path
+from shutil import copy
+from sysconfig import get_paths
 
 from virtualenv.create.creator import Creator, CreatorMeta
 from virtualenv.info import fs_supports_symlink
@@ -94,6 +96,10 @@ class ViaGlobalRefApi(Creator, ABC):
             logging.debug("create %s", dest_path)
             dest_path.write_text(text, encoding="utf-8")
 
+        distutils_distro_config = get_paths()["platlib"] + "/_distutils_system_mod.py"
+        if os.path.exists(distutils_distro_config):
+            copy(distutils_distro_config, self.platlib)
+
     def env_patch_text(self):
         """Patch the distutils package to not be derailed by its configuration files."""
         with self.app_data.ensure_extracted(Path(__file__).parent / "_virtualenv.py") as resolved_path:
