$NetBSD: patch-src_devices_dev_rtl8139c.cc,v 1.1 2020/10/07 00:43:05 thorpej Exp $

Updates for tap(4)-related changes to Ethernet support.

--- src/devices/dev_rtl8139c.cc.orig	2020-10-05 22:57:40.189047655 +0000
+++ src/devices/dev_rtl8139c.cc	2020-10-05 22:57:53.936646578 +0000
@@ -50,8 +50,9 @@
 #define	EEPROM_SIZE		0x100
 
 struct rtl8139c_data {
+	struct nic_data		nic;
+
 	struct interrupt	irq;
-	unsigned char		macaddr[6];
 
 	/*  Registers:  */
 	uint8_t			rl_command;
@@ -205,25 +206,26 @@ DEVINIT(rtl8139c)
 
 	INTERRUPT_CONNECT(devinit->interrupt_path, d->irq);
 
-	net_generate_unique_mac(devinit->machine, d->macaddr);
+	net_generate_unique_mac(devinit->machine, d->nic.mac_address);
 
 	/*  TODO: eeprom address width = 6 on 8129?  */
 	d->eeprom_address_width = 8;
 	d->eeprom_reg[0] = 0x8139;
-	d->eeprom_reg[7] = d->macaddr[0] + (d->macaddr[1] << 8);
-	d->eeprom_reg[8] = d->macaddr[2] + (d->macaddr[3] << 8);
-	d->eeprom_reg[9] = d->macaddr[4] + (d->macaddr[5] << 8);
+	d->eeprom_reg[7] = d->nic.mac_address[0] + (d->nic.mac_address[1] << 8);
+	d->eeprom_reg[8] = d->nic.mac_address[2] + (d->nic.mac_address[3] << 8);
+	d->eeprom_reg[9] = d->nic.mac_address[4] + (d->nic.mac_address[5] << 8);
 
 	CHECK_ALLOCATION(name2 = (char *) malloc(nlen));
 	snprintf(name2, nlen, "%s [%02x:%02x:%02x:%02x:%02x:%02x]",
-	    devinit->name, d->macaddr[0], d->macaddr[1], d->macaddr[2],
-	    d->macaddr[3], d->macaddr[4], d->macaddr[5]);
+	    devinit->name, d->nic.mac_address[0], d->nic.mac_address[1],
+	    d->nic.mac_address[2], d->nic.mac_address[3],
+	    d->nic.mac_address[4], d->nic.mac_address[5]);
 
 	memory_device_register(devinit->machine->memory, name2,
 	    devinit->addr, DEV_RTL8139C_LENGTH, dev_rtl8139c_access, (void *)d,
 	    DM_DEFAULT, NULL);
 
-	net_add_nic(devinit->machine->emul->net, d, d->macaddr);
+	net_add_nic(devinit->machine->emul->net, &d->nic);
 
 	return 1;
 }
