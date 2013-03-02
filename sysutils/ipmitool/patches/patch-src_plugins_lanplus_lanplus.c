$NetBSD: patch-src_plugins_lanplus_lanplus.c,v 1.1 2013/03/02 17:56:13 joerg Exp $

--- src/plugins/lanplus/lanplus.c.orig	2013-03-01 13:05:48.000000000 +0000
+++ src/plugins/lanplus/lanplus.c
@@ -734,7 +734,7 @@ ipmi_lan_poll_recv(struct ipmi_intf * in
       				ipmi_req_remove_entry(rsp->payload.ipmi_response.rq_seq,
 								rsp->payload.ipmi_response.cmd);
                   ipmi_lan_poll_recv(intf);
-                  return;
+                  return NULL;
 					}
 					else
 					{		
