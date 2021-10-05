$NetBSD: patch-Modules_socketmodule.c,v 1.1 2021/10/05 19:07:13 adam Exp $

Support NetBSD's socketcan implementation

--- Modules/socketmodule.c.orig	2021-07-10 00:51:07.000000000 +0000
+++ Modules/socketmodule.c
@@ -2115,7 +2115,7 @@ getsockaddrarg(PySocketSockObject *s, Py
             PyObject *interfaceName;
             struct ifreq ifr;
             Py_ssize_t len;
-            struct sockaddr_can *addr = &addrbuf->can;
+            struct sockaddr_can *addr = (struct sockaddr_can *)addrbuf;
 
             if (!PyTuple_Check(args)) {
                 PyErr_Format(PyExc_TypeError,
@@ -7785,6 +7785,20 @@ PyInit__socket(void)
 
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
