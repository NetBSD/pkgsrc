$NetBSD: patch-conf.c,v 1.1.2.2 2015/04/15 21:13:51 tron Exp $

Prepare for SUBST, not processed by configure.

--- conf.c.orig	2013-08-08 13:58:07.000000000 +0000
+++ conf.c
@@ -197,7 +197,7 @@ static IPAddr bind_cmd_address4, bind_cm
 
 /* Filename to use for storing pid of running chronyd, to prevent multiple
  * chronyds being started. */
-static char *pidfile = "/var/run/chronyd.pid";
+static char *pidfile = "@VARBASE@/run/chronyd.pid";
 
 /* Temperature sensor, update interval and compensation coefficients */
 static char *tempcomp_file = NULL;
