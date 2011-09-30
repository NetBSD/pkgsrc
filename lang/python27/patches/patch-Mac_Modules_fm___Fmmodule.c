$NetBSD: patch-Mac_Modules_fm___Fmmodule.c,v 1.1 2011/09/30 08:37:24 yyamano Exp $

Fix build errors on Mac OS XLion.

--- Mac/Modules/fm/_Fmmodule.c.orig	2010-05-09 15:15:40.000000000 +0000
+++ Mac/Modules/fm/_Fmmodule.c
@@ -3,8 +3,14 @@
 
 #include "Python.h"
 
-#ifndef __LP64__
+#include <AvailabilityMacros.h>
+#if (__MAC_OS_X_VERSION_MAX_ALLOWED >= 1070) || defined(__LP64__)
+#undef HAVE_CARBON
+#else
+#define HAVE_CARBON
+#endif
 
+#ifdef HAVE_CARBON
 
 #include "pymactoolbox.h"
 
@@ -336,32 +342,32 @@ static PyMethodDef Fm_methods[] = {
     {NULL, NULL, 0}
 };
 
-#else  /* __LP64__ */
+#else  /* HAVE_CARBON */
 
 static PyMethodDef Fm_methods[] = {
     {NULL, NULL, 0}
 };
 
-#endif  /* __LP64__ */
+#endif  /* HAVE_CARBON */
 
 void init_Fm(void)
 {
     PyObject *m;
-#ifndef __LP64__
+#ifdef HAVE_CARBON
     PyObject *d;
-#endif  /* __LP64__ */
+#endif  /* HAVE_CARBON */
 
 
 
 
     m = Py_InitModule("_Fm", Fm_methods);
-#ifndef __LP64__
+#ifdef HAVE_CARBON
     d = PyModule_GetDict(m);
     Fm_Error = PyMac_GetOSErrException();
     if (Fm_Error == NULL ||
         PyDict_SetItemString(d, "Error", Fm_Error) != 0)
         return;
-#endif  /* __LP64__ */
+#endif  /* HAVE_CARBON */
 }
 
 /* ========================= End module _Fm ========================= */
