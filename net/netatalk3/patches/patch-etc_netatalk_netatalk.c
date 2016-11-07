$NetBSD: patch-etc_netatalk_netatalk.c,v 1.2 2016/11/07 12:46:52 christos Exp $

We need EV_PERSIST for the sigterm handler to work.

--- etc/netatalk/netatalk.c.old	2014-11-19 05:22:07.000000000 -0500
+++ etc/netatalk/netatalk.c	2016-11-06 19:36:34.732675930 -0500
@@ -400,7 +400,7 @@
         netatalk_exit(EXITERR_CONF);
     }
 
-    sigterm_ev = event_new(base, SIGTERM, EV_SIGNAL, sigterm_cb, NULL);
+    sigterm_ev = event_new(base, SIGTERM, EV_SIGNAL | EV_PERSIST, sigterm_cb, NULL);
     sigquit_ev = event_new(base, SIGQUIT, EV_SIGNAL | EV_PERSIST, sigquit_cb, NULL);
     sighup_ev = event_new(base, SIGHUP,  EV_SIGNAL | EV_PERSIST, sighup_cb, NULL);
     sigchld_ev = event_new(base, SIGCHLD, EV_SIGNAL | EV_PERSIST, sigchld_cb, NULL);
