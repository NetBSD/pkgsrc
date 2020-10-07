$NetBSD: patch-src_net_net_ip.cc,v 1.1 2020/10/07 00:43:05 thorpej Exp $

Add support for tap(4)-based networking.

--- src/net/net_ip.cc.orig	2020-10-05 23:02:21.375165006 +0000
+++ src/net/net_ip.cc	2020-10-05 23:02:33.181030722 +0000
@@ -155,7 +155,7 @@ void net_ip_tcp_checksum(unsigned char *
  *	1c1d1e1f202122232425262728292a2b
  *	2c2d2e2f3031323334353637
  */
-static void net_ip_icmp(struct net *net, void *extra,
+static void net_ip_icmp(struct net *net, struct nic_data *nic,
 	unsigned char *packet, int len)
 {
 	int type;
@@ -166,7 +166,7 @@ static void net_ip_icmp(struct net *net,
 	switch (type) {
 	case 8:	/*  ECHO request  */
 		debug("[ ICMP echo ]\n");
-		lp = net_allocate_ethernet_packet_link(net, extra, len);
+		lp = net_allocate_ethernet_packet_link(net, nic, len);
 
 		/*  Copy the old packet first:  */
 		memcpy(lp->data + 12, packet + 12, len - 12);
@@ -225,7 +225,7 @@ static void tcp_closeconnection(struct n
  *  This creates an ethernet packet for the guest OS with an ACK to the
  *  initial SYN packet.
  */
-void net_ip_tcp_connectionreply(struct net *net, void *extra,
+void net_ip_tcp_connectionreply(struct net *net, struct nic_data *nic,
 	int con_id, int connecting, unsigned char *data, int datalen, int rst)
 {
 	struct ethernet_packet_link *lp;
@@ -238,7 +238,7 @@ void net_ip_tcp_connectionreply(struct n
 	net->tcp_connections[con_id].tcp_id ++;
 	tcp_length = 20 + option_len + datalen;
 	ip_len = 20 + tcp_length;
-	lp = net_allocate_ethernet_packet_link(net, extra, 14 + ip_len);
+	lp = net_allocate_ethernet_packet_link(net, nic, 14 + ip_len);
 
 	/*  Ethernet header:  */
 	memcpy(lp->data + 0, net->tcp_connections[con_id].ethernet_address, 6);
@@ -376,7 +376,7 @@ void net_ip_tcp_connectionreply(struct n
  *	http://www.networksorcery.com/enp/protocol/tcp.htm
  *	http://www.tcpipguide.com/free/t_TCPIPTransmissionControlProtocolTCP.htm
  */
-static void net_ip_tcp(struct net *net, void *extra,
+static void net_ip_tcp(struct net *net, struct nic_data *nic,
 	unsigned char *packet, int len)
 {
 	int con_id, free_con_id, i, res;
@@ -585,7 +585,7 @@ static void net_ip_tcp(struct net *net, 
 
 	if (rst) {
 		debug("[ 'rst': disconnecting TCP connection %i ]\n", con_id);
-		net_ip_tcp_connectionreply(net, extra, con_id, 0, NULL, 0, 1);
+		net_ip_tcp_connectionreply(net, nic, con_id, 0, NULL, 0, 1);
 		tcp_closeconnection(net, con_id);
 		return;
 	}
@@ -596,7 +596,7 @@ static void net_ip_tcp(struct net *net, 
 		    "connection %i ]\n", con_id);
 
 		/*  Send an RST?  (TODO, this is wrong...)  */
-		net_ip_tcp_connectionreply(net, extra, con_id, 0, NULL, 0, 1);
+		net_ip_tcp_connectionreply(net, nic, con_id, 0, NULL, 0, 1);
 
 		/*  ... and forget about this connection:  */
 		tcp_closeconnection(net, con_id);
@@ -610,7 +610,7 @@ static void net_ip_tcp(struct net *net, 
 
 		/*  Send an ACK:  */
 		net->tcp_connections[con_id].state = TCP_OUTSIDE_CONNECTED;
-		net_ip_tcp_connectionreply(net, extra, con_id, 0, NULL, 0, 0);
+		net_ip_tcp_connectionreply(net, nic, con_id, 0, NULL, 0, 0);
 		net->tcp_connections[con_id].state = TCP_OUTSIDE_DISCONNECTED2;
 		return;
 	}
@@ -620,7 +620,7 @@ static void net_ip_tcp(struct net *net, 
 		    con_id);
 
 		/*  Send ACK:  */
-		net_ip_tcp_connectionreply(net, extra, con_id, 0, NULL, 0, 0);
+		net_ip_tcp_connectionreply(net, nic, con_id, 0, NULL, 0, 0);
 		net->tcp_connections[con_id].state = TCP_OUTSIDE_DISCONNECTED2;
 
 		/*  Return and send FIN:  */
@@ -725,7 +725,7 @@ debug("  all acked\n");
 
 ret:
 	/*  Send an ACK (or FIN) to the guest OS:  */
-	net_ip_tcp_connectionreply(net, extra, con_id, 0, NULL, 0, 0);
+	net_ip_tcp_connectionreply(net, nic, con_id, 0, NULL, 0, 0);
 }
 
 
@@ -746,7 +746,7 @@ ret:
  *	srcport=fffc dstport=0035 length=0028 chksum=76b6
  *	43e20100000100000000000003667470066e6574627364036f726700001c0001
  */
-static void net_ip_udp(struct net *net, void *extra,
+static void net_ip_udp(struct net *net, struct nic_data *nic,
 	unsigned char *packet, int len)
 {
 	int con_id, free_con_id, i, srcport, dstport, udp_len;
@@ -882,7 +882,8 @@ static void net_ip_udp(struct net *net, 
  *
  *  Handle an IP packet, coming from the emulated NIC.
  */
-void net_ip(struct net *net, void *extra, unsigned char *packet, int len)
+void net_ip(struct net *net, struct nic_data *nic, unsigned char *packet,
+	int len)
 {
 #if 1
 	int i;
@@ -913,13 +914,13 @@ void net_ip(struct net *net, void *extra
 		/*  IPv4:  */
 		switch (packet[23]) {
 		case 1:	/*  ICMP  */
-			net_ip_icmp(net, extra, packet, len);
+			net_ip_icmp(net, nic, packet, len);
 			break;
 		case 6:	/*  TCP  */
-			net_ip_tcp(net, extra, packet, len);
+			net_ip_tcp(net, nic, packet, len);
 			break;
 		case 17:/*  UDP  */
-			net_ip_udp(net, extra, packet, len);
+			net_ip_udp(net, nic, packet, len);
 			break;
 		default:
 			fatal("[ net: IP: UNIMPLEMENTED protocol %i ]\n",
@@ -939,7 +940,7 @@ void net_ip(struct net *net, void *extra
  *  Read http://tools.ietf.org/html/rfc2131 for details on DHCP.
  *  (And http://users.telenet.be/mydotcom/library/network/dhcp.htm.)
  */
-static void net_ip_broadcast_dhcp(struct net *net, void *extra,
+static void net_ip_broadcast_dhcp(struct net *net, struct nic_data *nic,
 	unsigned char *packet, int len)
 {
 	/*
@@ -1008,7 +1009,7 @@ static void net_ip_broadcast_dhcp(struct
 	fatal(" ]\n");
 
         reply_len = 307;
-        lp = net_allocate_ethernet_packet_link(net, extra, reply_len);
+        lp = net_allocate_ethernet_packet_link(net, nic, reply_len);
 
         /*  From old packet, copy everything before options field:  */
         memcpy(lp->data, packet, 278);
@@ -1130,7 +1131,7 @@ packet = lp->data;
  *  Handle an IP broadcast packet, coming from the emulated NIC.
  *  (This is usually a DHCP request, or similar.)
  */
-void net_ip_broadcast(struct net *net, void *extra,
+void net_ip_broadcast(struct net *net, struct nic_data *nic,
 	unsigned char *packet, int len)
 {
 	unsigned char *p = (unsigned char *) &net->netmask_ipv4;
@@ -1193,7 +1194,7 @@ void net_ip_broadcast(struct net *net, v
 	    packet[23] == 0x11 &&			/*  UDP  */
 	    packet[34] == 0 && packet[35] == 68 &&	/*  DHCP client  */
 	    packet[36] == 0 && packet[37] == 67) {	/*  DHCP server  */
-		net_ip_broadcast_dhcp(net, extra, packet, len);
+		net_ip_broadcast_dhcp(net, nic, packet, len);
 		return;
 	}
 
@@ -1222,7 +1223,7 @@ void net_ip_broadcast(struct net *net, v
  *
  *  Receive any available UDP packets (from the outside world).
  */
-void net_udp_rx_avail(struct net *net, void *extra)
+void net_udp_rx_avail(struct net *net, struct nic_data *nic)
 {
 	int received_packets_this_tick = 0;
 	int max_packets_this_tick = 200;
@@ -1326,7 +1327,7 @@ void net_udp_rx_avail(struct net *net, v
 
 			ip_len = 20 + this_packets_data_length;
 
-			lp = net_allocate_ethernet_packet_link(net, extra,
+			lp = net_allocate_ethernet_packet_link(net, nic,
 			    14 + 20 + this_packets_data_length);
 
 			/*  Ethernet header:  */
@@ -1381,7 +1382,7 @@ void net_udp_rx_avail(struct net *net, v
  *
  *  Receive any available TCP packets (from the outside world).
  */
-void net_tcp_rx_avail(struct net *net, void *extra)
+void net_tcp_rx_avail(struct net *net, struct nic_data *nic)
 {
 	int received_packets_this_tick = 0;
 	int max_packets_this_tick = 200;
@@ -1445,7 +1446,7 @@ void net_tcp_rx_avail(struct net *net, v
 			net->tcp_connections[con_id].state =
 			    TCP_OUTSIDE_CONNECTED;
 			debug("CHANGING TO TCP_OUTSIDE_CONNECTED\n");
-			net_ip_tcp_connectionreply(net, extra, con_id, 1,
+			net_ip_tcp_connectionreply(net, nic, con_id, 1,
 			    NULL, 0, 0);
 		}
 
@@ -1477,7 +1478,7 @@ void net_tcp_rx_avail(struct net *net, v
 				    net->tcp_connections[con_id].
 				    incoming_buf_seqnr;
 
-				net_ip_tcp_connectionreply(net, extra, con_id,
+				net_ip_tcp_connectionreply(net, nic, con_id,
 				    0, net->tcp_connections[con_id].
 				    incoming_buf,
 				    net->tcp_connections[con_id].
@@ -1519,21 +1520,21 @@ void net_tcp_rx_avail(struct net *net, v
 			memcpy(net->tcp_connections[con_id].incoming_buf,
 			    buf, res);
 
-			net_ip_tcp_connectionreply(net, extra, con_id, 0,
+			net_ip_tcp_connectionreply(net, nic, con_id, 0,
 			    buf, res, 0);
 		} else if (res == 0) {
 			net->tcp_connections[con_id].state =
 			    TCP_OUTSIDE_DISCONNECTED;
 			debug("CHANGING TO TCP_OUTSIDE_DISCONNECTED, read"
 			    " res=0\n");
-			net_ip_tcp_connectionreply(net, extra, con_id, 0,
+			net_ip_tcp_connectionreply(net, nic, con_id, 0,
 			    NULL, 0, 0);
 		} else {
 			net->tcp_connections[con_id].state =
 			    TCP_OUTSIDE_DISCONNECTED;
 			fatal("CHANGING TO TCP_OUTSIDE_DISCONNECTED, "
 			    "read res<=0, errno = %i\n", errno);
-			net_ip_tcp_connectionreply(net, extra, con_id, 0,
+			net_ip_tcp_connectionreply(net, nic, con_id, 0,
 			    NULL, 0, 0);
 		}
 
