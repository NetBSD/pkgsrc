$NetBSD: patch-libheif_linux__build__libs.py,v 1.2 2025/03/16 12:58:12 wiz Exp $

Skip detection and build of libraries - provided by pkgsrc.

--- libheif/linux_build_libs.py.orig	2025-03-15 12:49:10.000000000 +0000
+++ libheif/linux_build_libs.py
@@ -77,6 +77,7 @@ def tool_check_version(name: str, min_ve
 
 
 def check_install_nasm(version: str):
+    return True
     if not match(r"(i[3-6]86|x86_64)$", machine()):
         return True
     if tool_check_version("nasm", version):
@@ -103,6 +104,7 @@ def is_musllinux() -> bool:
 
 
 def is_library_installed(name: str) -> bool:
+    return True
     if name.find("main") != -1 and name.find("reference") != -1:
         raise Exception("`name` param can not contain `main` and `reference` substrings.")
     result = run(f"gcc -l{name}".split(), stdout=PIPE, stderr=STDOUT, check=False)
