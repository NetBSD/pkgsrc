$NetBSD: patch-mesonpy___tags.py,v 1.1 2026/09/08 19:50:55 adam Exp $

Restore ABI tag handling from 0.20.0 to fix building certain packages.

--- mesonpy/_tags.py.orig	2026-09-08 19:43:03.139256199 +0000
+++ mesonpy/_tags.py
@@ -31,6 +31,11 @@ def get_interpreter_tag() -> str:
     return f'{name}{version[0]}{version[1]}'
 
 
+def _get_cpython_abi() -> str:
+    version = sys.version_info
+    return f'cp{version[0]}{version[1]}'
+
+
 def get_abi_tag() -> str:
     # The best solution to obtain the Python ABI is to parse the
     # $SOABI or $EXT_SUFFIX sysconfig variables as defined in PEP-314.
@@ -39,7 +44,12 @@ def get_abi_tag() -> str:
     # Using $EXT_SUFFIX will not break when PyPy will fix this.
     # See https://foss.heptapod.net/pypy/pypy/-/issues/3816 and
     # https://github.com/pypa/packaging/pull/607.
-    empty, abi, ext = str(sysconfig.get_config_var('EXT_SUFFIX')).split('.')
+    try:
+        empty, abi, ext = str(sysconfig.get_config_var('EXT_SUFFIX')).split('.')
+    except ValueError as exc:
+        if sys.implementation.name != 'cpython':
+            raise NotImplementedError from exc
+        return _get_cpython_abi()
 
     # The packaging module initially based his understanding of the
     # $SOABI variable on the inconsistent value reported by PyPy, and
