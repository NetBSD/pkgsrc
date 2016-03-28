$NetBSD: patch-scripts_Python_finishSwigPythonLLDB.py,v 1.1 2016/03/28 13:13:55 kamil Exp $

Don't conflict with lang/py-six.

--- scripts/Python/finishSwigPythonLLDB.py.orig	2016-02-21 02:08:07.000000000 +0000
+++ scripts/Python/finishSwigPythonLLDB.py
@@ -719,8 +719,8 @@ def main(vDictArgs):
     if bOk:
         bOk, strMsg = create_symlinks(vDictArgs, strFrameworkPythonDir)
 
-    if bOk:
-        bOk, strMsg = copy_six(vDictArgs, strFrameworkPythonDir)
+    # if bOk:
+    #     bOk, strMsg = copy_six(vDictArgs, strFrameworkPythonDir)
 
     if bOk:
         bOk, strMsg = copy_lldbpy_file_to_lldb_pkg_dir(vDictArgs,
