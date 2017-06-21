$NetBSD: patch-sendip.c,v 1.1.2.2 2017/06/21 18:20:04 bsiegert Exp $

Darwin compatibility, from Homebrew.

--- sendip.c.orig	2004-04-09 23:38:56.000000000 +0000
+++ sendip.c
@@ -48,7 +48,7 @@ void send_ip (char* src, char *dst, char
 	ip->ihl		= (IPHDR_SIZE + optlen + 3) >> 2;
 	ip->tos		= ip_tos;
 
-#if defined OSTYPE_FREEBSD || defined OSTYPE_NETBSD || defined OSTYPE_BSDI
+#if defined OSTYPE_DARWIN || OSTYPE_FREEBSD || defined OSTYPE_NETBSD || defined OSTYPE_BSDI
 /* FreeBSD */
 /* NetBSD */
 	ip->tot_len	= packetsize;
@@ -73,7 +73,7 @@ void send_ip (char* src, char *dst, char
 			htons((unsigned short) src_id);
 	}
 
-#if defined OSTYPE_FREEBSD || defined OSTYPE_NETBSD | defined OSTYPE_BSDI
+#if defined OSTYPE_DARWIN || OSTYPE_FREEBSD || defined OSTYPE_NETBSD | defined OSTYPE_BSDI
 /* FreeBSD */
 /* NetBSD */
 	ip->frag_off	|= more_fragments;
