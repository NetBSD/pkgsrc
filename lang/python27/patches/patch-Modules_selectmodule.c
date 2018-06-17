$NetBSD: patch-Modules_selectmodule.c,v 1.1 2018/06/17 19:21:21 adam Exp $

--- Modules/selectmodule.c.orig	2014-12-10 15:59:55.000000000 +0000
+++ Modules/selectmodule.c
@@ -1906,7 +1906,9 @@ initselect(void)
     PyModule_AddIntConstant(m, "KQ_FILTER_NETDEV", EVFILT_NETDEV);
 #endif
     PyModule_AddIntConstant(m, "KQ_FILTER_SIGNAL", EVFILT_SIGNAL);
+#ifdef EVFILT_TIMER
     PyModule_AddIntConstant(m, "KQ_FILTER_TIMER", EVFILT_TIMER);
+#endif
 
     /* event flags */
     PyModule_AddIntConstant(m, "KQ_EV_ADD", EV_ADD);
