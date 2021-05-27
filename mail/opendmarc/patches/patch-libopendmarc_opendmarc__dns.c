$NetBSD: patch-libopendmarc_opendmarc__dns.c,v 1.3 2021/05/27 16:52:00 manu Exp $

Make sure res_init works on zeroed structure

--- libopendmarc/opendmarc_dns.c.orig	2021-05-27 10:27:22.653313507 +0200
+++ libopendmarc/opendmarc_dns.c	2021-05-27 10:26:59.377412037 +0200
@@ -202,8 +202,9 @@
 	while (*bp == '.')
 		++bp;
 
 #ifdef HAVE_RES_NINIT   
+	memset(&resp, 0, sizeof(resp));
 	res_ninit(&resp);
 #ifdef RES_USE_DNSSEC
 	resp.options |= RES_USE_DNSSEC;
 #endif
