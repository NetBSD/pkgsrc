$NetBSD: patch-python_uv__build_____init____.py,v 1.1 2025/11/17 08:11:23 adam Exp $

Find versioned binary.

--- python/uv_build/__init__.py.orig	2025-11-17 07:49:39.731763510 +0000
+++ python/uv_build/__init__.py
@@ -45,6 +45,7 @@ def call(
     warn_config_settings(config_settings)
 
     uv_bin_name = "uv" if USE_UV_EXECUTABLE else "uv-build"
+    uv_bin_name += f"-{sys.version_info.major}.{sys.version_info.minor}"
     # Unlike `find_uv_bin`, this mechanism must work according to PEP 517
     uv_bin = shutil.which(uv_bin_name)
     if uv_bin is None:
