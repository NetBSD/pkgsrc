$NetBSD: patch-src_include_net.h,v 1.1 2020/10/07 00:43:05 thorpej Exp $

Add support for tap(4)-based networking.

--- src/include/net.h.orig	2020-10-05 22:59:17.124851904 +0000
+++ src/include/net.h	2020-10-05 22:59:31.468423021 +0000
@@ -112,6 +112,15 @@ struct tcp_connection {
 
 /*****************************************************************************/
 
+/* Common data for emulated Ethernet NICs. */
+
+struct nic_data {
+	struct net	*net;		/* net we belong to */
+	uint8_t		mac_address[6];	/* our MAC address */
+	int		promiscuous_mode;/* receive all packets */
+};
+
+/*****************************************************************************/
 
 #define	MAX_TCP_CONNECTIONS	100
 #define	MAX_UDP_CONNECTIONS	100
@@ -120,13 +129,17 @@ struct net {
 	/*  The emul struct which this net belong to:  */
 	struct emul	*emul;
 
+	/*  The network's tap device, if we're using tap:  */
+	const char	*tapdev;
+	int		tap_fd;
+
 	/*  The network's addresses:  */
 	struct in_addr	netmask_ipv4;
 	int		netmask_ipv4_len;
 
 	/*  NICs connected to this network:  */
 	int		n_nics;
-	void		**nic_extra;	/*  one void * per NIC  */
+	struct nic_data	**nic_data;	/* one per NIC */
 
 	/*  The "special machine":  */
 	unsigned char	gateway_ipv4_addr[4];
@@ -151,6 +164,18 @@ struct net {
 	struct remote_net *remote_nets;
 };
 
+/*  net_tap.c:  */
+void net_tap_rx_avail(struct net *net);
+void net_tap_tx(struct net *net, struct nic_data *nic, unsigned char *packet,
+	int len);
+int net_tap_init(struct net *net, const char *tapdev);
+
+/*  net_ether.cc  */
+int net_ether_eq(const uint8_t *a1, const uint8_t *a2);
+int net_ether_broadcast(const uint8_t *a);
+int net_ether_multicast(const uint8_t *a);
+uint32_t net_ether_crc32_le(const uint8_t *buf, size_t len);
+
 /*  net_misc.c:  */
 void net_debugaddr(void *addr, int type);
 void net_generate_unique_mac(struct machine *, unsigned char *macbuf);
@@ -162,25 +187,27 @@ void net_ip_checksum(unsigned char *ip_h
 void net_ip_tcp_checksum(unsigned char *tcp_header, int chksumoffset,
 	int tcp_len, unsigned char *srcaddr, unsigned char *dstaddr,
 	int udpflag);
-void net_ip_tcp_connectionreply(struct net *net, void *extra,
+void net_ip_tcp_connectionreply(struct net *net, struct nic_data *nic,
 	int con_id, int connecting, unsigned char *data, int datalen, int rst);
-void net_ip_broadcast(struct net *net, void *extra,
+void net_ip_broadcast(struct net *net, struct nic_data *nic,
         unsigned char *packet, int len);
-void net_ip(struct net *net, void *extra, unsigned char *packet, int len);
-void net_udp_rx_avail(struct net *net, void *extra);
-void net_tcp_rx_avail(struct net *net, void *extra);
+void net_ip(struct net *net, struct nic_data *nic, unsigned char *packet,
+	int len);
+void net_udp_rx_avail(struct net *net, struct nic_data *nic);
+void net_tcp_rx_avail(struct net *net, struct nic_data *nic);
 
 /*  net.c:  */
 struct ethernet_packet_link *net_allocate_ethernet_packet_link(
-	struct net *net, void *extra, size_t len);
-int net_ethernet_rx_avail(struct net *net, void *extra);
-int net_ethernet_rx(struct net *net, void *extra,
+	struct net *net, struct nic_data *nic, size_t len);
+int net_ethernet_rx_avail(struct net *net, struct nic_data *nic);
+int net_ethernet_rx(struct net *net, struct nic_data *nic,
 	unsigned char **packetp, int *lenp);
-void net_ethernet_tx(struct net *net, void *extra,
+void net_ethernet_tx(struct net *net, struct nic_data *nic,
 	unsigned char *packet, int len);
 void net_dumpinfo(struct net *net);
-void net_add_nic(struct net *net, void *extra, unsigned char *macaddr);
+void net_add_nic(struct net *net, struct nic_data *nic);
 struct net *net_init(struct emul *emul, int init_flags,
+	const char *tapdev,
 	const char *ipv4addr, int netipv4len, char **remote, int n_remote,
 	int local_port, const char *settings_prefix);
 
@@ -195,7 +222,7 @@ struct ethernet_packet_link {
 	struct ethernet_packet_link *prev;
 	struct ethernet_packet_link *next;
 
-	void		*extra;
+	struct nic_data	*nic;
 	unsigned char	*data;
 	int		len;
 };
