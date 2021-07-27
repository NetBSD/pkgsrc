$NetBSD: patch-drivers_pci_pcie__rockchip.c,v 1.1 2021/07/27 20:47:35 tnn Exp $

backport PCIe fixes from sysutils/u-boot-rockpro64

--- drivers/pci/pcie_rockchip.c.orig	2020-04-15 17:13:47.000000000 +0000
+++ drivers/pci/pcie_rockchip.c
@@ -171,8 +171,11 @@ enum of_gpio_flags {
 
 #define RC_REGION_0_ADDR_TRANS_H		0x00000000
 #define RC_REGION_0_ADDR_TRANS_L		0x00000000
-#define RC_REGION_0_PASS_BITS			(25 - 1)
+#define RC_REGION_0_PASS_BITS			(20 - 1)
 #define MAX_AXI_WRAPPER_REGION_NUM		33
+#define PCIE_ATR_HDR_CFG_TYPE0			0xa
+#define PCIE_ATR_HDR_CFG_TYPE1			0xb
+#define PCIE_ATR_HDR_RID			BIT(23)
 
 #define PCI_CLASS_BRIDGE_PCI		0x0604
 
@@ -359,42 +362,64 @@ static int rockchip_pcie_wr_own_conf(voi
     return 0;
 }
 
-static int rockchip_pcie_rd_other_conf(void *priv, int where,
+static void rockchip_pcie_write(struct pcie_rockchip *rockchip, u32 val, u32 reg);
+volatile int rockchip_pcie_expect_data_abort;
+volatile int rockchip_pcie_got_data_abort;
+
+static int rockchip_pcie_rd_other_conf(void *priv, pci_dev_t d, int where,
                                        int size, u32 *val)
 {
     u32 busdev;
     struct pcie_rockchip *rockchip = (struct pcie_rockchip *)priv;
 
-    /*
-     * BDF = 01:00:00
-     * end-to-end support, no hierarchy....
-     */
-    busdev = PCIE_ECAM_ADDR(1, 0, 0, where);
+    busdev = PCIE_ECAM_ADDR(0, PCI_DEV(d), PCI_FUNC(d), where);
+    rockchip_pcie_write(rockchip,
+      (PCI_BUS(d) << 20) | RC_REGION_0_PASS_BITS,
+      PCIE_CORE_OB_REGION_ADDR0);
+    rockchip_pcie_write(rockchip,
+      PCIE_ATR_HDR_RID | (PCI_BUS(d) > (rockchip->first_busno  + 1) ? PCIE_ATR_HDR_CFG_TYPE1 : PCIE_ATR_HDR_CFG_TYPE0),
+      PCIE_CORE_OB_REGION_DESC0);
+    dsb();
+    rockchip_pcie_got_data_abort = 0;
+    rockchip_pcie_expect_data_abort = 1;
 
 	if (size == 4) {
         *val = readl(rockchip->axi_base + busdev);
+            if (rockchip_pcie_got_data_abort) {
+                *val = 0xFFFFFFFFUL;
+            }
 	} else if (size == 2) {
         *val = readw(rockchip->axi_base + busdev);
+            if (rockchip_pcie_got_data_abort) {
+                *val = 0xFFFF;
+            }
     } else if (size == 1) {
         *val = readb(rockchip->axi_base + busdev);
+            if (rockchip_pcie_got_data_abort) {
+                *val = 0xFF;
+            }
     } else {
         *val = 0;
         return -1;
     }
+    dsb();
+    rockchip_pcie_expect_data_abort = 0;
     return 0;
 }
 
-static int rockchip_pcie_wr_other_conf(void *priv, int where, int size, u32 val)
+static int rockchip_pcie_wr_other_conf(void *priv, pci_dev_t d, int where, int size, u32 val)
 {
     struct pcie_rockchip *rockchip = (struct pcie_rockchip *)priv;
     u32 busdev;
 
-    /*
-     * BDF = 01:00:00
-     * end-to-end support, no hierarchy....
-     */
-    busdev = PCIE_ECAM_ADDR(1, 0, 0, where);
-
+    busdev = PCIE_ECAM_ADDR(0, PCI_DEV(d), PCI_FUNC(d), where);
+    rockchip_pcie_write(rockchip,
+      (PCI_BUS(d) << 20) | RC_REGION_0_PASS_BITS,
+      PCIE_CORE_OB_REGION_ADDR0);
+    rockchip_pcie_write(rockchip,
+      PCIE_ATR_HDR_RID | (PCI_BUS(d) > (rockchip->first_busno  + 1) ? PCIE_ATR_HDR_CFG_TYPE1 : PCIE_ATR_HDR_CFG_TYPE0),
+      PCIE_CORE_OB_REGION_DESC0);
+    dsb();
     if (size == 4)
         writel(val, rockchip->axi_base + busdev);
     else if (size == 2)
@@ -403,7 +428,7 @@ static int rockchip_pcie_wr_other_conf(v
         writeb(val, rockchip->axi_base + busdev);
     else
         return -1;
-
+    dsb();
     return 0;
 }
 
@@ -436,7 +461,7 @@ static int pcie_rockchip_read_config(str
         if(ret < 0)
             return ret;
 	} else {
-        ret = rockchip_pcie_rd_other_conf(pcie, offset, size1, (u32 *)valuep);
+        ret = rockchip_pcie_rd_other_conf(pcie, bdf, offset, size1, (u32 *)valuep);
         if(ret < 0)
 			return ret;
 	}
@@ -470,7 +495,7 @@ static int pcie_rockchip_write_config(st
         if(ret < 0)
             return ret;
 	} else {
-        ret = rockchip_pcie_wr_other_conf(pcie, offset, size1, value);
+        ret = rockchip_pcie_wr_other_conf(pcie, bdf, offset, size1, value);
         if(ret < 0)
             return ret;
 	}
@@ -496,8 +521,9 @@ static int config_link(struct udevice *d
 	u64 msix_table_addr = 0x0;
 	bool is_msi = false, is_msix = false;
 	u32 cmd;
+	pci_dev_t odev = PCI_BUS(rockchip->first_busno + 1) | PCI_DEV(0) | PCI_FUNC(0);
 
-	rockchip_pcie_rd_other_conf((void *)rockchip, PCI_CLASS_REVISION, 4, &value);
+	rockchip_pcie_rd_other_conf((void *)rockchip, odev, PCI_CLASS_REVISION, 4, &value);
 	if ((value & (0xffff << 16)) !=
         (PCI_CLASS_MSC | PCI_SUBCLASS_NVME)) {
         debug("PCIe: device's classe code & revision ID = 0x%x\n",
@@ -506,8 +532,8 @@ static int config_link(struct udevice *d
         return -EINVAL;
     }
 
-    rockchip_pcie_rd_other_conf((void *)rockchip, PCI_VENDOR_ID, 2, &value);
-    rockchip_pcie_rd_other_conf((void *)rockchip, PCI_DEVICE_ID, 2, &value);
+    rockchip_pcie_rd_other_conf((void *)rockchip, odev, PCI_VENDOR_ID, 2, &value);
+    rockchip_pcie_rd_other_conf((void *)rockchip, odev, PCI_DEVICE_ID, 2, &value);
 
     rockchip_pcie_wr_own_conf((void *)rockchip, PCI_PRIMARY_BUS, 4, 0x0);
     rockchip_pcie_wr_own_conf((void *)rockchip, PCI_BRIDGE_CONTROL, 2, 0x0);
@@ -516,7 +542,7 @@ static int config_link(struct udevice *d
     /* only support 64bit non-prefetchable 16k mem region: BAR0 + BAR1
      * clear BAR1 for upper 32bit, no need to wr all 1s to see the size
      */
-    rockchip_pcie_wr_other_conf((void *)rockchip, PCI_BASE_ADDRESS_1, 4, 0x0);
+    rockchip_pcie_wr_other_conf((void *)rockchip, odev, PCI_BASE_ADDRESS_1, 4, 0x0);
 
     /* clear CCC and enable retrain link */
     rockchip_pcie_rd_own_conf((void *)rockchip, PCI_LNKCTL, 2, &value);
@@ -542,22 +568,22 @@ static int config_link(struct udevice *d
     /* clear some enable bits for error */
     rockchip_pcie_wr_own_conf((void *)rockchip, PCI_BRIDGE_CONTROL, 2, 0x0);
     /* write EP's command register, disable EP */
-    rockchip_pcie_wr_other_conf((void *)rockchip, PCI_COMMAND, 2, 0x0);
+    rockchip_pcie_wr_other_conf((void *)rockchip, odev, PCI_COMMAND, 2, 0x0);
 
 	for (i = 0; i < rockchip->bus.region_count; i++) {
         if (rockchip->bus.regions[i].flags == PCI_REGION_MEM) {
             /* configre BAR0 */
-			rockchip_pcie_wr_other_conf((void *)rockchip, PCI_BASE_ADDRESS_0, 4,
+            rockchip_pcie_wr_other_conf((void *)rockchip, odev, PCI_BASE_ADDRESS_0, 4,
                                         rockchip->bus.regions[i].bus_start);
             /* configre BAR1 */
-            rockchip_pcie_wr_other_conf((void *)rockchip, PCI_BASE_ADDRESS_1,
+            rockchip_pcie_wr_other_conf((void *)rockchip, odev, PCI_BASE_ADDRESS_1,
                                   4, 0x0);
             break;
         }
     }
 
 	/* write EP's command register */
-    rockchip_pcie_wr_other_conf((void *)rockchip, PCI_COMMAND, 2, 0x0);
+    rockchip_pcie_wr_other_conf((void *)rockchip, odev, PCI_COMMAND, 2, 0x0);
 
     /* write RC's IO base and limit including upper */
     rockchip_pcie_wr_own_conf((void *)rockchip, PCI_IO_BASE_UPPER16, 4, 0xffff);
@@ -583,11 +609,11 @@ static int config_link(struct udevice *d
     rockchip_pcie_wr_own_conf((void *)rockchip, 0x104, 4, 0x0);
 
     value = 0;
-    rockchip_pcie_rd_other_conf((void *)rockchip, 0x34, 1, &pointer);
+    rockchip_pcie_rd_other_conf((void *)rockchip, odev, 0x34, 1, &pointer);
     debug("PCIe: cap pointer = 0x%x\n", pointer);
 
     for (;;) {
-        rockchip_pcie_rd_other_conf((void *)rockchip, pointer, 2, &next_pointer);
+        rockchip_pcie_rd_other_conf((void *)rockchip, odev, pointer, 2, &next_pointer);
         if ((next_pointer & 0xff) == PCI_CAP_ID_MSI) {
             is_msi = true;
             break;
@@ -602,18 +628,18 @@ static int config_link(struct udevice *d
     }
     if (is_msi) {
         debug("PCIe: msi cap pointer = 0x%x\n", pointer);
-        rockchip_pcie_rd_other_conf((void *)rockchip, pointer + 2, 2, &value);
+        rockchip_pcie_rd_other_conf((void *)rockchip, odev, pointer + 2, 2, &value);
         value |= 0x1;
-        rockchip_pcie_wr_other_conf((void *)rockchip, pointer + 2, 2, value);
-        rockchip_pcie_wr_other_conf((void *)rockchip, pointer + 4, 4,
+        rockchip_pcie_wr_other_conf((void *)rockchip, odev, pointer + 2, 2, value);
+        rockchip_pcie_wr_other_conf((void *)rockchip, odev, pointer + 4, 4,
                               rockchip->bus.msi_base);
-        rockchip_pcie_wr_other_conf((void *)rockchip, pointer + 8, 4, 0x0);
+        rockchip_pcie_wr_other_conf((void *)rockchip, odev, pointer + 8, 4, 0x0);
     } else if (is_msix) {
         debug("PCIe: msi-x cap pointer = 0x%x\n", pointer);
-        rockchip_pcie_rd_other_conf((void *)rockchip, pointer + 2, 2, &value);
+        rockchip_pcie_rd_other_conf((void *)rockchip, odev, pointer + 2, 2, &value);
         debug("PCIe: msi-x table size = %d\n", value & 0x7ff);
         table_size = value & 0x7ff;
-        rockchip_pcie_rd_other_conf((void *)rockchip, pointer + 8, 2, &value);
+        rockchip_pcie_rd_other_conf((void *)rockchip, odev, pointer + 8, 2, &value);
         debug("PCIe: msi-x BIR = 0x%x\n", value & 0x7);
         debug("PCIe: msi-x table offset = 0x%x\n", value & 0xfffffff8);
 
@@ -634,20 +660,20 @@ static int config_link(struct udevice *d
             writel(i,		msix_table_addr + i * 0x8);
             writel(0x0,		msix_table_addr + i * 0xc);
         }
-        rockchip_pcie_wr_other_conf((void *)rockchip, pointer + 2, 2, 0x20);
-        rockchip_pcie_wr_other_conf((void *)rockchip, pointer + 2, 2, 0xc020);
-        rockchip_pcie_wr_other_conf((void *)rockchip, pointer + 2, 2, 0x8020);
+        rockchip_pcie_wr_other_conf((void *)rockchip, odev, pointer + 2, 2, 0x20);
+        rockchip_pcie_wr_other_conf((void *)rockchip, odev, pointer + 2, 2, 0xc020);
+        rockchip_pcie_wr_other_conf((void *)rockchip, odev, pointer + 2, 2, 0x8020);
     } else {
         debug("PCIe: no msi and msi-x\n");
     }
 
-	rockchip_pcie_rd_other_conf((void *)rockchip, PCI_COMMAND, 2, &value);
+	rockchip_pcie_rd_other_conf((void *)rockchip, odev, PCI_COMMAND, 2, &value);
 	value |= PCI_COMMAND_INTX_DISABLE;
-	rockchip_pcie_wr_other_conf((void *)rockchip, PCI_COMMAND, 2, value);
+	rockchip_pcie_wr_other_conf((void *)rockchip, odev, PCI_COMMAND, 2, value);
 
-	rockchip_pcie_rd_other_conf((void *)rockchip, PCI_COMMAND, 2, &cmd);
+	rockchip_pcie_rd_other_conf((void *)rockchip, odev, PCI_COMMAND, 2, &cmd);
 	cmd = (cmd | PCI_COMMAND_MEMORY | PCI_COMMAND_MASTER);
-	rockchip_pcie_wr_other_conf((void *)rockchip, PCI_COMMAND, 2, cmd);
+	rockchip_pcie_wr_other_conf((void *)rockchip, odev, PCI_COMMAND, 2, cmd);
 
 	return 0;
 }
@@ -780,6 +806,8 @@ static int rockchip_pcie_init_port(struc
 	/* assert: mgmt_sticky_rst->core_rst->mgmt_rst->pipe_rst */
 	rkcru_pcie_soft_reset(PCIE_RESET_NOFATAL, 0);
 
+	mdelay(20);
+
 	/* Enable Gen1 training */
 	rockchip_pcie_write(rockchip, PCIE_CLIENT_LINK_TRAIN_ENABLE,
 			    PCIE_CLIENT_CONFIG);
@@ -832,8 +860,11 @@ static int rockchip_pcie_init_port(struc
 			    PCIE_CORE_OB_REGION_ADDR0);
 	rockchip_pcie_write(rockchip, RC_REGION_0_ADDR_TRANS_H,
 			    PCIE_CORE_OB_REGION_ADDR1);
-	rockchip_pcie_write(rockchip, 0x0080000a, PCIE_CORE_OB_REGION_DESC0);
+	rockchip_pcie_write(rockchip, PCIE_ATR_HDR_RID | PCIE_ATR_HDR_CFG_TYPE0, PCIE_CORE_OB_REGION_DESC0);
 	rockchip_pcie_write(rockchip, 0x0, PCIE_CORE_OB_REGION_DESC1);
+
+	mdelay(80);
+
 	return 0;
 }
 
