$NetBSD: patch-sm_mod_roster.c,v 1.1 2012/05/12 05:44:46 adam Exp $

Void function must not return any values.

--- sm/mod_roster.c.orig	2012-05-12 05:25:14.000000000 +0000
+++ sm/mod_roster.c
@@ -460,7 +460,7 @@ static void _roster_set_item(pkt_t pkt, 
     log_debug(ZONE, "added %s to roster (to %d from %d ask %d name %s ngroups %d)", jid_full(item->jid), item->to, item->from, item->ask, item->name, item->ngroups);
 
     if (sm_storage_rate_limit(sess->user->sm, jid_user(sess->user->jid)))
-        return -stanza_err_RESOURCE_CONSTRAINT;
+        return;
 
     /* save changes */
     _roster_save_item(sess->user, item);
