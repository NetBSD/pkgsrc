$NetBSD: patch-scripts_Python_finishSwigPythonLLDB.py,v 1.3 2017/03/17 22:38:17 adam Exp $

Don't conflict with lang/py-six.

--- scripts/Python/finishSwigPythonLLDB.py.orig	2016-10-27 22:51:41.000000000 +0000
+++ scripts/Python/finishSwigPythonLLDB.py
@@ -821,8 +821,6 @@ def main(vDictArgs):
         bOk, strMsg = create_symlinks(
             vDictArgs, strFrameworkPythonDir, strLldbLibDir)
 
-    if bOk:
-        bOk, strMsg = copy_six(vDictArgs, strFrameworkPythonDir)
 
     if bOk:
         bOk, strMsg = copy_lldbpy_file_to_lldb_pkg_dir(vDictArgs,
