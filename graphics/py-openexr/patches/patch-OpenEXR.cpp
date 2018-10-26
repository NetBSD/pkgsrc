$NetBSD: patch-OpenEXR.cpp,v 1.1 2018/10/26 12:45:47 jperkin Exp $

Avoid CS define on SunOS.

--- OpenEXR.cpp.orig	2018-08-30 14:53:51.000000000 +0000
+++ OpenEXR.cpp
@@ -1,5 +1,9 @@
 #include <Python.h>
 
+#ifdef __sun
+#undef CS
+#endif
+
 #if PY_VERSION_HEX < 0x02050000 && !defined(PY_SSIZE_T_MIN)
 typedef int Py_ssize_t;
 #define PY_SSIZE_T_MAX INT_MAX
