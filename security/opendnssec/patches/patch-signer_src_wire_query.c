$NetBSD: patch-signer_src_wire_query.c,v 1.1 2016/07/16 19:49:07 he Exp $

Add a check for whether we have an RRset in the query,
to side-step DoS via crafted packet.

--- signer/src/wire/query.c.orig	2016-05-02 10:40:02.000000000 +0000
+++ signer/src/wire/query.c
@@ -869,6 +869,10 @@ query_process(query_type* q, void* engin
         return query_formerr(q);
     }
     rr = ldns_rr_list_rr(ldns_pkt_question(pkt), 0);
+    if (rr == NULL) {
+	ods_log_debug("[%s] no RRset in query, ignoring", query_str);
+	return QUERY_DISCARDED; /* no RRset in query */
+    }
     lock_basic_lock(&e->zonelist->zl_lock);
     /* we can just lookup the zone, because we will only handle SOA queries,
        zone transfers, updates and notifies */
