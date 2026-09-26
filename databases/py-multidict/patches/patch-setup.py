$NetBSD: patch-setup.py,v 1.2 2026/09/26 10:18:39 wiz Exp $

Use CFLAGS from pkgsrc.

--- setup.py.orig	2026-09-21 16:18:55.298134000 +0000
+++ setup.py
@@ -12,7 +12,7 @@ if sys.implementation.name != "cpython":
 if sys.implementation.name != "cpython":
     NO_EXTENSIONS = True
 
-CFLAGS = ["-O0", "-g3", "-UNDEBUG"] if DEBUG_BUILD else ["-O3", "-DNDEBUG"]
+CFLAGS = ["-O0", "-g3", "-UNDEBUG"] if DEBUG_BUILD else ["-DNDEBUG"]
 LDFLAGS = []
 
 if platform.system() != "Windows":
