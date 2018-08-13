$NetBSD: patch-source_Plugins_ScriptInterpreter_Python_PythonDataObjects.cpp,v 1.1 2018/08/13 06:14:22 adam Exp $

Fix building.

--- source/Plugins/ScriptInterpreter/Python/PythonDataObjects.cpp.orig	2018-08-05 18:21:37.000000000 +0000
+++ source/Plugins/ScriptInterpreter/Python/PythonDataObjects.cpp
@@ -404,7 +404,7 @@ llvm::StringRef PythonString::GetString(
     return llvm::StringRef();
 
   Py_ssize_t size;
-  char *c;
+  const char *c;
 
 #if PY_MAJOR_VERSION >= 3
   c = PyUnicode_AsUTF8AndSize(m_py_obj, &size);
