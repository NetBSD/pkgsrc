$NetBSD: patch-Mac_Modules_qd___Qdmodule.c,v 1.1 2011/09/30 08:34:26 yyamano Exp $

Fix build errors on Mac OS XLion.

--- Mac/Modules/qd/_Qdmodule.c.orig	2010-05-09 15:15:40.000000000 +0000
+++ Mac/Modules/qd/_Qdmodule.c
@@ -3,8 +3,14 @@
 
 #include "Python.h"
 
+#include <AvailabilityMacros.h>
+#if (__MAC_OS_X_VERSION_MAX_ALLOWED >= 1070) || defined(__LP64__)
+#undef HAVE_CARBON
+#else
+#define HAVE_CARBON
+#endif
 
-#ifndef __LP64__
+#ifdef HAVE_CARBON
 
 #include "pymactoolbox.h"
 
@@ -6545,10 +6551,10 @@ static PyObject *Qd_RawBitMap(PyObject *
     return _res;
 
 }
-#endif /* __LP64__ */
+#endif /* HAVE_CARBON */
 
 static PyMethodDef Qd_methods[] = {
-#ifndef __LP64__
+#ifdef HAVE_CARBON
     {"GetPort", (PyCFunction)Qd_GetPort, 1,
      PyDoc_STR("() -> (GrafPtr port)")},
     {"GrafDevice", (PyCFunction)Qd_GrafDevice, 1,
@@ -7083,12 +7089,12 @@ static PyMethodDef Qd_methods[] = {
      PyDoc_STR("Take (string, int, Rect) argument and create BitMap")},
     {"RawBitMap", (PyCFunction)Qd_RawBitMap, 1,
      PyDoc_STR("Take string BitMap and turn into BitMap object")},
-#endif /* __LP64__ */
+#endif /* HAVE_CARBON */
     {NULL, NULL, 0}
 };
 
 
-#ifndef __LP64__
+#ifdef HAVE_CARBON
 
 /* Like BMObj_New, but the original bitmap data structure is copied (and
 ** released when the object is released)
@@ -7106,13 +7112,13 @@ PyObject *BMObj_NewCopied(BitMapPtr itse
     return (PyObject *)it;
 }
 
-#endif /* __LP64__ */
+#endif /* HAVE_CARBON */
 
 
 void init_Qd(void)
 {
     PyObject *m;
-#ifndef __LP64__
+#ifdef HAVE_CARBON
     PyObject *d;
 
 
@@ -7124,10 +7130,10 @@ void init_Qd(void)
         PyMac_INIT_TOOLBOX_OBJECT_NEW(RGBColorPtr, QdRGB_New);
         PyMac_INIT_TOOLBOX_OBJECT_CONVERT(RGBColor, QdRGB_Convert);
 
-#endif /* __LP64__ */
+#endif /* HAVE_CARBON */
 
     m = Py_InitModule("_Qd", Qd_methods);
-#ifndef __LP64__
+#ifdef HAVE_CARBON
     d = PyModule_GetDict(m);
     Qd_Error = PyMac_GetOSErrException();
     if (Qd_Error == NULL ||
@@ -7147,7 +7153,7 @@ void init_Qd(void)
     /* Backward-compatible name */
     Py_INCREF(&BitMap_Type);
     PyModule_AddObject(m, "BitMapType", (PyObject *)&BitMap_Type);
-#endif /* __LP64__ */
+#endif /* HAVE_CARBON */
 }
 
 /* ========================= End module _Qd ========================= */
