$NetBSD: patch-tools_pythonpkg_setup.py,v 1.3 2025/06/24 14:29:26 ryoon Exp $

--- tools/pythonpkg/setup.py.orig	2025-05-21 11:38:48.000000000 +0000
+++ tools/pythonpkg/setup.py
@@ -420,7 +420,7 @@ def parse(root: str | Path, config: Conf
     try:
         return git_parse(root, config, describe_command=git_describe_command)
     except Exception:
-        return meta(tag="v0.0.0", distance=0, node="deadbeeff", config=config)
+        return meta(tag="v@PKGVERSION_NOREV@", distance=0, node="deadbeeff", config=config)
 
 
 def version_scheme(version):
@@ -471,7 +471,7 @@ setup(
         "version_scheme": version_scheme,
         "root": "../..",
         "parse": parse,
-        "fallback_version": "v0.0.0",
+        "fallback_version": "v@PKGVERSION_NOREV@",
         "local_scheme": "no-local-version",
     },
     cmdclass={"build_ext": build_ext},
