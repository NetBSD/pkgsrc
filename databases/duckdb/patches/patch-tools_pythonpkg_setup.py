$NetBSD: patch-tools_pythonpkg_setup.py,v 1.1 2025/06/15 13:30:19 ryoon Exp $

* For py-duckdb.

--- tools/pythonpkg/setup.py.orig	2025-05-22 14:32:56.526625573 +0000
+++ tools/pythonpkg/setup.py
@@ -471,7 +471,7 @@ setup(
         "version_scheme": version_scheme,
         "root": "../..",
         "parse": parse,
-        "fallback_version": "v0.0.0",
+        "fallback_version": "v@PKGVERSION_NOREV@",
         "local_scheme": "no-local-version",
     },
     cmdclass={"build_ext": build_ext},
