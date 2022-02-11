$NetBSD: patch-drivers_pci_pcie__rockchip.c,v 1.1 2022/02/11 21:46:14 mrg Exp $

u-boot-rockpro64: fix broken PCI config space handling:

- Program bus number into the ECAM decoder for each access
- Use type 1 PCI config cycles for config spaces behind bridge
- Add a platform specific hack to the synchronous exception handler
  to deal with PCI-e subsystem triggering data aborts when probing
  nonexistent PCI devices.
- properly delay after deasserting reset for downstream devices to
  have time to initialize.

Allows booting from PCI devices behind bridges and probing
devices other than 0:0:0 and 1:0:0.

--- drivers/pci/pcie_rockchip.c.orig	2021-07-05 15:11:28.000000000 +0000
+++ drivers/pci/pcie_rockchip.c
@@ -73,6 +73,8 @@ DECLARE_GLOBAL_DATA_PTR;
 #define PCIE_ATR_OB_REGION0_SIZE	(32 * 1024 * 1024)
 #define PCIE_ATR_OB_REGION_SIZE		(1 * 1024 * 1024)
 
+#define PCIE_ATR_REGION0_PASS_BITS (20 - 1)
+
 struct rockchip_pcie {
 	fdt_addr_t axi_base;
 	fdt_addr_t apb_base;
@@ -103,13 +105,15 @@ struct rockchip_pcie {
 
 static int rockchip_pcie_off_conf(pci_dev_t bdf, uint offset)
 {
-	unsigned int bus = PCI_BUS(bdf);
 	unsigned int dev = PCI_DEV(bdf);
 	unsigned int func = PCI_FUNC(bdf);
 
-	return (bus << 20) | (dev << 15) | (func << 12) | (offset & ~0x3);
+	return (dev << 15) | (func << 12) | (offset & ~0x3);
 }
 
+volatile int rockchip_pcie_expect_data_abort;
+volatile int rockchip_pcie_got_data_abort;
+
 static int rockchip_pcie_rd_conf(const struct udevice *udev, pci_dev_t bdf,
 				 uint offset, ulong *valuep,
 				 enum pci_size_t size)
@@ -127,8 +131,33 @@ static int rockchip_pcie_rd_conf(const s
 	}
 
 	if ((bus == priv->first_busno + 1) && dev == 0) {
+		writel((bus << 20) | PCIE_ATR_REGION0_PASS_BITS,
+		       priv->apb_base + PCIE_ATR_OB_ADDR0(0));
+		writel(PCIE_ATR_HDR_CFG_TYPE0 | PCIE_ATR_HDR_RID,
+		       priv->apb_base + PCIE_ATR_OB_DESC0(0));
+		dsb();
 		value = readl(priv->axi_base + where);
 		*valuep = pci_conv_32_to_size(value, offset, size);
+		dsb();
+		return 0;
+	}
+
+	if (bus > priv->first_busno + 1) {
+		writel((bus << 20) | PCIE_ATR_REGION0_PASS_BITS,
+		       priv->apb_base + PCIE_ATR_OB_ADDR0(0));
+		writel(PCIE_ATR_HDR_CFG_TYPE1 | PCIE_ATR_HDR_RID,
+		       priv->apb_base + PCIE_ATR_OB_DESC0(0));
+		dsb();
+		rockchip_pcie_got_data_abort = 0;
+		rockchip_pcie_expect_data_abort = 1;
+		value = readl(priv->axi_base + where);
+		rockchip_pcie_expect_data_abort = 0;
+		if (rockchip_pcie_got_data_abort) {
+			*valuep = pci_get_ff(size);
+			return 0;
+		}
+		*valuep = pci_conv_32_to_size(value, offset, size);
+		dsb();
 		return 0;
 	}
 
@@ -155,9 +184,28 @@ static int rockchip_pcie_wr_conf(struct 
 	}
 
 	if ((bus == priv->first_busno + 1) && dev == 0) {
+		writel((bus << 20) | PCIE_ATR_REGION0_PASS_BITS,
+		       priv->apb_base + PCIE_ATR_OB_ADDR0(0));
+		writel(PCIE_ATR_HDR_CFG_TYPE0 | PCIE_ATR_HDR_RID,
+		       priv->apb_base + PCIE_ATR_OB_DESC0(0));
+		dsb();
 		old = readl(priv->axi_base + where);
 		value = pci_conv_size_to_32(old, value, offset, size);
 		writel(value, priv->axi_base + where);
+		dsb();
+		return 0;
+	}
+
+	if (bus > priv->first_busno + 1) {
+		writel((bus << 20) | PCIE_ATR_REGION0_PASS_BITS,
+		       priv->apb_base + PCIE_ATR_OB_ADDR0(0));
+		writel(PCIE_ATR_HDR_CFG_TYPE1 | PCIE_ATR_HDR_RID,
+		       priv->apb_base + PCIE_ATR_OB_DESC0(0));
+		dsb();
+		old = readl(priv->axi_base + where);
+		value = pci_conv_size_to_32(old, value, offset, size);
+		writel(value, priv->axi_base + where);
+		dsb();
 		return 0;
 	}
 
@@ -173,7 +221,7 @@ static int rockchip_pcie_atr_init(struct
 	int i, region;
 
 	/* Use region 0 to map PCI configuration space. */
-	writel(25 - 1, priv->apb_base + PCIE_ATR_OB_ADDR0(0));
+	writel(PCIE_ATR_REGION0_PASS_BITS, priv->apb_base + PCIE_ATR_OB_ADDR0(0));
 	writel(0, priv->apb_base + PCIE_ATR_OB_ADDR1(0));
 	writel(PCIE_ATR_HDR_CFG_TYPE0 | PCIE_ATR_HDR_RID,
 	       priv->apb_base + PCIE_ATR_OB_DESC0(0));
@@ -343,6 +391,8 @@ static int rockchip_pcie_init_port(struc
 		goto err_power_off_phy;
 	}
 
+	mdelay(20);	/* 20 ms according to PCI-e BS "Conventional Reset" */
+
 	/* Enable Gen1 training */
 	writel(PCIE_CLIENT_LINK_TRAIN_ENABLE,
 	       priv->apb_base + PCIE_CLIENT_CONFIG);
@@ -378,6 +428,8 @@ static int rockchip_pcie_init_port(struc
 		goto err_power_off_phy;
 	}
 
+	mdelay(80);   /* wait 100 ms before CSR accesses. Already waited 20. */
+
 	return 0;
 
 err_power_off_phy:
