$NetBSD: patch-server.c,v 1.1 2013/03/02 17:59:41 joerg Exp $

--- server.c.orig	1995-10-19 15:20:24.000000000 +0000
+++ server.c
@@ -126,9 +126,7 @@ extern struct st_host_info hinfo[];
  *                              hinfo[host].system and hinfo[host].server
  *                              are set; otherwise a no-op.
  */
-determine_server_from_open(host, reply)
-int host;
-char *reply;
+void determine_server_from_open(int host, char *reply)
 {
 	int i;
 
@@ -148,9 +146,7 @@ char *reply;
  *                              hinfo[host].system and hinfo[host].server
  *                              are set; otherwise a no-op.
  */
-determine_server_from_syst(host, reply)
-int host;
-char *reply;
+void determine_server_from_syst(int host, char *reply)
 {
 	int i;
 
