$NetBSD: patch-include_net-snmp_agent_snmp__agent.h,v 1.1 2014/01/26 21:33:06 spz Exp $

patch for CVE-2012-6151 from
http://sourceforge.net/p/net-snmp/patches/_discuss/thread/36675011/e98b/attachment/alt-cancel-next-walk-v2.patch

--- include/net-snmp/agent/snmp_agent.h.orig	2012-10-09 22:28:58.000000000 +0000
+++ include/net-snmp/agent/snmp_agent.h
@@ -32,6 +32,9 @@ extern          "C" {
 #define SNMP_MAX_PDU_SIZE 64000 /* local constraint on PDU size sent by agent
                                  * (see also SNMP_MAX_MSG_SIZE in snmp_api.h) */
 
+#define SNMP_AGENT_FLAGS_NONE                   0x0
+#define SNMP_AGENT_FLAGS_CANCEL_IN_PROGRESS     0x1
+
     /*
      * If non-zero, causes the addresses of peers to be logged when receptions
      * occur.  
@@ -205,6 +208,7 @@ extern          "C" {
         int             treecache_num;  /* number of current cache entries */
         netsnmp_cachemap *cache_store;
         int             vbcount;
+        int             flags;
     } netsnmp_agent_session;
 
     /*
@@ -240,6 +244,7 @@ extern          "C" {
     int             init_master_agent(void);
     void            shutdown_master_agent(void);
     int             agent_check_and_process(int block);
+    void            netsnmp_check_delegated_requests(void);
     void            netsnmp_check_outstanding_agent_requests(void);
 
     int             netsnmp_request_set_error(netsnmp_request_info *request,
