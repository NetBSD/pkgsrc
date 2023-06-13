$NetBSD: patch-xgboost_libpath.py,v 1.1 2023/06/13 17:36:58 adam Exp $

Default to libxgboost.so when looking for dynamic library.

--- xgboost/libpath.py.orig	2023-06-13 17:27:59.000000000 +0000
+++ xgboost/libpath.py
@@ -43,13 +43,11 @@ def find_lib_path() -> List[str]:
             # directory here
             dll_path.append(os.path.join(curr_path, './windows/Release/'))
         dll_path = [os.path.join(p, 'xgboost.dll') for p in dll_path]
-    elif sys.platform.startswith(('linux', 'freebsd', 'emscripten')):
-        dll_path = [os.path.join(p, 'libxgboost.so') for p in dll_path]
     elif sys.platform == 'darwin':
         dll_path = [os.path.join(p, 'libxgboost.dylib') for p in dll_path]
     elif sys.platform == 'cygwin':
         dll_path = [os.path.join(p, 'cygxgboost.dll') for p in dll_path]
-    if platform.system() == 'OS400':
+    else:
         dll_path = [os.path.join(p, 'libxgboost.so') for p in dll_path]
 
     lib_path = [p for p in dll_path if os.path.exists(p) and os.path.isfile(p)]
