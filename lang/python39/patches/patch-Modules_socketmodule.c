$NetBSD: patch-Modules_socketmodule.c,v 1.3 2022/01/20 13:06:33 jperkin Exp $

Support NetBSD's socketcan implementation

--- Modules/socketmodule.c.orig	2022-01-13 21:21:23.000000000 +0000
+++ Modules/socketmodule.c
@@ -2154,7 +2154,7 @@ getsockaddrarg(PySocketSockObject *s, Py
             PyObject *interfaceName;
             struct ifreq ifr;
             Py_ssize_t len;
-            struct sockaddr_can *addr = &addrbuf->can;
+            struct sockaddr_can *addr = (struct sockaddr_can *)addrbuf;
 
             if (!PyTuple_Check(args)) {
                 PyErr_Format(PyExc_TypeError,
@@ -5489,7 +5489,7 @@ socket_sethostname(PyObject *self, PyObj
     Py_buffer buf;
     int res, flag = 0;
 
-#ifdef _AIX
+#if defined(_AIX) || (defined(__sun) && PKGSRC_OPSYS_VERSION < 051100)
 /* issue #18259, not declared in any useful header file */
 extern int sethostname(const char *, size_t);
 #endif
@@ -7824,6 +7824,20 @@ PyInit__socket(void)
 
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
