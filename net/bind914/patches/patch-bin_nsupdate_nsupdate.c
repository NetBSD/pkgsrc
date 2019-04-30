$NetBSD: patch-bin_nsupdate_nsupdate.c,v 1.1 2019/04/30 03:34:34 taca Exp $

* C syntax.

--- bin/nsupdate/nsupdate.c.orig	2019-04-06 20:09:59.000000000 +0000
+++ bin/nsupdate/nsupdate.c
@@ -214,7 +214,7 @@ typedef struct nsu_gssinfo {
 } nsu_gssinfo_t;
 
 static void
-failed_gssrequest();
+failed_gssrequest(void);
 static void
 start_gssrequest(dns_name_t *master);
 static void
@@ -2797,7 +2797,7 @@ get_ticket_realm(isc_mem_t *mctx) {
 }
 
 static void
-failed_gssrequest() {
+failed_gssrequest(void) {
 	seenerror = true;
 
 	dns_name_free(&tmpzonename, gmctx);
