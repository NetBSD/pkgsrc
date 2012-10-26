$NetBSD: patch-rtp_rtp__transport__wrappers.c,v 1.1 2012/10/26 20:41:45 joerg Exp $

--- rtp/rtp_transport_wrappers.c.orig	2012-10-26 16:04:56.000000000 +0000
+++ rtp/rtp_transport_wrappers.c
@@ -34,7 +34,7 @@ inline char *rtp_get_spec(rtp_session * 
 	return rtp_sess->transport.spec;
 }
 
-inline enum deliveries rtp_get_delivery(rtp_session * rtp_sess)
+enum deliveries rtp_get_delivery(rtp_session * rtp_sess)
 {
 	return rtp_sess->transport.delivery;
 }
@@ -63,22 +63,22 @@ inline nms_addr *rtp_get_dstaddr(rtp_ses
 	return &rtp_sess->transport.RTP.u.udp.dstaddr;
 }
 
-inline enum modes rtp_get_mode(rtp_session * rtp_sess)
+enum modes rtp_get_mode(rtp_session * rtp_sess)
 {
 	return rtp_sess->transport.mode;
 }
 
-inline int rtp_get_layers(rtp_session * rtp_sess)
+int rtp_get_layers(rtp_session * rtp_sess)
 {
 	return rtp_sess->transport.layers;
 }
 
-inline int rtp_get_append(rtp_session * rtp_sess)
+int rtp_get_append(rtp_session * rtp_sess)
 {
 	return rtp_sess->transport.append;
 }
 
-inline int rtp_get_ttl(rtp_session * rtp_sess)
+int rtp_get_ttl(rtp_session * rtp_sess)
 {
 	return rtp_sess->transport.ttl;
 }
@@ -93,7 +93,7 @@ inline in_port_t rtp_get_mcsrtcpport(rtp
 	return rtp_sess->transport.RTCP.multicast_port;
 }
 
-inline int rtp_get_mcsports(rtp_session * rtp_sess, in_port_t ports[2])
+int rtp_get_mcsports(rtp_session * rtp_sess, in_port_t ports[2])
 {
 	return rtp_transport_get(rtp_sess, RTP_TRANSPORT_MCSPORTS, ports,
 				 sizeof(ports));
@@ -125,7 +125,7 @@ inline in_port_t rtp_get_clirtcpport(rtp
 	return rtp_sess->transport.RTCP.local_port;
 }
 
-inline int rtp_get_cliports(rtp_session * rtp_sess, in_port_t ports[2])
+int rtp_get_cliports(rtp_session * rtp_sess, in_port_t ports[2])
 {
 	return rtp_transport_get(rtp_sess, RTP_TRANSPORT_CLIPORTS, ports,
 				 sizeof(ports));
@@ -141,7 +141,7 @@ inline uint8 rtp_get_ilvdrtcp(rtp_sessio
 	return rtp_sess->transport.RTCP.u.tcp.ilvd;
 }
 
-inline int rtp_get_interleaved(rtp_session * rtp_sess, uint8 ilvds[2])
+int rtp_get_interleaved(rtp_session * rtp_sess, uint8 ilvds[2])
 {
 	return rtp_transport_get(rtp_sess, RTP_TRANSPORT_INTERLEAVED, ilvds,
 				 sizeof(ilvds));
@@ -163,7 +163,7 @@ inline int rtp_get_streams(rtp_session *
 				 sizeof(streams));
 }
 
-inline uint32 rtp_get_ssrc(rtp_session * rtp_sess)
+uint32 rtp_get_ssrc(rtp_session * rtp_sess)
 {
 	return rtp_sess->transport.ssrc;
 }
