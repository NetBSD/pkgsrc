$NetBSD: patch-src_netbsd__pci.c,v 1.1 2018/10/26 10:18:58 maya Exp $

Don't require root access.
support more than pci0 - from netbase base

--- src/netbsd_pci.c.orig	2017-10-23 15:48:29.000000000 +0000
+++ src/netbsd_pci.c
@@ -848,9 +848,11 @@ pci_device_netbsd_has_kernel_driver(stru
 {
 #ifdef PCI_IOC_DRVNAME
 	/*
-	 * NetBSD PCI_IOC_DRVNAME appears at the same time as pci_drvname(3)
+	 * NetBSD PCI_IOC_DRVNAME appears at the same time as pci_drvname(3),
+	 * same as the better onbus version.
 	 */
 	char drvname[16];
+	int i;
 
 	if (dev->bus >= nbuses)
 		return 0;
@@ -858,10 +860,22 @@ pci_device_netbsd_has_kernel_driver(stru
 	/*
 	 * vga(4) should be considered "not bound".
 	 */
-	if (pci_drvname(buses[dev->bus].fd, dev->dev, dev->func,
-			drvname, sizeof drvname) == 0 &&
-	    strncmp(drvname, "vga", 3) != 0)
-		return 1;
+	for (i = 0; i < nbuses; i++) {
+		if (buses[i].num == dev->bus) {
+			int rv;
+
+#ifdef PCI_IOC_DRVNAMEONBUS
+			rv = pci_drvnameonbus(buses[i].fd, dev->bus,
+			    dev->dev, dev->func, drvname, sizeof drvname);
+#else
+			rv = pci_drvname(buses[i].fd,
+			    dev->dev, dev->func, drvname, sizeof drvname);
+#endif
+			if (rv == 0 && strncmp(drvname, "vga", 3) != 0)
+				return 1;
+			return 0;
+		}
+	}
 #endif
 	return 0;
 }
@@ -910,6 +924,9 @@ pci_system_netbsd_create(void)
 	nbuses = 0;
 	snprintf(netbsd_devname, 32, "/dev/pci%d", nbuses);
 	pcifd = open(netbsd_devname, O_RDWR | O_CLOEXEC);
+	if (pcifd == -1)
+		pcifd = open(netbsd_devname, O_RDONLY | O_CLOEXEC);
+
 	while (pcifd > 0) {
 		ioctl(pcifd, PCI_IOC_BUSINFO, &businfo);
 		buses[nbuses].fd = pcifd;
@@ -932,6 +949,9 @@ pci_system_netbsd_create(void)
 		}
 		snprintf(netbsd_devname, 32, "/dev/pci%d", nbuses);
 		pcifd = open(netbsd_devname, O_RDWR);
+		if (pcifd == -1)
+			pcifd = open(netbsd_devname, O_RDONLY | O_CLOEXEC);
+
 	}
 
 	pci_sys->num_devices = ndevs;
