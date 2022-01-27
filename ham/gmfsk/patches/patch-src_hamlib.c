$NetBSD: patch-src_hamlib.c,v 1.1 2022/01/27 04:19:18 mef Exp $

hamlib.c:325:45: error: 'FILPATHLEN' undeclared 

--- src/hamlib.c.orig	2004-04-16 22:30:12.000000000 +0900
+++ src/hamlib.c	2022-01-27 13:15:02.849148846 +0900
@@ -322,8 +322,8 @@ void hamlib_init(void)
 	}
 	g_free(conf);
 
-	strncpy(rig->state.rigport.pathname, port, FILPATHLEN);
-	rig->state.rigport.pathname[FILPATHLEN - 1] = 0;
+	strncpy(rig->state.rigport.pathname, port, HAMLIB_FILPATHLEN);
+	rig->state.rigport.pathname[HAMLIB_FILPATHLEN - 1] = 0;
 
 	if (rig->caps->port_type == RIG_PORT_SERIAL)
 		rig->state.rigport.parm.serial.rate = speed;
