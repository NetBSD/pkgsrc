$NetBSD: patch-Modules_socketmodule.c,v 1.1 2020/10/10 20:20:12 adam Exp $

Support NetBSD's socketcan implementation

--- Modules/socketmodule.c.orig	2020-10-05 15:07:58.000000000 +0000
+++ Modules/socketmodule.c
@@ -7826,6 +7826,20 @@ PyInit__socket(void)
 
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
