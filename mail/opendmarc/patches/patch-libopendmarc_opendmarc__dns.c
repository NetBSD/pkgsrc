$NetBSD: patch-libopendmarc_opendmarc__dns.c,v 1.4 2022/05/12 13:49:28 jperkin Exp $

Make sure res_init works on zeroed structure

--- libopendmarc/opendmarc_dns.c.orig	2021-12-20 06:40:37.000000000 +0000
+++ libopendmarc/opendmarc_dns.c
@@ -203,6 +203,7 @@ dmarc_dns_get_record(char *domain, int *
 		++bp;
 
 #ifdef HAVE_RES_NINIT   
+	memset(&resp, 0, sizeof(resp));
 	res_ninit(&resp);
 #ifdef RES_USE_DNSSEC
 	resp.options |= RES_USE_DNSSEC;
