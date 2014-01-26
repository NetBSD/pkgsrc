$NetBSD: patch-agent_mibgroup_agentx_master_admin.c,v 1.1 2014/01/26 21:33:06 spz Exp $

patch for CVE-2012-6151 from
http://sourceforge.net/p/net-snmp/patches/_discuss/thread/36675011/e98b/attachment/alt-cancel-next-walk-v2.patch

--- agent/mibgroup/agentx/master_admin.c.orig	2012-10-09 22:28:58.000000000 +0000
+++ agent/mibgroup/agentx/master_admin.c
@@ -153,6 +153,7 @@ close_agentx_session(netsnmp_session * s
     for (sp = session->subsession; sp != NULL; sp = sp->next) {
 
         if (sp->sessid == sessid) {
+            netsnmp_remove_delegated_requests_for_session(sp);
             unregister_mibs_by_session(sp);
             unregister_index_by_session(sp);
             unregister_sysORTable_by_session(sp);
