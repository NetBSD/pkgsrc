$NetBSD: patch-signer_src_wire_query.c,v 1.1 2023/12/05 12:20:40 he Exp $

Be a bit more verbose about which zone isn't found...

--- signer/src/wire/query.c.orig	2021-02-20 21:04:47.000000000 +0000
+++ signer/src/wire/query.c
@@ -886,7 +886,13 @@ query_process(query_type* q, engine_type
     }
     pthread_mutex_unlock(&engine->zonelist->zl_lock);
     if (!q->zone) {
-        ods_log_debug("[%s] zone not found", query_str);
+	char *zn = ldns_rdf2str(ldns_rr_owner(rr));
+	if (zn) {
+            ods_log_debug("[%s] zone %s not found", query_str, zn);
+	    free(zn);
+	} else {
+            ods_log_debug("[%s] zone (unknown?) not found", query_str);
+	}
         ldns_pkt_free(pkt);
         return query_servfail(q);
     }
