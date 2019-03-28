$NetBSD: patch-src_python_grpcio_commands.py,v 1.2 2019/03/28 17:35:14 leot Exp $

Use dependencies in pkgsrc.

--- src/python/grpcio/commands.py.orig	2019-02-26 17:31:26.000000000 +0000
+++ src/python/grpcio/commands.py
@@ -218,7 +218,7 @@ class BuildExt(build_ext.build_ext):
         #   all C or all C++ compilation, the mix of C and C++ will crash.
         #   *By default*, the macOS use clang and Linux use gcc, that's why
         #   the special condition here is checking platform.
-        if "darwin" in sys.platform:
+        if False and "darwin" in sys.platform:
             config = os.environ.get('CONFIG', 'opt')
             target_path = os.path.abspath(
                 os.path.join(
