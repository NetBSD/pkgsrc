$NetBSD: patch-src_api_python_setup.py,v 1.2 2025/02/20 10:27:01 adam Exp $

Some platforms do not support LTO.

--- src/api/python/setup.py.orig	2025-02-18 21:41:31.000000000 +0000
+++ src/api/python/setup.py
@@ -26,7 +26,7 @@ SRC_DIR_REPO = os.path.join(ROOT_DIR, '.
 SRC_DIR = SRC_DIR_LOCAL if os.path.exists(SRC_DIR_LOCAL) else SRC_DIR_REPO
 
 IS_SINGLE_THREADED = False
-ENABLE_LTO = True
+ENABLE_LTO = False
 
 IS_PYODIDE = 'PYODIDE_ROOT' in os.environ and os.environ.get('_PYTHON_HOST_PLATFORM', '').startswith('emscripten')
 
