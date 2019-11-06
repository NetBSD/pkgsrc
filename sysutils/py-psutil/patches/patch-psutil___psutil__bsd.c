$NetBSD: patch-psutil___psutil__bsd.c,v 1.12 2019/11/06 15:48:23 adam Exp $

Optionally use SDEAD.

--- psutil/_psutil_bsd.c.orig	2019-10-21 06:43:32.000000000 +0000
+++ psutil/_psutil_bsd.c
@@ -1049,7 +1051,9 @@ static PyMethodDef mod_methods[] = {
     if (PyModule_AddIntConstant(mod, "SSLEEP", LSSLEEP)) INITERR;
     if (PyModule_AddIntConstant(mod, "SSTOP", LSSTOP)) INITERR;
     if (PyModule_AddIntConstant(mod, "SZOMB", LSZOMB)) INITERR;
+#if defined(LSDEAD)
     if (PyModule_AddIntConstant(mod, "SDEAD", LSDEAD)) INITERR;
+#endif
     if (PyModule_AddIntConstant(mod, "SONPROC", LSONPROC)) INITERR;
     // unique to NetBSD
     if (PyModule_AddIntConstant(mod, "SSUSPENDED", LSSUSPENDED)) INITERR;
