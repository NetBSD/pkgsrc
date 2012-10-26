$NetBSD: patch-rtp_rtp__rm__pkt.c,v 1.1 2012/10/26 20:41:45 joerg Exp $

--- rtp/rtp_rm_pkt.c.orig	2012-10-26 16:07:08.000000000 +0000
+++ rtp/rtp_rm_pkt.c
@@ -28,7 +28,7 @@
 
 #include <nemesi/rtp.h>
 
-inline int rtp_rm_pkt(rtp_ssrc * stm_src)
+int rtp_rm_pkt(rtp_ssrc * stm_src)
 {
 	return bprmv(&(stm_src->rtp_sess->bp), &(stm_src->po),
 		     stm_src->po.potail);
