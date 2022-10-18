$NetBSD: patch-agent_mibgroup_host_hr__swrun.c,v 1.1 2022/10/18 12:01:52 adam Exp $

--- agent/mibgroup/host/hr_swrun.c.orig	2014-12-08 20:23:22.000000000 +0000
+++ agent/mibgroup/host/hr_swrun.c
@@ -1027,6 +1027,8 @@ var_hrswrun(struct variable * vp,
 	else
 	    long_return = 4;	/* application */
     #endif
+#elif defined darwin
+	long_return = -1;
 #else
 	long_return = 4;	/* application */
 #endif
