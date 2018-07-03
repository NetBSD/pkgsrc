$NetBSD: patch-Modules_socketmodule.c,v 1.1 2018/07/03 03:55:40 adam Exp $

Support NetBSD's socketcan implementation

--- Modules/socketmodule.c.orig	2018-03-29 11:57:55.000000000 +0000
+++ Modules/socketmodule.c
@@ -1439,8 +1439,13 @@ makesockaddr(SOCKET_T sockfd, struct soc
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
 
         switch (proto) {
@@ -2010,7 +2015,12 @@ getsockaddrarg(PySocketSockObject *s, Py
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
@@ -7371,6 +7381,20 @@ PyInit__socket(void)
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
