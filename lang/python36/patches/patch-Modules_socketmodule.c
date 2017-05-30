$NetBSD: patch-Modules_socketmodule.c,v 1.1 2017/05/30 13:36:39 bouyer Exp $

Support NetBSD's socketcan implementation

--- Modules/socketmodule.c.orig	2017-05-30 13:31:59.096006411 +0200
+++ Modules/socketmodule.c	2017-05-30 13:37:39.696032387 +0200
@@ -1405,8 +1405,13 @@
         /* need to look up interface name given index */
         if (a->can_ifindex) {
             ifr.ifr_ifindex = a->can_ifindex;
+#ifdef __NetBSD__
+            if (if_indextoname(a->can_ifindex, ifr.ifr_name) != NULL)
+                ifname = ifr.ifr_name;
+#else
             if (ioctl(sockfd, SIOCGIFNAME, &ifr) == 0)
                 ifname = ifr.ifr_name;
+#endif /* __NetBSD__ */
         }
 
         return Py_BuildValue("O&h", PyUnicode_DecodeFSDefault,
@@ -1905,12 +1910,14 @@
     }
 #endif
 
-#if defined(AF_CAN) && defined(CAN_RAW) && defined(CAN_BCM)
+#if defined(AF_CAN) && defined(CAN_RAW)
     case AF_CAN:
         switch (s->sock_proto) {
         case CAN_RAW:
+#ifdef CAN_BCM
         /* fall-through */
         case CAN_BCM:
+#endif
         {
             struct sockaddr_can *addr;
             PyObject *interfaceName;
@@ -1930,7 +1937,12 @@
             } else if ((size_t)len < sizeof(ifr.ifr_name)) {
                 strncpy(ifr.ifr_name, PyBytes_AS_STRING(interfaceName), sizeof(ifr.ifr_name));
                 ifr.ifr_name[(sizeof(ifr.ifr_name))-1] = '\0';
-                if (ioctl(s->sock_fd, SIOCGIFINDEX, &ifr) < 0) {
+#ifdef __NetBSD__
+                if ((ifr.ifr_ifindex = if_nametoindex(ifr.ifr_name)) == 0)
+#else
+                if (ioctl(s->sock_fd, SIOCGIFINDEX, &ifr) < 0)
+#endif
+		{
                     s->errorhandler();
                     Py_DECREF(interfaceName);
                     return 0;
@@ -7136,6 +7148,20 @@
     PyModule_AddIntConstant(m, "CAN_BCM_RX_TIMEOUT", RX_TIMEOUT);
     PyModule_AddIntConstant(m, "CAN_BCM_RX_CHANGED", RX_CHANGED);
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
