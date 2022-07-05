$NetBSD: patch-setuptools__rust_rustc__info.py,v 1.1 2022/07/05 08:12:00 adam Exp $

https://github.com/PyO3/setuptools-rust/issues/262

--- setuptools_rust/rustc_info.py.orig	2022-07-05 06:20:44.000000000 +0000
+++ setuptools_rust/rustc_info.py
@@ -10,7 +10,7 @@ def get_rust_version() -> Optional[Versi
     try:
         # first line of rustc -Vv is something like
         # rustc 1.61.0 (fe5b13d68 2022-05-18)
-        return Version(_rust_version_verbose().split(" ")[1])
+        return Version(_rust_version().split(" ")[1])
     except (subprocess.CalledProcessError, OSError):
         return None
 
@@ -59,5 +59,10 @@ def get_rust_target_list() -> List[str]:
 
 
 @lru_cache()
+def _rust_version() -> str:
+    return subprocess.check_output(["rustc", "-V"], text=True)
+
+
+@lru_cache()
 def _rust_version_verbose() -> str:
     return subprocess.check_output(["rustc", "-Vv"], text=True)
