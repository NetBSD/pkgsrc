$NetBSD: patch-setup.py,v 1.1 2024/12/29 14:58:01 adam Exp $

Fix build: library_dirs must not be empty.
Do not force optimisation flag.

--- setup.py.orig	2024-11-18 05:53:16.000000000 +0000
+++ setup.py
@@ -62,8 +62,7 @@ if __name__ == "__main__":
             Extension(
                 "hyperscan._ext",
                 sources=["src/hyperscan/hyperscanmodule.c"],
-                library_dirs=os.getenv("LIBRARY_PATH", "").split(":"),
-                extra_compile_args=["-O0", "-DPCRE_STATIC"],
+                extra_compile_args=["-DPCRE_STATIC"],
                 # extra_link_args=["-Wl,--exclude-libs,ALL"],
                 **get_platform_specific_options(),
             )
