$NetBSD: patch-agent_mibgroup_agentx_master.c,v 1.1 2014/01/26 21:33:06 spz Exp $

patch for CVE-2012-6151 from
http://sourceforge.net/p/net-snmp/patches/_discuss/thread/36675011/e98b/attachment/alt-cancel-next-walk-v2.patch

--- agent/mibgroup/agentx/master.c.orig	2012-10-09 22:28:58.000000000 +0000
+++ agent/mibgroup/agentx/master.c
@@ -219,7 +219,13 @@ agentx_got_response(int operation,
     if (!cache) {
         DEBUGMSGTL(("agentx/master", "response too late on session %8p\n",
                     session));
-        return 0;
+        /*
+         * Response is too late, free the cache and return 1
+         * so that the session pending request list item can be deleted
+         */
+        if (magic)
+            netsnmp_free_delegated_cache((netsnmp_delegated_cache*) magic);
+        return 1;
     }
     requests = cache->requests;
 
@@ -606,6 +612,8 @@ agentx_master_handler(netsnmp_mib_handle
     result = snmp_async_send(ax_session, pdu, agentx_got_response, cb_data);
     if (result == 0) {
         snmp_free_pdu(pdu);
+        if (cb_data)
+            netsnmp_free_delegated_cache((netsnmp_delegated_cache*) cb_data);
     }
 
     return SNMP_ERR_NOERROR;
