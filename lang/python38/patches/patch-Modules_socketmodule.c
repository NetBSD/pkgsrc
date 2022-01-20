$NetBSD: patch-Modules_socketmodule.c,v 1.2 2022/01/20 11:52:28 jperkin Exp $

Support NetBSD's socketcan implementation

--- Modules/socketmodule.c.orig	2021-08-30 14:26:41.000000000 +0000
+++ Modules/socketmodule.c
@@ -5409,7 +5409,7 @@ socket_sethostname(PyObject *self, PyObj
     Py_buffer buf;
     int res, flag = 0;
 
-#ifdef _AIX
+#if defined(_AIX) || (defined(__sun) && PKGSRC_OPSYS_VERSION < 051100)
 /* issue #18259, not declared in any useful header file */
 extern int sethostname(const char *, size_t);
 #endif
@@ -7701,6 +7701,20 @@ PyInit__socket(void)
     PyModule_AddIntConstant(m, "CAN_BCM_CAN_FD_FRAME", CAN_FD_FRAME);
 #endif
 #endif
+#ifdef HAVE_NETCAN_CAN_H
+    PyModule_AddIntMacro(m, CAN_EFF_FLAG);
+    PyModule_AddIntMacro(m, CAN_RTR_FLAG);
+    PyModule_AddIntMacro(m, CAN_ERR_FLAG);
+
+    PyModule_AddIntMacro(m, CAN_SFF_MASK);
+    PyModule_AddIntMacro(m, CAN_EFF_MASK);
+    PyModule_AddIntMacro(m, CAN_ERR_MASK);
+
+    PyModule_AddIntMacro(m, CAN_RAW_FILTER);
+    /* PyModule_AddIntMacro(m, CAN_RAW_ERR_FILTER); */
+    PyModule_AddIntMacro(m, CAN_RAW_LOOPBACK);
+    PyModule_AddIntMacro(m, CAN_RAW_RECV_OWN_MSGS);
+#endif
 #ifdef SOL_RDS
     PyModule_AddIntMacro(m, SOL_RDS);
 #endif
