$NetBSD: patch-src_devices_dev_dec21143.cc,v 1.1 2020/10/07 00:43:05 thorpej Exp $

- Add support for tap(4)-based networking.
- Process the setup packet, and implement all of the Tulip receive
  filtering modes.
- Add ugly hack to deal with PCI vs. CPU views of main memory differences
  between systems.

--- src/devices/dev_dec21143.cc.orig	2020-10-05 22:54:55.903897678 +0000
+++ src/devices/dev_dec21143.cc	2020-10-05 22:55:15.711704852 +0000
@@ -45,8 +45,6 @@
  *	o)  Handle _writes_ to MII registers.
  *	o)  Make it work with modern Linux kernels (as a guest OS).
  *	o)  Endianness for descriptors? If necessary.
- *	o)  Actually handle the "Setup" packet.
- *	o)  MAC filtering on incoming packets.
  *	o)  Don't hardcode as many values.
  */
 
@@ -76,16 +74,15 @@
 #define	ROM_WIDTH		6
 
 struct dec21143_data {
+	/*  NIC common data  */
+	struct nic_data	nic;
+
 	struct interrupt irq;
 	int		irq_was_asserted;
 
 	/*  PCI:  */
 	int		pci_little_endian;
 
-	/*  Ethernet address, and a network which we are connected to:  */
-	uint8_t		mac[6];
-	struct net	*net;
-
 	/*  SROM emulation:  */
 	uint8_t		srom[1 << (ROM_WIDTH + 1)];
 	int		srom_curbit;
@@ -105,19 +102,66 @@ struct dec21143_data {
 	uint32_t	reg[N_REGS];
 
 	/*  Internal TX state:  */
-	uint64_t	cur_tx_addr;
+	uint32_t	cur_tx_addr;
 	unsigned char	*cur_tx_buf;
 	int		cur_tx_buf_len;
 	int		tx_idling;
 	int		tx_idling_threshold;
 
 	/*  Internal RX state:  */
-	uint64_t	cur_rx_addr;
+	uint32_t	cur_rx_addr;
 	unsigned char	*cur_rx_buf;
 	int		cur_rx_buf_len;
 	int		cur_rx_offset;
+
+	/*
+	 *  Receive filter information.  We keep our own copy of
+	 *  the promiscuous flag because to implement some of the
+	 *  filtering modes, we need to tell the network layer that
+	 *  we want all packets.
+	 */
+	int		(*drop_packet)(struct net *, struct dec21143_data *);
+	int		allmulti;
+	int		promiscuous;
+	int		filter_needs_promiscuous;
+	uint8_t		perfect_filter[6 * TULIP_MAXADDRS];
+
+	/*  Only 16 bits are used per filter word.  */
+#define	MCHASH_NWORDS	(TULIP_MCHASHSIZE / 16)
+	uint32_t	hash_filter[MCHASH_NWORDS];
+	int		hash_filter_saturated;
+
+	/*
+	 *  XXX XXX XXX
+	 *  XXX UGLY HACK.  Need a proper way to deal with
+	 *  XXX different PCI vs. CPU views of RAM.
+	 *  XXX XXX XXX
+	 */
+	uint32_t	xxx_dma_to_phys_mask;
 };
 
+/*  XXX This is an UGLY hack.  */
+static uint64_t dma_to_phys(const struct dec21143_data *d, uint32_t dma_addr)
+{
+	return dma_addr & d->xxx_dma_to_phys_mask;
+}
+
+
+static inline uint32_t load_le32(const uint8_t *buf)
+{
+	return buf[0] | ((uint32_t)buf[1] << 8) |
+	    ((uint32_t)buf[2] << 16) | ((uint32_t)buf[3] << 24);
+}
+
+
+static inline void store_le32(uint8_t *buf, uint32_t val)
+{
+	buf[0] = (uint8_t)val;
+	buf[1] = (uint8_t)(val >> 8);
+	buf[2] = (uint8_t)(val >> 16);
+	buf[3] = (uint8_t)(val >> 24);
+}
+
 
 /*  Internal states during MII data stream decode:  */
 #define	MII_STATE_RESET				0
@@ -130,6 +174,171 @@ struct dec21143_data {
 
 
 /*
+ * The 21143 has multiple address matching modes:
+ *
+ *	- Perfect Filtering: The chip interprets the descriptor buffer
+ *	  as a table of 16 MAC addresses that it should match.  The
+ *	  station address and broadcast must be included in the list.
+ *
+ *	- Hash Perfect Filtering: The chip interprets the descriptor buffer
+ *	  as a 512-bit hash table plus one perfect filter match.  Multicast
+ *	  addresses only are matched against the hash table.
+ *
+ *	- Inverse Filtering: Like Perfect Filtering, but the table is
+ *	  addresses NOT to match.
+ *
+ *	- Hash-only Filtering: Like Hash Perfect, except without the Perfect.
+ *	  All addresses are matched against the hash table.
+ *
+ * The mode seleted by the TDCTL descriptor field is reflected in 3
+ * read-only bits in the OPMODE register.
+ *
+ * We implement all 4 (NetBSD, at least, is known to use Perfect and
+ * Hash Perfect on the 21143; it also uses Hash-only on the 21140).
+ */
+
+#define	TDCTL_Tx_FT_MASK	(TDCTL_Tx_FT1|TDCTL_Tx_FT0)
+
+#define	dec21143_mchash(addr)	\
+	(net_ether_crc32_le((addr), 6) & (TULIP_MCHASHSIZE - 1))
+
+static int dec21143_drop_packet_perfect(struct net *net,
+	struct dec21143_data *d)
+{
+	int i;
+
+	for (i = 0; i < TULIP_MAXADDRS; i++) {
+		if (net_ether_eq(d->cur_rx_buf, &d->perfect_filter[6 * i])) {
+			/* Match! */
+			return 0;
+		}
+	}
+
+	return 1;
+}
+
+static int dec21143_drop_packet_hashperfect(struct net *net,
+	struct dec21143_data *d)
+{
+
+	/*
+	 * In this mode, we have the network layer match our station
+	 * address, and we reflect the true promiscuous status there
+	 * as well.  This means that if it's not a multicast address,
+	 * then it's already been sufficiently matched.
+	 */
+	if (! net_ether_multicast(d->cur_rx_buf))
+		return 0;
+
+	/*
+	 * Note that the broadcast address is also checked against
+	 * the hash table in this mode!
+	 */
+
+	const uint32_t hash = dec21143_mchash(d->cur_rx_buf);
+	if (d->hash_filter[hash >> 4] & (1U << (hash & 0xf))) {
+		/* Match! */
+		return 0;
+	}
+
+	return 1;
+}
+
+static int dec21143_drop_packet_inverse(struct net *net,
+	struct dec21143_data *d)
+{
+	return !dec21143_drop_packet_perfect(net, d);
+}
+
+static int dec21143_drop_packet_hashonly(struct net *net,
+	struct dec21143_data *d)
+{
+	const uint32_t hash = dec21143_mchash(d->cur_rx_buf);
+	if (d->hash_filter[hash >> 4] & (1U << (hash & 0xf))) {
+		/* Match! */
+		return 0;
+	}
+
+	return 1;
+}
+
+
+/*
+ *  dec21143_rx_drop_packet():
+ *
+ *  Implement the logic to determine if we should drop a packet
+ *  before paassing it to the guest.  Returns 1 if the packet
+ *  was dropped.
+ */
+static int dec21143_rx_drop_packet(struct net *net, struct dec21143_data *d)
+{
+	/* Only implement filtering if using a tap device. */
+	if (net->tapdev == NULL)
+		return 0;
+
+	/*
+	 * We might have told the network layer that we're promiscuous
+	 * due to the chosen filtering mode, so check the truth here.
+	 */
+	if (d->promiscuous)
+		return 0;
+
+	/*
+	 * If the guest wants all multicast (either all the bits are
+	 * set or the OPMODE_PM bit is set), then check to see if we
+	 * can short-circuit the checks.
+	 */
+	if (d->allmulti && net_ether_multicast(d->cur_rx_buf))
+		return 0;
+
+	/*
+	 * Note that if we haven't gotten a setup packet yet, then
+	 * d->drop_packet will be NULL.  If this happens, we always
+	 * drop.  This is akin to the real hardware defaulting to
+	 * Perfect filtering mode but not having any valid addresses
+	 * in the list to match against.
+	 */
+	if (d->drop_packet == NULL || d->drop_packet(net, d)) {
+		/* Not for us; drop the packet. */
+		free(d->cur_rx_buf);
+		d->cur_rx_buf = NULL;
+		d->cur_rx_buf_len = 0;
+		return 1;
+	}
+
+	return 0;
+}
+
+
+/*
+ *  dec21143_update_rx_mode():
+ *
+ *  Update promiscuous / allmulti indicators based on OPMODE
+ *  and filter state.
+ */
+static void dec21143_update_rx_mode(struct dec21143_data *d)
+{
+	int opmode_pr = (d->reg[CSR_OPMODE / 8] & OPMODE_PR) != 0;
+	int opmode_pm = (d->reg[CSR_OPMODE / 8] & OPMODE_PM) != 0;
+
+	debug("[ dec21143 rx mode: opmode_pr = %d                ]\n",
+	      opmode_pr);
+	debug("[ dec21143 rx mode: filter_needs_promiscuous = %d ]\n",
+	      d->filter_needs_promiscuous);
+	debug("[ dec21143 rx mode: opmode_pm = %d                ]\n",
+	      opmode_pm);
+	debug("[ dec21143 rx mode: filter_saturated = %d         ]\n",
+	      d->hash_filter_saturated);
+
+	d->promiscuous = opmode_pr;
+	d->nic.promiscuous_mode =
+	    d->promiscuous || d->filter_needs_promiscuous;
+
+	d->allmulti = opmode_pm || d->hash_filter_saturated;
+}
+
+
+/*
  *  dec21143_rx():
  *
  *  Receive a packet. (If there is no current packet, then check for newly
@@ -138,20 +347,23 @@ struct dec21143_data {
  */
 int dec21143_rx(struct cpu *cpu, struct dec21143_data *d)
 {
-	uint64_t addr = d->cur_rx_addr, bufaddr;
+	uint32_t addr = d->cur_rx_addr, bufaddr;
 	unsigned char descr[16];
 	uint32_t rdes0, rdes1, rdes2, rdes3;
 	int bufsize, buf1_size, buf2_size, i, writeback_len = 4, to_xfer;
 
 	/*  No current packet? Then check for new ones.  */
-	if (d->cur_rx_buf == NULL) {
+	while (d->cur_rx_buf == NULL) {
 		/*  Nothing available? Then abort.  */
-		if (!net_ethernet_rx_avail(d->net, d))
+		if (!net_ethernet_rx_avail(d->nic.net, &d->nic))
 			return 0;
 
 		/*  Get the next packet into our buffer:  */
-		net_ethernet_rx(d->net, d, &d->cur_rx_buf,
-		    &d->cur_rx_buf_len);
+		net_ethernet_rx(d->nic.net, &d->nic,
+		    &d->cur_rx_buf, &d->cur_rx_buf_len);
+
+		if (dec21143_rx_drop_packet(d->nic.net, d))
+			continue;
 
 		/*  Append a 4 byte CRC:  */
 		d->cur_rx_buf_len += 4;
@@ -165,15 +377,14 @@ int dec21143_rx(struct cpu *cpu, struct 
 	}
 
 	/*  fatal("{ dec21143_rx: base = 0x%08x }\n", (int)addr);  */
-	addr &= 0x7fffffff;
 
-	if (!cpu->memory_rw(cpu, cpu->mem, addr, descr, sizeof(uint32_t),
-	    MEM_READ, PHYSICAL | NO_EXCEPTIONS)) {
+	if (!cpu->memory_rw(cpu, cpu->mem, dma_to_phys(d, addr),
+	    descr, sizeof(uint32_t), MEM_READ, PHYSICAL | NO_EXCEPTIONS)) {
 		fatal("[ dec21143_rx: memory_rw failed! ]\n");
 		return 0;
 	}
 
-	rdes0 = descr[0] + (descr[1]<<8) + (descr[2]<<16) + (descr[3]<<24);
+	rdes0 = load_le32(&descr[0]);
 
 	/*  Only use descriptors owned by the 21143:  */
 	if (!(rdes0 & TDSTAT_OWN)) {
@@ -181,16 +392,17 @@ int dec21143_rx(struct cpu *cpu, struct 
 		return 0;
 	}
 
-	if (!cpu->memory_rw(cpu, cpu->mem, addr + sizeof(uint32_t), descr +
-	    sizeof(uint32_t), sizeof(uint32_t) * 3, MEM_READ, PHYSICAL |
-	    NO_EXCEPTIONS)) {
+	if (!cpu->memory_rw(cpu, cpu->mem,
+	    dma_to_phys(d, addr + sizeof(uint32_t)),
+	    descr + sizeof(uint32_t), sizeof(uint32_t) * 3, MEM_READ,
+	    PHYSICAL | NO_EXCEPTIONS)) {
 		fatal("[ dec21143_rx: memory_rw failed! ]\n");
 		return 0;
 	}
 
-	rdes1 = descr[4] + (descr[5]<<8) + (descr[6]<<16) + (descr[7]<<24);
-	rdes2 = descr[8] + (descr[9]<<8) + (descr[10]<<16) + (descr[11]<<24);
-	rdes3 = descr[12] + (descr[13]<<8) + (descr[14]<<16) + (descr[15]<<24);
+	rdes1 = load_le32(&descr[4]);
+	rdes2 = load_le32(&descr[8]);
+	rdes3 = load_le32(&descr[12]);
 
 	buf1_size = rdes1 & TDCTL_SIZE1;
 	buf2_size = (rdes1 & TDCTL_SIZE2) >> TDCTL_SIZE2_SHIFT;
@@ -210,7 +422,6 @@ int dec21143_rx(struct cpu *cpu, struct 
 
 	debug("{ RX (%llx): 0x%08x 0x%08x 0x%x 0x%x: buf %i bytes at 0x%x }\n",
 	    (long long)addr, rdes0, rdes1, rdes2, rdes3, bufsize, (int)bufaddr);
-	bufaddr &= 0x7fffffff;
 
 	/*  Turn off all status bits, and give up ownership:  */
 	rdes0 = 0x00000000;
@@ -221,7 +432,7 @@ int dec21143_rx(struct cpu *cpu, struct 
 
 	/*  DMA bytes from the packet into emulated physical memory:  */
 	for (i=0; i<to_xfer; i++) {
-		cpu->memory_rw(cpu, cpu->mem, bufaddr + i,
+		cpu->memory_rw(cpu, cpu->mem, dma_to_phys(d, bufaddr + i),
 		    d->cur_rx_buf + d->cur_rx_offset + i, 1, MEM_WRITE,
 		    PHYSICAL | NO_EXCEPTIONS);
 		/*  fatal(" %02x", d->cur_rx_buf[d->cur_rx_offset + i]);  */
@@ -253,19 +464,16 @@ int dec21143_rx(struct cpu *cpu, struct 
 	}
 
 	/*  Descriptor writeback:  */
-	descr[ 0] = rdes0;       descr[ 1] = rdes0 >> 8;
-	descr[ 2] = rdes0 >> 16; descr[ 3] = rdes0 >> 24;
+	store_le32(&descr[0], rdes0);
 	if (writeback_len > 1) {
-		descr[ 4] = rdes1;       descr[ 5] = rdes1 >> 8;
-		descr[ 6] = rdes1 >> 16; descr[ 7] = rdes1 >> 24;
-		descr[ 8] = rdes2;       descr[ 9] = rdes2 >> 8;
-		descr[10] = rdes2 >> 16; descr[11] = rdes2 >> 24;
-		descr[12] = rdes3;       descr[13] = rdes3 >> 8;
-		descr[14] = rdes3 >> 16; descr[15] = rdes3 >> 24;
+		store_le32(&descr[4], rdes1);
+		store_le32(&descr[8], rdes2);
+		store_le32(&descr[12], rdes3);
 	}
 
-	if (!cpu->memory_rw(cpu, cpu->mem, addr, descr, sizeof(uint32_t)
-	    * writeback_len, MEM_WRITE, PHYSICAL | NO_EXCEPTIONS)) {
+	if (!cpu->memory_rw(cpu, cpu->mem, dma_to_phys(d, addr), descr,
+	    sizeof(uint32_t) * writeback_len, MEM_WRITE,
+	    PHYSICAL | NO_EXCEPTIONS)) {
 		fatal("[ dec21143_rx: memory_rw failed! ]\n");
 		return 0;
 	}
@@ -275,6 +483,178 @@ int dec21143_rx(struct cpu *cpu, struct 
 
 
 /*
+ *  dec21143_setup_copy_enaddr():
+ *
+ *  Copy an Ethernet address out of the setup packet.
+ */
+static void dec21143_setup_copy_enaddr(uint8_t *enaddr,
+	const uint32_t *setup_packet)
+{
+	int i;
+
+	for (i = 0; i < 3; i++) {
+		enaddr[i*2    ] = (uint8_t)setup_packet[i];
+		enaddr[i*2 + 1] = (uint8_t)(setup_packet[i] >> 8);
+	}
+}
+
+
+/*
+ *  dec21143_setup_perfect():
+ *
+ *  Setup perfect filtering mode.
+ */
+static void dec21143_setup_perfect(struct dec21143_data *d,
+	const uint32_t *setup_packet)
+{
+	int i;
+
+	for (i = 0; i < TULIP_MAXADDRS; i++) {
+		dec21143_setup_copy_enaddr(&d->perfect_filter[i * 6],
+		    &setup_packet[i * 3]);
+		debug("dec21143 PERFECT[%d] %02x:%02x:%02x:%02x:%02x:%02x\n",
+		    i,
+		    d->perfect_filter[i*6 + 0],
+		    d->perfect_filter[i*6 + 1],
+		    d->perfect_filter[i*6 + 2],
+		    d->perfect_filter[i*6 + 3],
+		    d->perfect_filter[i*6 + 4],
+		    d->perfect_filter[i*6 + 5]);
+	}
+
+	d->drop_packet = dec21143_drop_packet_perfect;
+}
+
+
+/*
+ *  dec21143_setup_hashperfect():
+ *
+ *  Setup hash-perfect filtering mode.
+ */
+static void dec21143_setup_hashperfect(struct dec21143_data *d,
+	const uint32_t *setup_packet)
+{
+	int i;
+
+	debug("dec21143 HASHPERFECT:");
+	for (i = 0; i < MCHASH_NWORDS; i++) {
+		if ((i % 8) == 0)
+			debug("\n\t");
+		debug(" %04x", setup_packet[i]);
+		d->hash_filter[i] = setup_packet[i];
+		d->hash_filter_saturated |= (d->hash_filter[i] == 0xffff);
+	}
+	debug("\n");
+
+	dec21143_setup_copy_enaddr(d->nic.mac_address, &setup_packet[39]);
+	debug("dec21143 HASHPERFECT %02x:%02x:%02x:%02x:%02x:%02x\n",
+	      d->nic.mac_address[0],
+	      d->nic.mac_address[1],
+	      d->nic.mac_address[2],
+	      d->nic.mac_address[3],
+	      d->nic.mac_address[4],
+	      d->nic.mac_address[5]);
+
+	d->filter_needs_promiscuous = 0;
+	d->drop_packet = dec21143_drop_packet_hashperfect;
+}
+
+
+/*
+ *  dec21143_setup_inverse():
+ *
+ *  Setup inverse filtering mode.
+ */
+static void dec21143_setup_inverse(struct dec21143_data *d,
+	const uint32_t *setup_packet)
+{
+	dec21143_setup_perfect(d, setup_packet);
+	debug("dec21143 INVERSE ^^^^\n");
+	d->drop_packet = dec21143_drop_packet_inverse;
+}
+
+
+/*
+ *  dec21143_setup_hashonly():
+ *
+ *  Setup hash-only filtering mode.
+ */
+static void dec21143_setup_hashonly(struct dec21143_data *d,
+	const uint32_t *setup_packet)
+{
+	int i;
+
+	debug("dec21143 HASHONLY:");
+	for (i = 0; i < MCHASH_NWORDS; i++) {
+		if ((i % 8) == 0)
+			fatal("\n\t");
+		debug(" %04x", setup_packet[i]);
+		d->hash_filter[i] = setup_packet[i];
+		d->hash_filter_saturated |= (d->hash_filter[i] == 0xffff);
+	}
+	debug("\n");
+
+	d->drop_packet = dec21143_drop_packet_hashonly;
+}
+
+
+/*
+ *  dec21143_process_setup_packet():
+ *
+ *  Process the address filter setup packet.
+ */
+static void dec21143_process_setup_packet(struct cpu *cpu,
+	struct dec21143_data *d, uint32_t tdctl, uint32_t bufaddr)
+{
+	uint32_t setup_packet[TULIP_SETUP_PACKET_LEN / sizeof(uint32_t)];
+	uint8_t *cp = (uint8_t *)setup_packet;
+	uint32_t tmp;
+	int i;
+
+	if (!cpu->memory_rw(cpu, cpu->mem, dma_to_phys(d, bufaddr), cp,
+	    TULIP_SETUP_PACKET_LEN, MEM_READ, PHYSICAL | NO_EXCEPTIONS)) {
+		fatal("[ dec21143_process_setup_packet: memory_rw failed! ]\n");
+		return;
+	}
+
+	/* Ensure host order of each word. */
+	for (i = 0; i < TULIP_SETUP_PACKET_LEN; i += sizeof(uint32_t)) {
+		tmp = load_le32(&cp[i]);
+		setup_packet[i / sizeof(uint32_t)] = tmp;
+	}
+
+	/* Defaults. */
+	d->hash_filter_saturated = 0;
+	d->filter_needs_promiscuous = 1;
+
+	d->reg[CSR_OPMODE / 8] &= ~(OPMODE_HP | OPMODE_HO | OPMODE_IF);
+
+	switch (tdctl & TDCTL_Tx_FT_MASK) {
+	case TDCTL_Tx_FT_PERFECT:
+		dec21143_setup_perfect(d, setup_packet);
+		break;
+
+	case TDCTL_Tx_FT_HASH:
+		dec21143_setup_hashperfect(d, setup_packet);
+		d->reg[CSR_OPMODE / 8] |= OPMODE_HP;
+		break;
+
+	case TDCTL_Tx_FT_INVERSE:
+		dec21143_setup_inverse(d, setup_packet);
+		d->reg[CSR_OPMODE / 8] |= OPMODE_IF;
+		break;
+
+	case TDCTL_Tx_FT_HASHONLY:
+		dec21143_setup_hashonly(d, setup_packet);
+		d->reg[CSR_OPMODE / 8] |= OPMODE_HO;
+		break;
+	}
+
+	dec21143_update_rx_mode(d);
+}
+
+
+/*
  *  dec21143_tx():
  *
  *  Transmit a packet, if the guest OS has marked a descriptor as containing
@@ -282,20 +662,18 @@ int dec21143_rx(struct cpu *cpu, struct 
  */
 int dec21143_tx(struct cpu *cpu, struct dec21143_data *d)
 {
-	uint64_t addr = d->cur_tx_addr, bufaddr;
+	uint32_t addr = d->cur_tx_addr, bufaddr;
 	unsigned char descr[16];
 	uint32_t tdes0, tdes1, tdes2, tdes3;
 	int bufsize, buf1_size, buf2_size, i;
 
-	addr &= 0x7fffffff;
-
-	if (!cpu->memory_rw(cpu, cpu->mem, addr, descr, sizeof(uint32_t),
-	    MEM_READ, PHYSICAL | NO_EXCEPTIONS)) {
+	if (!cpu->memory_rw(cpu, cpu->mem, dma_to_phys(d, addr), descr,
+	    sizeof(uint32_t), MEM_READ, PHYSICAL | NO_EXCEPTIONS)) {
 		fatal("[ dec21143_tx: memory_rw failed! ]\n");
 		return 0;
 	}
 
-	tdes0 = descr[0] + (descr[1]<<8) + (descr[2]<<16) + (descr[3]<<24);
+	tdes0 = load_le32(&descr[0]);
 
 	/*  fatal("{ dec21143_tx: base=0x%08x, tdes0=0x%08x }\n",
 	    (int)addr, (int)tdes0);  */
@@ -310,16 +688,17 @@ int dec21143_tx(struct cpu *cpu, struct 
 		return 0;
 	}
 
-	if (!cpu->memory_rw(cpu, cpu->mem, addr + sizeof(uint32_t), descr +
-	    sizeof(uint32_t), sizeof(uint32_t) * 3, MEM_READ, PHYSICAL |
-	    NO_EXCEPTIONS)) {
+	if (!cpu->memory_rw(cpu, cpu->mem,
+	    dma_to_phys(d, addr + sizeof(uint32_t)),
+	    descr + sizeof(uint32_t), sizeof(uint32_t) * 3, MEM_READ,
+	    PHYSICAL | NO_EXCEPTIONS)) {
 		fatal("[ dec21143_tx: memory_rw failed! ]\n");
 		return 0;
 	}
 
-	tdes1 = descr[4] + (descr[5]<<8) + (descr[6]<<16) + (descr[7]<<24);
-	tdes2 = descr[8] + (descr[9]<<8) + (descr[10]<<16) + (descr[11]<<24);
-	tdes3 = descr[12] + (descr[13]<<8) + (descr[14]<<16) + (descr[15]<<24);
+	tdes1 = load_le32(&descr[4]);
+	tdes2 = load_le32(&descr[8]);
+	tdes3 = load_le32(&descr[12]);
 
 	buf1_size = tdes1 & TDCTL_SIZE1;
 	buf2_size = (tdes1 & TDCTL_SIZE2) >> TDCTL_SIZE2_SHIFT;
@@ -338,10 +717,9 @@ int dec21143_tx(struct cpu *cpu, struct 
 	}
 
 	/*
-	fatal("{ TX (%llx): 0x%08x 0x%08x 0x%x 0x%x: buf %i bytes at 0x%x }\n",
-	  (long long)addr, tdes0, tdes1, tdes2, tdes3, bufsize, (int)bufaddr);
+	fatal("{ TX (%x): 0x%08x 0x%08x 0x%x 0x%x: buf %i bytes at 0x%x }\n",
+	  addr, tdes0, tdes1, tdes2, tdes3, bufsize, bufaddr);
 	*/
-	bufaddr &= 0x7fffffff;
 
 	/*  Assume no error:  */
 	tdes0 &= ~ (TDSTAT_Tx_UF | TDSTAT_Tx_EC | TDSTAT_Tx_LC
@@ -350,13 +728,13 @@ int dec21143_tx(struct cpu *cpu, struct 
 	if (tdes1 & TDCTL_Tx_SET) {
 		/*
 		 *  Setup Packet.
-		 *
-		 *  TODO. For now, just ignore it, and pretend it worked.
 		 */
 		/*  fatal("{ TX: setup packet }\n");  */
-		if (bufsize != 192)
+		if (bufsize != TULIP_SETUP_PACKET_LEN)
 			fatal("[ dec21143: setup packet len = %i, should be"
-			    " 192! ]\n", (int)bufsize);
+			    " %d! ]\n", (int)bufsize, TULIP_SETUP_PACKET_LEN);
+		else
+			dec21143_process_setup_packet(cpu, d, tdes1, bufaddr);
 		if (tdes1 & TDCTL_Tx_IC)
 			d->reg[CSR_STATUS/8] |= STATUS_TI;
 		/*  New descriptor values, according to the docs:  */
@@ -388,7 +766,8 @@ int dec21143_tx(struct cpu *cpu, struct 
 
 		/*  "DMA" data from emulated physical memory into the buf:  */
 		for (i=0; i<bufsize; i++) {
-			cpu->memory_rw(cpu, cpu->mem, bufaddr + i,
+			cpu->memory_rw(cpu, cpu->mem,
+			    dma_to_phys(d, bufaddr + i),
 			    d->cur_tx_buf + d->cur_tx_buf_len + i, 1, MEM_READ,
 			    PHYSICAL | NO_EXCEPTIONS);
 			/*  fatal(" %02x", d->cur_tx_buf[
@@ -400,9 +779,9 @@ int dec21143_tx(struct cpu *cpu, struct 
 		/*  Last segment? Then actually transmit it:  */
 		if (tdes1 & TDCTL_Tx_LS) {
 			/*  fatal("{ TX: data frame complete. }\n");  */
-			if (d->net != NULL) {
-				net_ethernet_tx(d->net, d, d->cur_tx_buf,
-				    d->cur_tx_buf_len);
+			if (d->nic.net != NULL) {
+				net_ethernet_tx(d->nic.net, &d->nic,
+				    d->cur_tx_buf, d->cur_tx_buf_len);
 			} else {
 				static int warn = 0;
 				if (!warn)
@@ -430,17 +809,13 @@ int dec21143_tx(struct cpu *cpu, struct 
 		tdes0 |= TDSTAT_ES;
 
 	/*  Descriptor writeback:  */
-	descr[ 0] = tdes0;       descr[ 1] = tdes0 >> 8;
-	descr[ 2] = tdes0 >> 16; descr[ 3] = tdes0 >> 24;
-	descr[ 4] = tdes1;       descr[ 5] = tdes1 >> 8;
-	descr[ 6] = tdes1 >> 16; descr[ 7] = tdes1 >> 24;
-	descr[ 8] = tdes2;       descr[ 9] = tdes2 >> 8;
-	descr[10] = tdes2 >> 16; descr[11] = tdes2 >> 24;
-	descr[12] = tdes3;       descr[13] = tdes3 >> 8;
-	descr[14] = tdes3 >> 16; descr[15] = tdes3 >> 24;
+	store_le32(&descr[0], tdes0);
+	store_le32(&descr[4], tdes1);
+	store_le32(&descr[8], tdes2);
+	store_le32(&descr[12], tdes3);
 
-	if (!cpu->memory_rw(cpu, cpu->mem, addr, descr, sizeof(uint32_t)
-	    * 4, MEM_WRITE, PHYSICAL | NO_EXCEPTIONS)) {
+	if (!cpu->memory_rw(cpu, cpu->mem, dma_to_phys(d, addr), descr,
+	    sizeof(uint32_t) * 4, MEM_WRITE, PHYSICAL | NO_EXCEPTIONS)) {
 		fatal("[ dec21143_tx: memory_rw failed! ]\n");
 		return 0;
 	}
@@ -750,7 +1125,6 @@ static void srom_access(struct cpu *cpu,
  */
 static void dec21143_reset(struct cpu *cpu, struct dec21143_data *d)
 {
-	int leaf;
 
 	if (d->cur_rx_buf != NULL)
 		free(d->cur_rx_buf);
@@ -759,7 +1133,6 @@ static void dec21143_reset(struct cpu *c
 	d->cur_rx_buf = d->cur_tx_buf = NULL;
 
 	memset(d->reg, 0, sizeof(uint32_t) * N_REGS);
-	memset(d->srom, 0, sizeof(d->srom));
 	memset(d->mii_phy_reg, 0, sizeof(d->mii_phy_reg));
 
 	/*  Register values at reset, according to the manual:  */
@@ -772,35 +1145,8 @@ static void dec21143_reset(struct cpu *c
 	d->tx_idling_threshold = 10;
 	d->cur_rx_addr = d->cur_tx_addr = 0;
 
-	/*  Version (= 1) and Chip count (= 1):  */
-	d->srom[TULIP_ROM_SROM_FORMAT_VERION] = 1;
-	d->srom[TULIP_ROM_CHIP_COUNT] = 1;
-
 	/*  Set the MAC address:  */
-	memcpy(d->srom + TULIP_ROM_IEEE_NETWORK_ADDRESS, d->mac, 6);
-
-	leaf = 30;
-	d->srom[TULIP_ROM_CHIPn_DEVICE_NUMBER(0)] = 0;
-	d->srom[TULIP_ROM_CHIPn_INFO_LEAF_OFFSET(0)] = leaf & 255;
-	d->srom[TULIP_ROM_CHIPn_INFO_LEAF_OFFSET(0)+1] = leaf >> 8;
-
-	d->srom[leaf+TULIP_ROM_IL_SELECT_CONN_TYPE] = 0; /*  Not used?  */
-	d->srom[leaf+TULIP_ROM_IL_MEDIA_COUNT] = 2;
-	leaf += TULIP_ROM_IL_MEDIAn_BLOCK_BASE;
-
-	d->srom[leaf] = 7;	/*  descriptor length  */
-	d->srom[leaf+1] = TULIP_ROM_MB_21142_SIA;
-	d->srom[leaf+2] = TULIP_ROM_MB_MEDIA_100TX;
-	/*  here comes 4 bytes of GPIO control/data settings  */
-	leaf += d->srom[leaf];
-
-	d->srom[leaf] = 15;	/*  descriptor length  */
-	d->srom[leaf+1] = TULIP_ROM_MB_21142_MII;
-	d->srom[leaf+2] = 0;	/*  PHY nr  */
-	d->srom[leaf+3] = 0;	/*  len of select sequence  */
-	d->srom[leaf+4] = 0;	/*  len of reset sequence  */
-	/*  5,6, 7,8, 9,10, 11,12, 13,14 = unused by GXemul  */
-	leaf += d->srom[leaf];
+	memcpy(d->nic.mac_address, d->srom + TULIP_ROM_IEEE_NETWORK_ADDRESS, 6);
 
 	/*  MII PHY initial state:  */
 	d->mii_state = MII_STATE_RESET;
@@ -814,12 +1160,13 @@ static void dec21143_reset(struct cpu *c
 DEVICE_ACCESS(dec21143)
 {
 	struct dec21143_data *d = (struct dec21143_data *) extra;
-	uint64_t idata = 0, odata = 0;
+	uint32_t idata = 0, odata = 0;
 	uint32_t oldreg = 0;
 	int regnr = relative_addr >> 3;
 
 	if (writeflag == MEM_WRITE)
-		idata = memory_readmax64(cpu, data, len | d->pci_little_endian);
+		idata = (uint32_t)memory_readmax64(cpu, data,
+		    len | d->pci_little_endian);
 
 	if ((relative_addr & 7) == 0 && regnr < N_REGS) {
 		if (writeflag == MEM_READ) {
@@ -916,8 +1263,15 @@ DEVICE_ACCESS(dec21143)
 				/*  Turned off RX? Then go to stopped state:  */
 				d->reg[CSR_STATUS/8] &= ~STATUS_RS;
 			}
+			/*  Maintain r/o filter mode bits:  */
+			d->reg[CSR_OPMODE/8] &=
+			    ~(OPMODE_HP | OPMODE_HO | OPMODE_IF);
+			d->reg[CSR_OPMODE/8] |= oldreg &
+			    (OPMODE_HP | OPMODE_HO | OPMODE_IF);
 			idata &= ~(OPMODE_HBD | OPMODE_SCR | OPMODE_PCS
-			    | OPMODE_PS | OPMODE_SF | OPMODE_TTM | OPMODE_FD);
+			    | OPMODE_PS | OPMODE_SF | OPMODE_TTM | OPMODE_FD
+			    | OPMODE_IF | OPMODE_HO | OPMODE_HP | OPMODE_PR
+			    | OPMODE_PM);
 			if (idata & OPMODE_PNIC_IT) {
 				idata &= ~OPMODE_PNIC_IT;
 				d->tx_idling = d->tx_idling_threshold;
@@ -926,6 +1280,7 @@ DEVICE_ACCESS(dec21143)
 				fatal("[ dec21143: UNIMPLEMENTED OPMODE bits"
 				    ": 0x%08x ]\n", (int)idata);
 			}
+			dec21143_update_rx_mode(d);
 			dev_dec21143_tick(cpu, extra);
 		}
 		break;
@@ -976,6 +1331,7 @@ DEVINIT(dec21143)
 {
 	struct dec21143_data *d;
 	char name2[100];
+	int leaf;
 
 	CHECK_ALLOCATION(d = (struct dec21143_data *) malloc(sizeof(struct dec21143_data)));
 	memset(d, 0, sizeof(struct dec21143_data));
@@ -983,15 +1339,80 @@ DEVINIT(dec21143)
 	INTERRUPT_CONNECT(devinit->interrupt_path, d->irq);
 	d->pci_little_endian = devinit->pci_little_endian;
 
-	net_generate_unique_mac(devinit->machine, d->mac);
-	net_add_nic(devinit->machine->emul->net, d, d->mac);
-	d->net = devinit->machine->emul->net;
+	/* XXX XXX XXX */
+	switch (devinit->machine->machine_type) {
+	/*
+	 * Footbridge systems -- this is actually configurable by
+	 * system software, but this is the window setting that
+	 * NetBSD uses.
+	 */
+	case MACHINE_CATS:
+	case MACHINE_NETWINDER:
+		d->xxx_dma_to_phys_mask = ~0x20000000;
+		break;
+
+	/*
+	 * V3 Semi PCI bus controller -- this is actually configurable
+	 * by system sofware, but this is the value previously hard-coded
+	 * for all platforms that did not work on Footbridge systems.
+	 */
+	case MACHINE_ALGOR:
+		/* FALLTHROUGH */
+
+	/* Other known users of dc21143 that came along for the ride. */
+	case MACHINE_COBALT:
+	case MACHINE_PMPPC:
+	case MACHINE_PREP:
+	case MACHINE_MACPPC:
+	case MACHINE_MVMEPPC:
+		d->xxx_dma_to_phys_mask = 0x7fffffff;
+		break;
+
+	default:
+		fatal("[ dec21143: default DMA mask for unhandled machine %d\n",
+		      devinit->machine->machine_type);
+		d->xxx_dma_to_phys_mask = 0xffffffff;
+	}
+
+	memset(d->srom, 0, sizeof(d->srom));
+
+	/*  Version (= 1) and Chip count (= 1):  */
+	d->srom[TULIP_ROM_SROM_FORMAT_VERION] = 1;
+	d->srom[TULIP_ROM_CHIP_COUNT] = 1;
+
+	leaf = 30;
+	d->srom[TULIP_ROM_CHIPn_DEVICE_NUMBER(0)] = 0;
+	d->srom[TULIP_ROM_CHIPn_INFO_LEAF_OFFSET(0)] = leaf & 255;
+	d->srom[TULIP_ROM_CHIPn_INFO_LEAF_OFFSET(0)+1] = leaf >> 8;
+
+	d->srom[leaf+TULIP_ROM_IL_SELECT_CONN_TYPE] = 0; /*  Not used?  */
+	d->srom[leaf+TULIP_ROM_IL_MEDIA_COUNT] = 2;
+	leaf += TULIP_ROM_IL_MEDIAn_BLOCK_BASE;
+
+	d->srom[leaf] = 7;	/*  descriptor length  */
+	d->srom[leaf+1] = TULIP_ROM_MB_21142_SIA;
+	d->srom[leaf+2] = TULIP_ROM_MB_MEDIA_100TX;
+	/*  here comes 4 bytes of GPIO control/data settings  */
+	leaf += d->srom[leaf];
+
+	d->srom[leaf] = 15;	/*  descriptor length  */
+	d->srom[leaf+1] = TULIP_ROM_MB_21142_MII;
+	d->srom[leaf+2] = 0;	/*  PHY nr  */
+	d->srom[leaf+3] = 0;	/*  len of select sequence  */
+	d->srom[leaf+4] = 0;	/*  len of reset sequence  */
+	/*  5,6, 7,8, 9,10, 11,12, 13,14 = unused by GXemul  */
+	leaf += d->srom[leaf];
+
+	net_generate_unique_mac(devinit->machine, d->nic.mac_address);
+	memcpy(d->srom + TULIP_ROM_IEEE_NETWORK_ADDRESS, d->nic.mac_address, 6);
+	net_add_nic(devinit->machine->emul->net, &d->nic);
 
 	dec21143_reset(devinit->machine->cpus[0], d);
 
 	snprintf(name2, sizeof(name2), "%s [%02x:%02x:%02x:%02x:%02x:%02x]",
-	    devinit->name, d->mac[0], d->mac[1], d->mac[2], d->mac[3],
-	    d->mac[4], d->mac[5]);
+	    devinit->name, d->nic.mac_address[0], d->nic.mac_address[1],
+	    d->nic.mac_address[2], d->nic.mac_address[3],
+	    d->nic.mac_address[4], d->nic.mac_address[5]);
 
 	memory_device_register(devinit->machine->memory, name2,
 	    devinit->addr, 0x100, dev_dec21143_access, d, DM_DEFAULT, NULL);
