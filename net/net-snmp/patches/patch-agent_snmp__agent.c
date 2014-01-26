$NetBSD: patch-agent_snmp__agent.c,v 1.1 2014/01/26 21:33:06 spz Exp $

patch for CVE-2012-6151 from
http://sourceforge.net/p/net-snmp/patches/_discuss/thread/36675011/e98b/attachment/alt-cancel-next-walk-v2.patch

--- agent/snmp_agent.c.orig	2012-10-09 22:28:58.000000000 +0000
+++ agent/snmp_agent.c
@@ -1409,6 +1409,7 @@ init_agent_snmp_session(netsnmp_session 
     asp->treecache_num = -1;
     asp->treecache_len = 0;
     asp->reqinfo = SNMP_MALLOC_TYPEDEF(netsnmp_agent_request_info);
+    asp->flags = SNMP_AGENT_FLAGS_NONE;
     DEBUGMSGTL(("verbose:asp", "asp %p reqinfo %p created\n",
                 asp, asp->reqinfo));
 
@@ -1458,6 +1459,9 @@ netsnmp_check_for_delegated(netsnmp_agen
     if (NULL == asp->treecache)
         return 0;
     
+    if (asp->flags & SNMP_AGENT_FLAGS_CANCEL_IN_PROGRESS)
+        return 0;
+
     for (i = 0; i <= asp->treecache_num; i++) {
         for (request = asp->treecache[i].requests_begin; request;
              request = request->next) {
@@ -1535,39 +1539,48 @@ int
 netsnmp_remove_delegated_requests_for_session(netsnmp_session *sess)
 {
     netsnmp_agent_session *asp;
-    int count = 0;
+    int total_count = 0;
     
     for (asp = agent_delegated_list; asp; asp = asp->next) {
         /*
          * check each request
          */
+        int i;
+        int count = 0;
         netsnmp_request_info *request;
-        for(request = asp->requests; request; request = request->next) {
-            /*
-             * check session
-             */
-            netsnmp_assert(NULL!=request->subtree);
-            if(request->subtree->session != sess)
-                continue;
-
-            /*
-             * matched! mark request as done
-             */
-            netsnmp_request_set_error(request, SNMP_ERR_GENERR);
-            ++count;
+        for (i = 0; i <= asp->treecache_num; i++) {
+	    for(request = asp->requests; request;
+                request = request->next) {
+		/*
+		 * check session
+		 */
+		netsnmp_assert(NULL!=request->subtree);
+		if(request->subtree->session != sess)
+		    continue;
+
+		/*
+		 * matched! mark request as done
+		 */
+		netsnmp_request_set_error(request, SNMP_ERR_GENERR);
+		++count;
+	    }
+	}
+        if (count) {
+            asp->flags |= SNMP_AGENT_FLAGS_CANCEL_IN_PROGRESS;
+            total_count += count;
         }
     }
 
     /*
      * if we found any, that request may be finished now
      */
-    if(count) {
+    if(total_count) {
         DEBUGMSGTL(("snmp_agent", "removed %d delegated request(s) for session "
-                    "%8p\n", count, sess));
-        netsnmp_check_outstanding_agent_requests();
+                    "%8p\n", total_count, sess));
+        netsnmp_check_delegated_requests();
     }
     
-    return count;
+    return total_count;
 }
 
 int
@@ -2739,13 +2752,8 @@ handle_var_requests(netsnmp_agent_sessio
     return final_status;
 }
 
-/*
- * loop through our sessions known delegated sessions and check to see
- * if they've completed yet. If there are no more delegated sessions,
- * check for and process any queued requests
- */
 void
-netsnmp_check_outstanding_agent_requests(void)
+netsnmp_check_delegated_requests(void)
 {
     netsnmp_agent_session *asp, *prev_asp = NULL, *next_asp = NULL;
 
@@ -2790,6 +2798,22 @@ netsnmp_check_outstanding_agent_requests
             prev_asp = asp;
         }
     }
+}
+
+/*
+ * loop through our sessions known delegated sessions and check to see
+ * if they've completed yet. If there are no more delegated sessions,
+ * check for and process any queued requests
+ */
+void
+netsnmp_check_outstanding_agent_requests(void)
+{
+    netsnmp_agent_session *asp;
+
+    /*
+     * deal with delegated requests
+     */
+    netsnmp_check_delegated_requests();
 
     /*
      * if we are processing a set and there are more delegated
@@ -2819,7 +2843,8 @@ netsnmp_check_outstanding_agent_requests
 
             netsnmp_processing_set = netsnmp_agent_queued_list;
             DEBUGMSGTL(("snmp_agent", "SET request remains queued while "
-                        "delegated requests finish, asp = %8p\n", asp));
+                        "delegated requests finish, asp = %8p\n",
+                        agent_delegated_list));
             break;
         }
 #endif /* NETSNMP_NO_WRITE_SUPPORT */
@@ -2880,6 +2905,10 @@ check_delayed_request(netsnmp_agent_sess
     case SNMP_MSG_GETBULK:
     case SNMP_MSG_GETNEXT:
         netsnmp_check_all_requests_status(asp, 0);
+        if (asp->flags & SNMP_AGENT_FLAGS_CANCEL_IN_PROGRESS) {
+            DEBUGMSGTL(("snmp_agent","canceling next walk for asp %p\n", asp));
+            break;
+        }
         handle_getnext_loop(asp);
         if (netsnmp_check_for_delegated(asp) &&
             netsnmp_check_transaction_id(asp->pdu->transid) !=
