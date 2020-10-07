$NetBSD: patch-src_devices_dev_sgi_mec.cc,v 1.1 2020/10/07 00:43:05 thorpej Exp $

Updates for tap(4)-related changes to Ethernet support.

--- src/devices/dev_sgi_mec.cc.orig	2020-10-05 22:58:11.248005164 +0000
+++ src/devices/dev_sgi_mec.cc	2020-10-05 22:58:31.644418157 +0000
@@ -81,13 +81,13 @@
 #define	N_RX_ADDRESSES		16
 
 struct sgi_mec_data {
+	struct nic_data	nic;
+
 	uint64_t	reg[DEV_SGI_MEC_LENGTH / sizeof(uint64_t)];
 
 	struct interrupt irq;
 	int		prev_asserted;
 
-	unsigned char	macaddr[6];
-
 	unsigned char	cur_tx_packet[MAX_TX_PACKET_LEN];
 	int		cur_tx_packet_len;
 
@@ -157,8 +157,8 @@ static int mec_try_rx(struct cpu *cpu, s
 	}
 
 	if (d->cur_rx_packet == NULL &&
-	    net_ethernet_rx_avail(cpu->machine->emul->net, d))
-		net_ethernet_rx(cpu->machine->emul->net, d,
+	    net_ethernet_rx_avail(cpu->machine->emul->net, &d->nic))
+		net_ethernet_rx(cpu->machine->emul->net, &d->nic,
 		    &d->cur_rx_packet, &d->cur_rx_packet_len);
 
 	if (d->cur_rx_packet == NULL)
@@ -343,7 +343,7 @@ static int mec_try_tx(struct cpu *cpu, s
 	if (j < len)
 		fatal("[ mec_try_tx: not enough data? ]\n");
 
-	net_ethernet_tx(cpu->machine->emul->net, d,
+	net_ethernet_tx(cpu->machine->emul->net, &d->nic,
 	    d->cur_tx_packet, d->cur_tx_packet_len);
 
 	/*  see openbsd's if_mec.c for details  */
@@ -675,13 +675,14 @@ void dev_sgi_mec_init(struct machine *ma
 	memset(d, 0, sizeof(struct sgi_mec_data));
 
 	INTERRUPT_CONNECT(irq_path, d->irq);
-	memcpy(d->macaddr, macaddr, 6);
+	memcpy(d->nic.mac_address, macaddr, 6);
 	mec_reset(d);
 
 	CHECK_ALLOCATION(name2 = (char *) malloc(nlen));
 	snprintf(name2, nlen, "mec [%02x:%02x:%02x:%02x:%02x:%02x]",
-	    d->macaddr[0], d->macaddr[1], d->macaddr[2],
-	    d->macaddr[3], d->macaddr[4], d->macaddr[5]);
+	    d->nic.mac_address[0], d->nic.mac_address[1],
+	    d->nic.mac_address[2], d->nic.mac_address[3],
+	    d->nic.mac_address[4], d->nic.mac_address[5]);
 
 	memory_device_register(mem, name2, baseaddr,
 	    DEV_SGI_MEC_LENGTH, dev_sgi_mec_access, (void *)d,
@@ -690,7 +691,7 @@ void dev_sgi_mec_init(struct machine *ma
 	machine_add_tickfunction(machine, dev_sgi_mec_tick, d,
 	    MEC_TICK_SHIFT);
 
-	net_add_nic(machine->emul->net, d, macaddr);
+	net_add_nic(machine->emul->net, &d->nic);
 }
 
 
