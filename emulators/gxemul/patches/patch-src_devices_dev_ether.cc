$NetBSD: patch-src_devices_dev_ether.cc,v 1.1 2020/10/07 00:43:05 thorpej Exp $

Add support for tap(4)-based networking.

--- src/devices/dev_ether.cc.orig	2020-10-05 22:56:01.167967575 +0000
+++ src/devices/dev_ether.cc	2020-10-05 22:56:17.330782903 +0000
@@ -49,6 +49,8 @@
 #define	DEV_ETHER_TICK_SHIFT	14
 
 struct ether_data {
+	struct nic_data		nic;
+
 	unsigned char		buf[DEV_ETHER_BUFFER_SIZE];
 	unsigned char		mac[6];
 
@@ -66,7 +68,7 @@ DEVICE_TICK(ether)
 
 	d->status &= ~DEV_ETHER_STATUS_MORE_PACKETS_AVAILABLE;
 	if (cpu->machine->emul->net != NULL)
-		r = net_ethernet_rx_avail(cpu->machine->emul->net, d);
+		r = net_ethernet_rx_avail(cpu->machine->emul->net, &d->nic);
 	if (r)
 		d->status |= DEV_ETHER_STATUS_MORE_PACKETS_AVAILABLE;
 
@@ -147,7 +149,7 @@ DEVICE_ACCESS(ether)
 			else {
 				d->status &= ~DEV_ETHER_STATUS_PACKET_RECEIVED;
 				if (net_ethernet_rx(cpu->machine->emul->net,
-				    d, &incoming_ptr, &incoming_len)) {
+				    &d->nic, &incoming_ptr, &incoming_len)) {
 					d->status |=
 					    DEV_ETHER_STATUS_PACKET_RECEIVED;
 					if (incoming_len>DEV_ETHER_BUFFER_SIZE)
@@ -167,7 +169,7 @@ DEVICE_ACCESS(ether)
 				fatal("[ ether: SEND but no net? ]\n");
 			else
 				net_ethernet_tx(cpu->machine->emul->net,
-				    d, d->buf, d->packet_len);
+				    &d->nic, d->buf, d->packet_len);
 			d->status &= ~DEV_ETHER_STATUS_PACKET_RECEIVED;
 			dev_ether_tick(cpu, d);
 			break;
@@ -183,7 +185,7 @@ DEVICE_ACCESS(ether)
 			fatal("[ ether: read of MAC is not allowed! ]\n");
 		} else {
 			// Write out the MAC address to the address given.
-			cpu->memory_rw(cpu, cpu->mem, idata, d->mac,
+			cpu->memory_rw(cpu, cpu->mem, idata, d->nic.mac_address,
 			    6, MEM_WRITE, CACHE_NONE);
 		}
 		break;
@@ -221,9 +223,11 @@ DEVINIT(ether)
 
 	INTERRUPT_CONNECT(devinit->interrupt_path, d->irq);
 
-	net_generate_unique_mac(devinit->machine, d->mac);
+	net_generate_unique_mac(devinit->machine, d->nic.mac_address);
 	snprintf(tmp, sizeof(tmp), "%02x:%02x:%02x:%02x:%02x:%02x",
-	    d->mac[0], d->mac[1], d->mac[2], d->mac[3], d->mac[4], d->mac[5]);
+	    d->nic.mac_address[0], d->nic.mac_address[1],
+	    d->nic.mac_address[2], d->nic.mac_address[3],
+	    d->nic.mac_address[4], d->nic.mac_address[5]);
 
 	snprintf(n1, nlen, "%s [%s]", devinit->name, tmp);
 	snprintf(n2, nlen, "%s [%s, control]", devinit->name, tmp);
@@ -237,7 +241,7 @@ DEVINIT(ether)
 	    DEV_ETHER_LENGTH-DEV_ETHER_BUFFER_SIZE, dev_ether_access, (void *)d,
 	    DM_DEFAULT, NULL);
 
-	net_add_nic(devinit->machine->emul->net, d, d->mac);
+	net_add_nic(devinit->machine->emul->net, &d->nic);
 
 	machine_add_tickfunction(devinit->machine,
 	    dev_ether_tick, d, DEV_ETHER_TICK_SHIFT);
