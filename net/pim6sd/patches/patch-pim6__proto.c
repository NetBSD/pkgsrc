$NetBSD: patch-pim6__proto.c,v 1.1 2013/09/10 14:37:32 joerg Exp $

--- pim6_proto.c.orig	2013-09-10 12:22:49.000000000 +0000
+++ pim6_proto.c
@@ -1328,7 +1328,7 @@ join_or_prune(mrtentry_ptr, upstream_rou
     if_set     		entry_oifs;
     mrtentry_t     	*mrtentry_grp;
 
-    if ((mrtentry_ptr == NULL)) {
+    if (mrtentry_ptr == NULL) {
 	IF_DEBUG(DEBUG_PIM_JOIN_PRUNE)
 	    log_msg(LOG_DEBUG,0,"Join_or_prune : mrtentry_ptr is null");
 	return (PIM_ACTION_NOTHING);
