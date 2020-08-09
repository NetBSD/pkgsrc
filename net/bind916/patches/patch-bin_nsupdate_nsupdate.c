$NetBSD: patch-bin_nsupdate_nsupdate.c,v 1.1 2020/08/09 15:20:22 taca Exp $

* C syntax.

--- bin/nsupdate/nsupdate.c.orig	2020-05-06 09:59:35.000000000 +0000
+++ bin/nsupdate/nsupdate.c
@@ -212,8 +212,6 @@ typedef struct nsu_gssinfo {
 } nsu_gssinfo_t;
 
 static void
-failed_gssrequest();
-static void
 start_gssrequest(dns_name_t *master);
 static void
 send_gssrequest(isc_sockaddr_t *destaddr, dns_message_t *msg,
@@ -2893,7 +2891,7 @@ get_ticket_realm(isc_mem_t *mctx) {
 }
 
 static void
-failed_gssrequest() {
+failed_gssrequest(void) {
 	seenerror = true;
 
 	dns_name_free(&tmpzonename, gmctx);
