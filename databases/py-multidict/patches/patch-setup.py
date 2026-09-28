$NetBSD: patch-setup.py,v 1.3 2026/09/28 15:45:34 wiz Exp $

Use CFLAGS from pkgsrc.

--- setup.py.orig	2026-09-26 17:37:59.797439000 +0000
+++ setup.py
@@ -13,7 +13,7 @@ if sys.implementation.name != "cpython":
 if sys.implementation.name != "cpython":
     NO_EXTENSIONS = True
 
-CFLAGS = ["-O0", "-g3", "-UNDEBUG"] if DEBUG_BUILD else ["-O3", "-DNDEBUG"]
+CFLAGS = ["-O0", "-g3", "-UNDEBUG"] if DEBUG_BUILD else ["-DNDEBUG"]
 LDFLAGS = []
 
 if NO_FREELIST:
