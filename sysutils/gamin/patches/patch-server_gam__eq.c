$NetBSD: patch-server_gam__eq.c,v 1.1 2012/12/25 21:02:56 joerg Exp $

--- server/gam_eq.c.orig	2012-12-25 13:34:53.000000000 +0000
+++ server/gam_eq.c
@@ -124,7 +124,7 @@ gam_eq_flush (gam_eq_t *eq, GamConnDataP
 {
 	gboolean done_work = FALSE;
 	if (!eq)
-		return;
+		return FALSE;
 
 #ifdef GAM_EQ_VERBOSE
 	GAM_DEBUG(DEBUG_INFO, "gam_eq: Flushing event queue for %s\n", gam_connection_get_pidname (conn));
