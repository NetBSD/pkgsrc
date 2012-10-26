$NetBSD: patch-rtp_rtpparsers_rtpparsers.c,v 1.1 2012/10/26 20:41:45 joerg Exp $

--- rtp/rtpparsers/rtpparsers.c.orig	2012-10-26 16:08:03.000000000 +0000
+++ rtp/rtpparsers/rtpparsers.c
@@ -131,7 +131,7 @@ void rtp_parsers_new(rtp_parser * new_pa
 	       sizeof(rtp_parsers_inits));
 }
 
-inline void rtp_parser_set_uninit(rtp_session * rtp_sess, unsigned pt,
+void rtp_parser_set_uninit(rtp_session * rtp_sess, unsigned pt,
 				  rtp_parser_uninit parser_uninit)
 {
 	rtp_sess->parsers_uninits[pt] = parser_uninit;
