$NetBSD: patch-tools_pythonpkg_setup.py,v 1.4 2025/08/03 16:09:18 ryoon Exp $

--- tools/pythonpkg/setup.py.orig	2025-06-16 06:39:30.000000000 +0000
+++ tools/pythonpkg/setup.py
@@ -480,7 +480,7 @@ setup(
     use_scm_version={
         "version_scheme": lambda v: bump_version(str(v.tag), v.distance, v.dirty),
         "root": "../..",
-        "fallback_version": "0.0.0",
+        "fallback_version": "@PKGVERSION_NOREV@",
         "local_scheme": "no-local-version",
     },
     cmdclass={"build_ext": build_ext},
