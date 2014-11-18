$NetBSD: patch-xlator_cluster_dht_src_dht-common.c,v 1.1 2014/11/18 14:38:15 manu Exp $

Shut up log-filling message

--- xlators/cluster/dht/src/dht-common.c.orig	2014-11-07 16:45:47.000000000 +0100
+++ xlators/cluster/dht/src/dht-common.c	2014-11-07 16:46:09.000000000 +0100
@@ -1817,9 +1817,9 @@
                       "fresh_lookup returned for %s with op_ret %d and "
                       "op_errno %d", loc->path, op_ret, op_errno);
 
         if (ENTRY_MISSING (op_ret, op_errno)) {
-                gf_log (this->name, GF_LOG_INFO, "Entry %s missing on subvol"
+                gf_log (this->name, GF_LOG_DEBUG, "Entry %s missing on subvol"
                               " %s", loc->path, prev->this->name);
                 if (conf->search_unhashed == GF_DHT_LOOKUP_UNHASHED_ON) {
                         local->op_errno = ENOENT;
                         dht_lookup_everywhere (frame, this, loc);
