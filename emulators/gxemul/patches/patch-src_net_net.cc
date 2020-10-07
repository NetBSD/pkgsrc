$NetBSD: patch-src_net_net.cc,v 1.1 2020/10/07 00:43:05 thorpej Exp $

Add support for tap(4)-based networking.

--- src/net/net.cc.orig	2020-10-05 23:00:24.839832619 +0000
+++ src/net/net.cc	2020-10-05 23:00:41.597469289 +0000
@@ -30,10 +30,10 @@
  *  (Read the README file in this directory for more details.)
  *
  *
- *  NOTE: The 'extra' argument used in many functions in this file is a pointer
- *  to something unique for each NIC (i.e. the NIC itself :-), so that if
- *  multiple NICs are emulated concurrently, they will not get packets that
- *  are meant for some other controller.
+ *  NOTE: The 'nic' argument used in many functions in this file is a pointer
+ *  to the nic_data for each NIC, so that if multiple NICs are emulated
+ *  concurrently, they will not get packets that are meant for some other
+ *  controller.
  */
 
 #include <stdio.h>
@@ -62,7 +62,7 @@
  *
  *  This routine allocates an ethernet_packet_link struct, and adds it at
  *  the end of the packet chain.  A data buffer is allocated, and the data,
- *  extra, and len fields of the link are set.
+ *  nic, and len fields of the link are set.
  *
  *  Note: The data buffer is not zeroed.
  *
@@ -70,7 +70,7 @@
  *  failure.
  */
 struct ethernet_packet_link *net_allocate_ethernet_packet_link(
-	struct net *net, void *extra, size_t len)
+	struct net *net, struct nic_data *nic, size_t len)
 {
 	struct ethernet_packet_link *lp;
 
@@ -78,7 +78,7 @@ struct ethernet_packet_link *net_allocat
 	    malloc(sizeof(struct ethernet_packet_link)));
 
 	lp->len = len;
-	lp->extra = extra;
+	lp->nic = nic;
 	CHECK_ALLOCATION(lp->data = (unsigned char *) malloc(len));
 
 	lp->next = NULL;
@@ -116,7 +116,7 @@ struct ethernet_packet_link *net_allocat
  *  An ARP request with the same from and to IP addresses should be ignored.
  *  (This would be a host testing to see if there is an IP collision.)
  */
-static void net_arp(struct net *net, void *extra,
+static void net_arp(struct net *net, struct nic_data *nic,
 	unsigned char *packet, int len, int reverse)
 {
 	int q;
@@ -161,7 +161,7 @@ static void net_arp(struct net *net, voi
 				break;
 
 			lp = net_allocate_ethernet_packet_link(
-			    net, extra, 60 + 14);
+			    net, nic, 60 + 14);
 
 			/*  Copy the old packet first:  */
 			memset(lp->data, 0, 60 + 14);
@@ -186,7 +186,7 @@ static void net_arp(struct net *net, voi
 			break;
 		case 3:		/*  Reverse Request  */
 			lp = net_allocate_ethernet_packet_link(
-			    net, extra, 60 + 14);
+			    net, nic, 60 + 14);
 
 			/*  Copy the old packet first:  */
 			memset(lp->data, 0, 60 + 14);
@@ -242,7 +242,7 @@ static void net_arp(struct net *net, voi
 /*
  *  net_ethernet_rx_avail():
  *
- *  Return 1 if there is a packet available for this 'extra' pointer, otherwise
+ *  Return 1 if there is a packet available for this nic, otherwise
  *  return 0.
  *
  *  Appart from actually checking for incoming packets from the outside world,
@@ -250,12 +250,21 @@ static void net_arp(struct net *net, voi
  *  a return value telling us whether there is a packet or not, we don't
  *  actually get the packet.
  */
-int net_ethernet_rx_avail(struct net *net, void *extra)
+int net_ethernet_rx_avail(struct net *net, struct nic_data *nic)
 {
 	if (net == NULL)
 		return 0;
 
 	/*
+	 *  If we're using a tap device, check in with that and
+	 *  that's it.
+	 */
+	if (net->tapdev) {
+		net_tap_rx_avail(net);
+		return net_ethernet_rx(net, nic, NULL, NULL);
+	}
+
+	/*
 	 *  If the network is distributed across multiple emulator processes,
 	 *  then receive incoming packets from those processes.
 	 */
@@ -282,7 +291,7 @@ int net_ethernet_rx_avail(struct net *ne
 				for (i=0; i<net->n_nics; i++) {
 					struct ethernet_packet_link *lp;
 					lp = net_allocate_ethernet_packet_link(
-					    net, net->nic_extra[i], res);
+					    net, net->nic_data[i], res);
 					memcpy(lp->data, buf, res);
 				}
 			}
@@ -290,10 +299,10 @@ int net_ethernet_rx_avail(struct net *ne
 	}
 
 	/*  IP protocol specific:  */
-	net_udp_rx_avail(net, extra);
-	net_tcp_rx_avail(net, extra);
+	net_udp_rx_avail(net, nic);
+	net_tcp_rx_avail(net, nic);
 
-	return net_ethernet_rx(net, extra, NULL, NULL);
+	return net_ethernet_rx(net, nic, NULL, NULL);
 }
 
 
@@ -309,11 +318,11 @@ int net_ethernet_rx_avail(struct net *ne
  *  available, 0 is returned.
  *
  *  If packetp is NULL, then the search is aborted as soon as a packet with
- *  the correct 'extra' field is found, and a 1 is returned, but as packetp
+ *  the correct 'nic' field is found, and a 1 is returned, but as packetp
  *  is NULL we can't return the actual packet. (This is the internal form
  *  if net_ethernet_rx_avail().)
  */
-int net_ethernet_rx(struct net *net, void *extra,
+int net_ethernet_rx(struct net *net, struct nic_data *nic,
 	unsigned char **packetp, int *lenp)
 {
 	struct ethernet_packet_link *lp, *prev;
@@ -321,12 +330,12 @@ int net_ethernet_rx(struct net *net, voi
 	if (net == NULL)
 		return 0;
 
-	/*  Find the first packet which has the right 'extra' field.  */
+	/*  Find the first packet which has the right 'nic' field.  */
 
 	lp = net->first_ethernet_packet;
 	prev = NULL;
 	while (lp != NULL) {
-		if (lp->extra == extra) {
+		if (lp->nic == nic) {
 			/*  We found a packet for this controller!  */
 			if (packetp == NULL || lenp == NULL)
 				return 1;
@@ -368,7 +377,7 @@ int net_ethernet_rx(struct net *net, voi
  *  If the packet can be handled here, it will not necessarily be transmitted
  *  to the outside world.
  */
-void net_ethernet_tx(struct net *net, void *extra,
+void net_ethernet_tx(struct net *net, struct nic_data *nic,
 	unsigned char *packet, int len)
 {
 	int i, eth_type, for_the_gateway;
@@ -376,8 +385,6 @@ void net_ethernet_tx(struct net *net, vo
 	if (net == NULL)
 		return;
 
-	for_the_gateway = !memcmp(packet, net->gateway_ethernet_addr, 6);
-
 	/*  Drop too small packets:  */
 	if (len < 20) {
 		fatal("[ net_ethernet_tx: Warning: dropping tiny packet "
@@ -386,15 +393,26 @@ void net_ethernet_tx(struct net *net, vo
 	}
 
 	/*
+	 * If we're using a tap device, we send the packet that way
+	 * and that's it.
+	 */
+	if (net->tapdev) {
+		net_tap_tx(net, nic, packet, len);
+		return;
+	}
+
+	for_the_gateway = !memcmp(packet, net->gateway_ethernet_addr, 6);
+
+	/*
 	 *  Copy this packet to all other NICs on this network (except if
 	 *  it is aimed specifically at the gateway's ethernet address):
 	 */
-	if (!for_the_gateway && extra != NULL && net->n_nics > 0) {
+	if (!for_the_gateway && nic != NULL && net->n_nics > 0) {
 		for (i=0; i<net->n_nics; i++)
-			if (extra != net->nic_extra[i]) {
+			if (nic != net->nic_data[i]) {
 				struct ethernet_packet_link *lp;
 				lp = net_allocate_ethernet_packet_link(net,
-				    net->nic_extra[i], len);
+				    net->nic_data[i], len);
 
 				/*  Copy the entire packet:  */
 				memcpy(lp->data, packet, len);
@@ -438,7 +456,7 @@ void net_ethernet_tx(struct net *net, vo
 	if (eth_type == ETHERTYPE_IP) {
 		/*  Routed via the gateway?  */
 		if (for_the_gateway) {
-			net_ip(net, extra, packet, len);
+			net_ip(net, nic, packet, len);
 			return;
 		}
 
@@ -446,7 +464,7 @@ void net_ethernet_tx(struct net *net, vo
 		if (packet[0] == 0xff && packet[1] == 0xff &&
 		    packet[2] == 0xff && packet[3] == 0xff &&
 		    packet[4] == 0xff && packet[5] == 0xff) {
-			net_ip_broadcast(net, extra, packet, len);
+			net_ip_broadcast(net, nic, packet, len);
 			return;
 		}
 
@@ -465,13 +483,13 @@ void net_ethernet_tx(struct net *net, vo
 		if (len != 42 && len != 60)
 			fatal("[ net_ethernet_tx: WARNING! unusual "
 			    "ARP len (%i) ]\n", len);
-		net_arp(net, extra, packet + 14, len - 14, 0);
+		net_arp(net, nic, packet + 14, len - 14, 0);
 		return;
 	}
 
 	/*  RARP:  */
 	if (eth_type == ETHERTYPE_REVARP) {
-		net_arp(net, extra, packet + 14, len - 14, 1);
+		net_arp(net, nic, packet + 14, len - 14, 1);
 		return;
 	}
 
@@ -595,21 +613,28 @@ static void parse_resolvconf(struct net 
  *  Add a NIC to a network. (All NICs on a network will see each other's
  *  packets.)
  */
-void net_add_nic(struct net *net, void *extra, unsigned char *macaddr)
+void net_add_nic(struct net *net, struct nic_data *nic)
 {
 	if (net == NULL)
 		return;
 
-	if (extra == NULL) {
-		fprintf(stderr, "net_add_nic(): extra = NULL\n");
+	if (nic == NULL) {
+		fprintf(stderr, "net_add_nic(): nic = NULL\n");
 		exit(1);
 	}
 
-	net->n_nics ++;
-	CHECK_ALLOCATION(net->nic_extra = (void **)
-	    realloc(net->nic_extra, sizeof(void *) * net->n_nics));
+	/*
+	 *  Set up some of the basics for this NIC.  We assume the
+	 *  device has set up all of the other fields.
+	 */
+	nic->net = net;
+	nic->promiscuous_mode = 0;
+
+	net->n_nics++;
+	CHECK_ALLOCATION(net->nic_data = (struct nic_data **)
+	    realloc(net->nic_data, sizeof(struct nic_data *) * net->n_nics));
 
-	net->nic_extra[net->n_nics - 1] = extra;
+	net->nic_data[net->n_nics - 1] = nic;
 }
 
 
@@ -661,6 +686,12 @@ void net_dumpinfo(struct net *net)
 
 	debug_indentation(iadd);
 
+	if (net->tapdev) {
+		debug("tap device: %s\n", net->tapdev);
+		debug_indentation(-iadd);
+		return;
+	}
+
 	debug("simulated network: ");
 	net_debugaddr(&net->netmask_ipv4, NET_ADDR_IPV4);
 	debug("/%i", net->netmask_ipv4_len);
@@ -718,6 +749,7 @@ void net_dumpinfo(struct net *net)
  *  On failure, exit() is called.
  */
 struct net *net_init(struct emul *emul, int init_flags,
+	const char *tapdev,
 	const char *ipv4addr, int netipv4len,
 	char **remote, int n_remote, int local_port,
 	const char *settings_prefix)
@@ -734,6 +766,19 @@ struct net *net_init(struct emul *emul, 
 	/*  Sane defaults:  */
 	net->timestamp = 0;
 	net->first_ethernet_packet = net->last_ethernet_packet = NULL;
+	net->tapdev = NULL;
+	net->tap_fd = -1;
+
+	/*
+	 *  If we're using a tap device, attempt to initialize it and
+	 *  none of the other stuff.
+	 */
+	if (tapdev) {
+		if (! net_tap_init(net, tapdev))
+			exit(1);
+		net_dumpinfo(net);
+		return net;
+	}
 
 #ifdef HAVE_INET_PTON
 	res = inet_pton(AF_INET, ipv4addr, &net->netmask_ipv4);
