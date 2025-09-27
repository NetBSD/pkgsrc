$NetBSD: patch-tools_build__pytorch__libs.py,v 1.1 2025/09/27 01:19:55 ryoon Exp $

--- tools/build_pytorch_libs.py.orig	2025-08-06 17:08:06.000000000 +0000
+++ tools/build_pytorch_libs.py
@@ -86,12 +86,6 @@ def build_pytorch(
     cmake: CMake,
 ) -> None:
     my_env = _create_build_env()
-    if (
-        not check_negative_env_flag("USE_CUDA")
-        and not check_negative_env_flag("USE_NCCL")
-        and not check_env_flag("USE_SYSTEM_NCCL")
-    ):
-        checkout_nccl()
     build_test = not check_negative_env_flag("BUILD_TEST")
     cmake.generate(
         version, cmake_python_library, build_python, build_test, my_env, rerun_cmake
