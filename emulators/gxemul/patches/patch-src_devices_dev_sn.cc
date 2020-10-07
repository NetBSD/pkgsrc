$NetBSD: patch-src_devices_dev_sn.cc,v 1.1 2020/10/07 00:43:05 thorpej Exp $

Updates for tap(4)-related changes to Ethernet support.

--- src/devices/dev_sn.cc.orig	2020-10-05 22:58:49.162038719 +0000
+++ src/devices/dev_sn.cc	2020-10-05 22:59:04.524312162 +0000
@@ -48,8 +48,8 @@
 #define	DEV_SN_LENGTH		0x1000
 
 struct sn_data {
+	struct nic_data	nic;
 	struct interrupt irq;
-	unsigned char	macaddr[6];
 	uint32_t	reg[SONIC_NREGS];
 };
 
@@ -104,18 +104,19 @@ DEVINIT(sn)
 
 	INTERRUPT_CONNECT(devinit->interrupt_path, d->irq);
 
-	net_generate_unique_mac(devinit->machine, d->macaddr);
+	net_generate_unique_mac(devinit->machine, d->nic.mac_address);
 
 	CHECK_ALLOCATION(name2 = (char *) malloc(nlen));
 	snprintf(name2, nlen, "%s [%02x:%02x:%02x:%02x:%02x:%02x]",
-	    devinit->name, d->macaddr[0], d->macaddr[1], d->macaddr[2],
-	    d->macaddr[3], d->macaddr[4], d->macaddr[5]);
+	    devinit->name, d->nic.mac_address[0], d->nic.mac_address[1],
+	    d->nic.mac_address[2], d->nic.mac_address[3],
+	    d->nic.mac_address[4], d->nic.mac_address[5]);
 
 	memory_device_register(devinit->machine->memory, name2,
 	    devinit->addr, DEV_SN_LENGTH,
 	    dev_sn_access, (void *)d, DM_DEFAULT, NULL);
 
-	net_add_nic(devinit->machine->emul->net, d, d->macaddr);
+	net_add_nic(devinit->machine->emul->net, &d->nic);
 
 	return 1;
 }
