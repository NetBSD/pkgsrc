$NetBSD: patch-Lib_ctypes_____init____.py,v 1.1 2020/09/01 09:26:54 schmonz Exp $

Avoid MemoryError from "import ctypes" on OpenBSD.

--- Lib/ctypes/__init__.py.orig	Sun Apr 19 21:13:39 2020
+++ Lib/ctypes/__init__.py
@@ -273,7 +273,8 @@ def _reset_cache():
     # function is needed for the unittests on Win64 to succeed.  This MAY
     # be a compiler bug, since the problem occurs only when _ctypes is
     # compiled with the MS SDK compiler.  Or an uninitialized variable?
-    CFUNCTYPE(c_int)(lambda: None)
+    if not _sys.platform.startswith('openbsd'):
+        CFUNCTYPE(c_int)(lambda: None)
 
 try:
     from _ctypes import set_conversion_mode
