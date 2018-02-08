$NetBSD: patch-controller.c,v 1.1.2.2 2018/02/08 22:00:59 spz Exp $

Avoid explicit out of bound read (undefined behaviour)
fix whitespace

--- controller.c.orig	2013-08-10 02:01:58.000000000 +0000
+++ controller.c
@@ -292,15 +292,15 @@ static void setup_nhm(void)
 
 	/* First, locate the PCI bus where the MCH is located */
 
-	for(i = 0; i < sizeof(possible_nhm_bus); i++) {
+	for(i = 0; i < sizeof(possible_nhm_bus)/sizeof(possible_nhm_bus[0]); i++) {
 		pci_conf_read( possible_nhm_bus[i], 3, 4, 0x00, 2, &vid);
 		pci_conf_read( possible_nhm_bus[i], 3, 4, 0x02, 2, &did);
 		vid &= 0xFFFF;
 		did &= 0xFF00;
 		if(vid == 0x8086 && did >= 0x2C00) { 
 			nhm_bus = possible_nhm_bus[i]; 
-			}
-}
+		}
+	}
 
 	/* Now, we have the last IMC bus number in nhm_bus */
 	/* Check for ECC & Scrub */
@@ -327,14 +327,14 @@ static void setup_nhm32(void)
 	ctrl.mode = ECC_NONE;
 
 	/* First, locate the PCI bus where the MCH is located */
-	for(i = 0; i < sizeof(possible_nhm_bus); i++) {
+	for(i = 0; i < sizeof(possible_nhm_bus) / sizeof(possible_nhm_bus[0]); i++) {
 		pci_conf_read( possible_nhm_bus[i], 3, 4, 0x00, 2, &vid);
 		pci_conf_read( possible_nhm_bus[i], 3, 4, 0x02, 2, &did);
 		vid &= 0xFFFF;
 		did &= 0xFF00;
 		if(vid == 0x8086 && did >= 0x2C00) { 
 			nhm_bus = possible_nhm_bus[i]; 
-			}
+		}
 	}
 
 	/* Now, we have the last IMC bus number in nhm_bus */
