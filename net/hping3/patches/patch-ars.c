$NetBSD: patch-ars.c,v 1.1.2.2 2017/06/21 18:20:04 bsiegert Exp $

Darwin compatibility, from Homebrew.

--- ars.c.orig	2004-04-14 12:30:18.000000000 +0000
+++ ars.c
@@ -914,7 +914,7 @@ int ars_bsd_fix(struct ars_packet *pkt,
 		return -ARS_INVALID;
 	}
 	ip = (struct ars_iphdr*) packet;
-#if defined OSTYPE_FREEBSD || defined OSTYPE_NETBSD || defined OSTYPE_BSDI
+#if defined OSTYPE_DARWIN || OSTYPE_FREEBSD || defined OSTYPE_NETBSD || defined OSTYPE_BSDI
 	ip->tot_len = ntohs(ip->tot_len);
 	ip->frag_off = ntohs(ip->frag_off);
 #endif
