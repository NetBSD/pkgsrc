$NetBSD: patch-Mac_Modules_qdoffs___Qdoffsmodule.c,v 1.1 2011/09/30 08:37:24 yyamano Exp $

Fix build errors on Mac OS XLion.

--- Mac/Modules/qdoffs/_Qdoffsmodule.c.orig	2010-05-09 15:15:40.000000000 +0000
+++ Mac/Modules/qdoffs/_Qdoffsmodule.c
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
 
@@ -631,10 +637,10 @@ static PyObject *Qdoffs_PutPixMapBytes(P
     return _res;
 
 }
-#endif /* __LP64__ */
+#endif /* HAVE_CARBON */
 
 static PyMethodDef Qdoffs_methods[] = {
-#ifndef __LP64__
+#ifdef HAVE_CARBON
     {"NewGWorld", (PyCFunction)Qdoffs_NewGWorld, 1,
      PyDoc_STR("(short PixelDepth, Rect boundsRect, CTabHandle cTable, GDHandle aGDevice, GWorldFlags flags) -> (GWorldPtr offscreenGWorld)")},
     {"LockPixels", (PyCFunction)Qdoffs_LockPixels, 1,
@@ -681,7 +687,7 @@ static PyMethodDef Qdoffs_methods[] = {
      PyDoc_STR("(pixmap, int start, int size) -> string. Return bytes from the pixmap")},
     {"PutPixMapBytes", (PyCFunction)Qdoffs_PutPixMapBytes, 1,
      PyDoc_STR("(pixmap, int start, string data). Store bytes into the pixmap")},
-#endif /* __LP64__ */
+#endif /* CARBON */
     {NULL, NULL, 0}
 };
 
@@ -691,7 +697,7 @@ static PyMethodDef Qdoffs_methods[] = {
 void init_Qdoffs(void)
 {
     PyObject *m;
-#ifndef __LP64__
+#ifdef HAVE_CARBON
     PyObject *d;
 
 
@@ -699,10 +705,10 @@ void init_Qdoffs(void)
         PyMac_INIT_TOOLBOX_OBJECT_NEW(GWorldPtr, GWorldObj_New);
         PyMac_INIT_TOOLBOX_OBJECT_CONVERT(GWorldPtr, GWorldObj_Convert);
 
-#endif /* __LP64__ */
+#endif /* HAVE_CARBON */
 
     m = Py_InitModule("_Qdoffs", Qdoffs_methods);
-#ifndef __LP64__
+#ifdef HAVE_CARBON
     d = PyModule_GetDict(m);
     Qdoffs_Error = PyMac_GetOSErrException();
     if (Qdoffs_Error == NULL ||
@@ -715,7 +721,7 @@ void init_Qdoffs(void)
     /* Backward-compatible name */
     Py_INCREF(&GWorld_Type);
     PyModule_AddObject(m, "GWorldType", (PyObject *)&GWorld_Type);
-#endif /* __LP64__ */
+#endif /* HAVE_CARBON */
 }
 
 /* ======================= End module _Qdoffs ======================= */
