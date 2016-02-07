$NetBSD: patch-fontforge_python.c,v 1.1 2016/02/07 14:09:08 adam Exp $

Fix for Python 3.5+.

--- fontforge/python.c.orig	2016-02-07 11:15:18.000000000 +0000
+++ fontforge/python.c
@@ -18174,7 +18174,11 @@ static PyObject* CreatePyModule( module_
     mdef->runtime.pymod_def.m_doc = mdef->docstring;
     mdef->runtime.pymod_def.m_methods = mdef->methods;
     mdef->runtime.pymod_def.m_size = -1;
+#if PY_MINOR_VERSION >= 5
+    mdef->runtime.pymod_def.m_slots = NULL;
+#else
     mdef->runtime.pymod_def.m_reload = NULL;
+#endif
     mdef->runtime.pymod_def.m_traverse = NULL;
     mdef->runtime.pymod_def.m_clear = NULL;
     mdef->runtime.pymod_def.m_free = NULL;
