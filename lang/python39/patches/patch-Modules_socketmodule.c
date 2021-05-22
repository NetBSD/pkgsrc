$NetBSD: patch-Modules_socketmodule.c,v 1.2 2021/05/22 11:36:01 bouyer Exp $

Support NetBSD's socketcan implementation

--- Modules/socketmodule.c.orig	2021-05-03 16:54:42.000000000 +0200
+++ Modules/socketmodule.c	2021-05-22 12:11:03.509965978 +0200
@@ -2157,7 +2157,7 @@
             PyObject *interfaceName;
             struct ifreq ifr;
             Py_ssize_t len;
-            struct sockaddr_can *addr = &addrbuf->can;
+            struct sockaddr_can *addr = (struct sockaddr_can *)addrbuf;
 
             if (!PyTuple_Check(args)) {
                 PyErr_Format(PyExc_TypeError,
@@ -7827,6 +7827,20 @@
 
     PyModule_AddIntMacro(m, J1939_FILTER_MAX);
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
