$NetBSD: patch-psutil___psutil__bsd.c,v 1.11 2019/06/29 18:00:49 wiz Exp $

Define proc_cwd on NetBSD >= 8.99.42.

--- psutil/_psutil_bsd.c.orig	2019-06-11 04:04:44.000000000 +0000
+++ psutil/_psutil_bsd.c
@@ -921,6 +921,8 @@ PsutilMethods[] = {
 #if defined(PSUTIL_FREEBSD) || defined(PSUTIL_OPENBSD)
     {"proc_connections", psutil_proc_connections, METH_VARARGS,
      "Return connections opened by process"},
+#endif
+#if defined(PSUTIL_FREEBSD) || defined(PSUTIL_OPENBSD) || (defined(PSUTIL_NETBSD) && __NetBSD_Version__ >= 899004200)
     {"proc_cwd", psutil_proc_cwd, METH_VARARGS,
      "Return process current working directory."},
 #endif
@@ -1071,7 +1073,9 @@ void init_psutil_bsd(void)
     PyModule_AddIntConstant(module, "SSLEEP", LSSLEEP);
     PyModule_AddIntConstant(module, "SSTOP", LSSTOP);
     PyModule_AddIntConstant(module, "SZOMB", LSZOMB);
+#if defined(LSDEAD)
     PyModule_AddIntConstant(module, "SDEAD", LSDEAD);
+#endif
     PyModule_AddIntConstant(module, "SONPROC", LSONPROC);
     // unique to NetBSD
     PyModule_AddIntConstant(module, "SSUSPENDED", LSSUSPENDED);
