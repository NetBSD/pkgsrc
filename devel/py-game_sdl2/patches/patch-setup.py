$NetBSD: patch-setup.py,v 1.1 2025/05/12 05:18:50 ryoon Exp $

--- setup.py.orig	2025-05-11 13:19:44.688031560 +0000
+++ setup.py
@@ -169,7 +169,7 @@ if __name__ == "__main__":
         if virtual_env:
             headers_dir = pathlib.Path(virtual_env) / "include" / "pygame_sdl2"
         else:
-            headers_dir = pathlib.Path(sysconfig.get_paths()['include']) / "pygame_sdl2"
+            headers_dir = pathlib.Path("@DESTDIR@@PREFIX@/@PYINC@/pygame_sdl2")
 
         headers_dir.mkdir(parents=True, exist_ok=True)
 
