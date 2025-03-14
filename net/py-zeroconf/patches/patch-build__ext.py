$NetBSD: patch-build__ext.py,v 1.1 2025/03/14 08:19:58 adam Exp $

Let pkgsrc handle compiler optimization flags.

--- build_ext.py.orig	2025-03-14 08:16:23.235236019 +0000
+++ build_ext.py
@@ -38,7 +38,6 @@ EXTENSIONS = [
         ext.removeprefix("src/").removesuffix(".py").replace("/", "."),
         [ext],
         language="c",
-        extra_compile_args=["-O3", "-g0"],
     )
     for ext in TO_CYTHONIZE
 ]
