$NetBSD: patch-Modules_socketmodule.c,v 1.1 2019/10/15 16:50:11 adam Exp $

Support NetBSD's socketcan implementation

--- Modules/socketmodule.c.orig	2019-09-06 08:21:57.000000000 +0000
+++ Modules/socketmodule.c
@@ -7709,6 +7709,20 @@ PyInit__socket(void)
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
