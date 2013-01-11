$NetBSD: patch-sn__interface.h,v 1.2 2013/01/11 00:02:13 joerg Exp $

- make const declarations internally consistent

--- sn_interface.h.orig	1997-04-18 09:33:58.000000000 +0000
+++ sn_interface.h
@@ -29,7 +29,7 @@ void sig_blocking(char, int);
 void stop_logging (void);
 int check_mask (const struct packetheader *,const unsigned char *, char *, 
 					char *, struct unwrap *);
-pcap_handler interactive_packethandler( char *, const struct packetheader *,
+void interactive_packethandler(unsigned char *, const struct packetheader *,
                  		        const unsigned char *);
 void stop_packet_info (void);
 void packet_info_handler (int);
