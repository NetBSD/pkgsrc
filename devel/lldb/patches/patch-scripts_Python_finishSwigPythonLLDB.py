$NetBSD: patch-scripts_Python_finishSwigPythonLLDB.py,v 1.2 2016/07/27 09:17:42 wiz Exp $

Don't conflict with lang/py-six.

--- scripts/Python/finishSwigPythonLLDB.py.orig	2016-05-19 21:02:17.000000000 +0000
+++ scripts/Python/finishSwigPythonLLDB.py
@@ -749,8 +749,8 @@ def main(vDictArgs):
     if bOk:
         bOk, strMsg = create_symlinks(vDictArgs, strFrameworkPythonDir, strLldbLibDir)
 
-    if bOk:
-        bOk, strMsg = copy_six(vDictArgs, strFrameworkPythonDir)
+    # if bOk:
+    #     bOk, strMsg = copy_six(vDictArgs, strFrameworkPythonDir)
 
     if bOk:
         bOk, strMsg = copy_lldbpy_file_to_lldb_pkg_dir(vDictArgs,
