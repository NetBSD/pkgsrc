$NetBSD: patch-src_devices_dev_le.cc,v 1.1 2020/10/07 00:43:05 thorpej Exp $

- Add support for tap(4)-based networking.
- Process the setup packet, and implement address filtering.

--- src/devices/dev_le.cc.orig	2020-10-05 22:56:40.808218933 +0000
+++ src/devices/dev_le.cc	2020-10-05 22:56:55.751440817 +0000
@@ -72,9 +72,10 @@
 
 extern int quiet_mode;
 
-#define	LE_MODE_LOOP		4
-#define	LE_MODE_DTX		2
-#define	LE_MODE_DRX		1
+#define	LE_MODE_PROM		0x8000
+#define	LE_MODE_LOOP		0x0004
+#define	LE_MODE_DTX		0x0002
+#define	LE_MODE_DRX		0x0001
 
 
 #define	N_REGISTERS		4
@@ -83,6 +84,8 @@ extern int quiet_mode;
 
 
 struct le_data {
+	struct nic_data	nic;
+
 	struct interrupt irq;
 	int		irq_asserted;
 
@@ -101,13 +104,14 @@ struct le_data {
 	uint32_t	init_block_addr;
 
 	uint16_t	mode;
-	uint64_t	padr;	/*  MAC address  */
-	uint64_t	ladrf;
+	uint16_t	ladrf[4];
 	uint32_t	rdra;	/*  receive descriptor ring address  */
 	int		rlen;	/*  nr of rx descriptors  */
 	uint32_t	tdra;	/*  transmit descriptor ring address  */
 	int		tlen;	/*  nr ot tx descriptors  */
 
+	int		allmulti;/* receive all multicast packets */
+
 	/*  Current rx and tx descriptor indices:  */
 	int		rxp;
 	int		txp;
@@ -157,6 +161,9 @@ static void le_write_16bit(struct le_dat
  */
 static void le_chip_init(struct le_data *d)
 {
+	uint16_t tmp;
+	uint8_t macaddr[6];
+
 	d->init_block_addr = (d->reg[1] & 0xffff) + ((d->reg[2] & 0xff) << 16);
 	if (d->init_block_addr & 1)
 		fatal("[ le: WARNING! initialization block address "
@@ -165,13 +172,36 @@ static void le_chip_init(struct le_data 
 	debug("[ le: d->init_block_addr = 0x%06x ]\n", d->init_block_addr);
 
 	d->mode = le_read_16bit(d, d->init_block_addr + 0);
-	d->padr = le_read_16bit(d, d->init_block_addr + 2);
-	d->padr += (le_read_16bit(d, d->init_block_addr + 4) << 16);
-	d->padr += (le_read_16bit(d, d->init_block_addr + 6) << 32);
-	d->ladrf = le_read_16bit(d, d->init_block_addr + 8);
-	d->ladrf += (le_read_16bit(d, d->init_block_addr + 10) << 16);
-	d->ladrf += (le_read_16bit(d, d->init_block_addr + 12) << 32);
-	d->ladrf += (le_read_16bit(d, d->init_block_addr + 14) << 48);
+
+	/*
+	 * The MAC address is packed into the PADR field as 3 little-endian
+	 * 16-bit words.
+	 */
+	tmp = le_read_16bit(d, d->init_block_addr + 2);
+	macaddr[0] = (uint8_t)(tmp);
+	macaddr[1] = (uint8_t)(tmp >> 8);
+	tmp = le_read_16bit(d, d->init_block_addr + 4);
+	macaddr[2] = (uint8_t)(tmp);
+	macaddr[3] = (uint8_t)(tmp >> 8);
+	tmp = le_read_16bit(d, d->init_block_addr + 6);
+	macaddr[4] = (uint8_t)(tmp);
+	macaddr[5] = (uint8_t)(tmp >> 8);
+	memcpy(d->nic.mac_address, macaddr, sizeof(d->nic.mac_address));
+
+	/*
+	 * The muticast address filter is packed into the LADRF field
+	 * as 4 little-endian 16-bit words.
+	 */
+	d->ladrf[0] = le_read_16bit(d, d->init_block_addr + 8);
+	d->ladrf[1] = le_read_16bit(d, d->init_block_addr + 10);
+	d->ladrf[2] = le_read_16bit(d, d->init_block_addr + 12);
+	d->ladrf[3] = le_read_16bit(d, d->init_block_addr + 14);
+	if (d->ladrf[0] == 0xffff && d->ladrf[1] == 0xffff &&
+	    d->ladrf[2] == 0xffff && d->ladrf[3] == 0xffff)
+		d->allmulti = 1;
+	else
+		d->allmulti = 0;
+
 	d->rdra = le_read_16bit(d, d->init_block_addr + 16);
 	d->rdra += ((le_read_16bit(d, d->init_block_addr + 18) & 0xff) << 16);
 	d->rlen = 1 << ((le_read_16bit(d, d->init_block_addr + 18) >> 13) & 7);
@@ -179,13 +209,16 @@ static void le_chip_init(struct le_data 
 	d->tdra += ((le_read_16bit(d, d->init_block_addr + 22) & 0xff) << 16);
 	d->tlen = 1 << ((le_read_16bit(d, d->init_block_addr + 22) >> 13) & 7);
 
-	debug("[ le: DEBUG: mode              %04x ]\n", d->mode);
-	debug("[ le: DEBUG: padr  %016llx ]\n", (long long)d->padr);
-	debug("[ le: DEBUG: ladrf %016llx ]\n", (long long)d->ladrf);
-	debug("[ le: DEBUG: rdra            %06llx ]\n", d->rdra);
-	debug("[ le: DEBUG: rlen               %3i ]\n", d->rlen);
-	debug("[ le: DEBUG: tdra            %06llx ]\n", d->tdra);
-	debug("[ le: DEBUG: tlen               %3i ]\n", d->tlen);
+	debug("[ le: DEBUG: mode                 %04x ]\n", d->mode);
+	debug("[ le: DEBUG: padr    %02x:%02x:%02x:%02x:%02x:%02x ]\n",
+	      macaddr[0], macaddr[1], macaddr[2],
+	      macaddr[3], macaddr[4], macaddr[5]);
+	debug("[ le: DEBUG: ladrf %04x:%04x:%04x:%04x ]\n",
+	      d->ladrf[0], d->ladrf[1], d->ladrf[2], d->ladrf[3]);
+	debug("[ le: DEBUG: rdra               %06llx ]\n", d->rdra);
+	debug("[ le: DEBUG: rlen                  %3i ]\n", d->rlen);
+	debug("[ le: DEBUG: tdra               %06llx ]\n", d->tdra);
+	debug("[ le: DEBUG: tlen                  %3i ]\n", d->tlen);
 
 	/*  Set TXON and RXON, unless they are disabled by 'mode':  */
 	if (d->mode & LE_MODE_DTX)
@@ -198,6 +231,9 @@ static void le_chip_init(struct le_data 
 	else
 		d->reg[0] |= LE_RXON;
 
+	/*  Initialize promiscuous mode.  */
+	d->nic.promiscuous_mode = (d->mode & LE_MODE_PROM) ? 1 : 0;
+
 	/*  Go to the start of the descriptor rings:  */
 	d->rxp = d->txp = 0;
 
@@ -308,7 +344,8 @@ static void le_tx(struct net *net, struc
 		 *  the packet.
 		 */
 		if (enp) {
-			net_ethernet_tx(net, d, d->tx_packet, d->tx_packet_len);
+			net_ethernet_tx(net, &d->nic, d->tx_packet,
+			    d->tx_packet_len);
 
 			free(d->tx_packet);
 			d->tx_packet = NULL;
@@ -446,6 +483,62 @@ static void le_rx(struct net *net, struc
 
 
 /*
+ *  le_rx_drop_packet():
+ *
+ *  Implement the logic to determine if we should drop a packet
+ *  before passing it to the guest.  Returns 1 if the packet was
+ *  dropped.
+ */
+static int
+le_rx_drop_packet(struct net *net, struct le_data *d)
+{
+	/* Only implement filtering if using a tap device. */
+	if (net->tapdev == NULL)
+		return 0;
+
+	/*
+	 * The network layer has already checked for our MAC address
+	 * or promiscuous mode.  We just need to check the multicast
+	 * filter or broadcast.
+	 */
+
+	/* If the packet is not multicast, we know it should be received. */
+	if (! net_ether_multicast(d->rx_packet))
+		return 0;
+
+	/*
+	 * Optimization -- if the guest has set all of the filter
+	 * bits, then we can skip additional checks.
+	 */
+	if (d->allmulti)
+		return 0;
+
+	/* Check for broadcast. */
+	if (net_ether_broadcast(d->rx_packet))
+		return 0;
+
+	/*
+	 * Check the multicast address filter.  We pass the address
+	 * through the little-endian Ethernet CRC generator.  The
+	 * high-order 6 bits are the index into the 64-bit filter.
+	 * The upper 2 bits select the 16-bit filter word, and the
+	 * remaining 4 select the bit in the word.
+	 */
+	uint32_t crc = net_ether_crc32_le(d->rx_packet, 6);
+	crc >>= 26;
+	if (d->ladrf[crc >> 4] & (1 << (crc & 0xf)))
+		return 0;
+
+	/* Not for us; drop the packet. */
+	free(d->rx_packet);
+	d->rx_packet = NULL;
+	d->rx_packet_len = 0;
+
+	return 1;
+}
+
+
+/*
  *  le_register_fix():
  */
 static void le_register_fix(struct net *net, struct le_data *d)
@@ -481,9 +574,12 @@ static void le_register_fix(struct net *
 				break;
 
 			if (d->rx_packet == NULL &&
-			    net_ethernet_rx_avail(net, d))
-				net_ethernet_rx(net, d,
+			    net_ethernet_rx_avail(net, &d->nic)) {
+				net_ethernet_rx(net, &d->nic,
 				    &d->rx_packet, &d->rx_packet_len);
+				if (le_rx_drop_packet(net, d))
+					continue;
+			}
 		} while (d->rx_packet != NULL);
 	}
 
@@ -813,6 +909,7 @@ void dev_le_init(struct machine *machine
 
 	machine_add_tickfunction(machine, dev_le_tick, d, LE_TICK_SHIFT);
 
-	net_add_nic(machine->emul->net, d, &d->rom[0]);
+	memcpy(d->nic.mac_address, &d->rom[0], sizeof(d->nic.mac_address));
+	net_add_nic(machine->emul->net, &d->nic);
 }
 
