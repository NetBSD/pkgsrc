$NetBSD: patch-setup.py,v 1.1 2026/09/03 08:25:05 adam Exp $

Use system zstd.
Let pkgsrc handle compiler arguments.

--- setup.py.orig	2026-09-03 07:54:01.011844957 +0000
+++ setup.py
@@ -28,12 +28,7 @@ UnixCCompiler.src_extensions.append(".S"
 
 _PLATFORM_IS_WIN = sysconfig.get_platform().startswith("win")
 _USE_CFFI = platform.python_implementation() == "PyPy"
-try:
-    sys.argv.remove("--system-zstd")
-except ValueError:
-    _SYSTEM_ZSTD = False
-else:
-    _SYSTEM_ZSTD = True
+_SYSTEM_ZSTD = True
 
 
 def locate_sources(*sub_paths):
@@ -53,11 +48,6 @@ def build_extension():
         ],
     )
 
-    if _PLATFORM_IS_WIN:
-        kwargs["extra_compile_args"] += ["/Ob3", "/GF", "/Gy"]
-    else:
-        kwargs["extra_compile_args"] += ["-g0", "-flto"]
-        kwargs["extra_link_args"] += ["-g0", "-flto"]
 
     if _SYSTEM_ZSTD:
         kwargs["libraries"].append("zstd")
