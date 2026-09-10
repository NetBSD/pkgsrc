$NetBSD: patch-setup.py,v 1.1 2026/09/10 11:32:24 adam Exp $

Use CFLAGS from pkgsrc.

--- setup.py.orig	2026-09-09 12:34:28.056868300 +0000
+++ setup.py
@@ -10,7 +10,7 @@ DEBUG_BUILD = bool(os.environ.get("MULTI
 if sys.implementation.name != "cpython":
     NO_EXTENSIONS = True
 
-CFLAGS = ["-O0", "-g3", "-UNDEBUG"] if DEBUG_BUILD else ["-O3", "-DNDEBUG"]
+CFLAGS = ["-O0", "-g3", "-UNDEBUG"] if DEBUG_BUILD else ["-DNDEBUG"]
 
 if platform.system() != "Windows":
     CFLAGS.extend(
