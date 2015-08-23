$NetBSD: patch-qemu-xen-traditional_hw_pass-through.c,v 1.2 2015/08/23 16:17:12 spz Exp $

patch for CVE-2015-2756 aka XSA-126 from
http://xenbits.xenproject.org/xsa/xsa126-qemut.patch

patch for CVE-2015-4103 aka XSA-128 from
http://xenbits.xen.org/xsa/xsa128-qemut.patch

patch for CVE-2015-4104 aka XSA-129 from
http://xenbits.xen.org/xsa/xsa129-qemut.patch

patch for CVE-2015-4106 aka XSA-131 from
http://xenbits.xen.org/xsa/xsa131-qemut-4.2-1.patch
http://xenbits.xen.org/xsa/xsa131-qemut-2.patch
http://xenbits.xen.org/xsa/xsa131-qemut-3.patch
http://xenbits.xen.org/xsa/xsa131-qemut-4.patch
http://xenbits.xen.org/xsa/xsa131-qemut-5.patch
http://xenbits.xen.org/xsa/xsa131-qemut-6.patch
http://xenbits.xen.org/xsa/xsa131-qemut-7.patch
http://xenbits.xen.org/xsa/xsa131-qemut-8.patch

avoid duplicate inclusion of pci/header.h and pci/pci.h (also in pass-through.h)

--- qemu-xen-traditional/hw/pass-through.c.orig	2014-01-09 12:44:42.000000000 +0000
+++ qemu-xen-traditional/hw/pass-through.c
@@ -84,8 +84,6 @@
  */
 
 #include "pass-through.h"
-#include "pci/header.h"
-#include "pci/pci.h"
 #include "pt-msi.h"
 #include "qemu-xen.h"
 #include "iomulti.h"
@@ -147,6 +145,10 @@ static uint32_t pt_msgaddr64_reg_init(st
     struct pt_reg_info_tbl *reg, uint32_t real_offset);
 static uint32_t pt_msgdata_reg_init(struct pt_dev *ptdev,
     struct pt_reg_info_tbl *reg, uint32_t real_offset);
+static uint32_t pt_mask_reg_init(struct pt_dev *ptdev,
+    struct pt_reg_info_tbl *reg, uint32_t real_offset);
+static uint32_t pt_pending_reg_init(struct pt_dev *ptdev,
+    struct pt_reg_info_tbl *reg, uint32_t real_offset);
 static uint32_t pt_msixctrl_reg_init(struct pt_dev *ptdev,
     struct pt_reg_info_tbl *reg, uint32_t real_offset);
 static uint32_t pt_header_type_reg_init(struct pt_dev *ptdev,
@@ -178,9 +180,6 @@ static int pt_cmd_reg_read(struct pt_dev
 static int pt_bar_reg_read(struct pt_dev *ptdev,
     struct pt_reg_tbl *cfg_entry,
     uint32_t *value, uint32_t valid_mask);
-static int pt_pmcsr_reg_read(struct pt_dev *ptdev,
-    struct pt_reg_tbl *cfg_entry,
-    uint16_t *value, uint16_t valid_mask);
 static int pt_byte_reg_write(struct pt_dev *ptdev,
     struct pt_reg_tbl *cfg_entry,
     uint8_t *value, uint8_t dev_value, uint8_t valid_mask);
@@ -285,7 +284,7 @@ static struct pt_reg_info_tbl pt_emu_reg
         .offset     = PCI_COMMAND,
         .size       = 2,
         .init_val   = 0x0000,
-        .ro_mask    = 0xF880,
+        .res_mask   = 0xF880,
         .emu_mask   = 0x0740,
         .init       = pt_common_reg_init,
         .u.w.read   = pt_cmd_reg_read,
@@ -312,7 +311,8 @@ static struct pt_reg_info_tbl pt_emu_reg
         .offset     = PCI_STATUS,
         .size       = 2,
         .init_val   = 0x0000,
-        .ro_mask    = 0x06FF,
+        .res_mask   = 0x0007,
+        .ro_mask    = 0x06F8,
         .emu_mask   = 0x0010,
         .init       = pt_status_reg_init,
         .u.w.read   = pt_word_reg_read,
@@ -457,7 +457,7 @@ static struct pt_reg_info_tbl pt_emu_reg
         .offset     = PCI_INTEL_OPREGION,
         .size       = 4,
         .init_val   = 0,
-        .no_wb      = 1,
+        .emu_mask   = 0xFFFFFFFF,
         .u.dw.read   = pt_intel_opregion_read,
         .u.dw.write  = pt_intel_opregion_write,
         .u.dw.restore  = NULL,
@@ -493,15 +493,29 @@ static struct pt_reg_info_tbl pt_emu_reg
         .u.w.write  = pt_word_reg_write,
         .u.w.restore  = NULL,
     },
-    /* PCI Power Management Control/Status reg */
+    /* PCI Power Management Control/Status reg (->power_mgmt on) */
     {
         .offset     = PCI_PM_CTRL,
         .size       = 2,
         .init_val   = 0x0008,
-        .ro_mask    = 0xE1FC,
+        .res_mask   = 0x00F0,
+        .ro_mask    = 0xE10C,
         .emu_mask   = 0x8100,
         .init       = pt_pmcsr_reg_init,
-        .u.w.read   = pt_pmcsr_reg_read,
+        .u.w.read   = pt_word_reg_read,
+        .u.w.write  = pt_pmcsr_reg_write,
+        .u.w.restore  = pt_pmcsr_reg_restore,
+    },
+    /* PCI Power Management Control/Status reg (->power_mgmt off) */
+    {
+        .offset     = PCI_PM_CTRL,
+        .size       = 2,
+        .init_val   = 0x0008,
+        .res_mask   = 0x00F0,
+        .ro_mask    = 0xE10C,
+        .emu_mask   = 0x810B,
+        .init       = pt_pmcsr_reg_init,
+        .u.w.read   = pt_word_reg_read,
         .u.w.write  = pt_pmcsr_reg_write,
         .u.w.restore  = pt_pmcsr_reg_restore,
     },
@@ -525,6 +539,16 @@ static struct pt_reg_info_tbl pt_emu_reg
         .u.b.restore  = NULL,
     },
     {
+        .offset     = PCI_VPD_ADDR,
+        .size       = 2,
+        .ro_mask    = 0x0003,
+        .emu_mask   = 0x0003,
+        .init       = pt_common_reg_init,
+        .u.w.read   = pt_word_reg_read,
+        .u.w.write  = pt_word_reg_write,
+        .u.w.restore = pt_word_reg_restore,
+    },
+    {
         .size = 0,
     },
 };
@@ -567,7 +591,7 @@ static struct pt_reg_info_tbl pt_emu_reg
         .offset     = PCI_EXP_DEVCAP,
         .size       = 4,
         .init_val   = 0x00000000,
-        .ro_mask    = 0x1FFCFFFF,
+        .ro_mask    = 0xFFFFFFFF,
         .emu_mask   = 0x10000000,
         .init       = pt_common_reg_init,
         .u.dw.read  = pt_long_reg_read,
@@ -586,6 +610,17 @@ static struct pt_reg_info_tbl pt_emu_reg
         .u.w.write  = pt_word_reg_write,
         .u.w.restore  = pt_word_reg_restore,
     },
+    /* Device Status reg */
+    {
+        .offset     = PCI_EXP_DEVSTA,
+        .size       = 2,
+        .res_mask   = 0xFFC0,
+        .ro_mask    = 0x0030,
+        .init       = pt_common_reg_init,
+        .u.w.read   = pt_word_reg_read,
+        .u.w.write  = pt_word_reg_write,
+        .u.w.restore  = pt_word_reg_restore,
+    },
     /* Link Control reg */
     {
         .offset     = PCI_EXP_LNKCTL,
@@ -598,6 +633,16 @@ static struct pt_reg_info_tbl pt_emu_reg
         .u.w.write  = pt_word_reg_write,
         .u.w.restore  = pt_word_reg_restore,
     },
+    /* Link Status reg */
+    {
+        .offset     = PCI_EXP_LNKSTA,
+        .size       = 2,
+        .ro_mask    = 0x3FFF,
+        .init       = pt_common_reg_init,
+        .u.w.read   = pt_word_reg_read,
+        .u.w.write  = pt_word_reg_write,
+        .u.w.restore = pt_word_reg_restore,
+    },
     /* Device Control 2 reg */
     {
         .offset     = 0x28,
@@ -646,8 +691,9 @@ static struct pt_reg_info_tbl pt_emu_reg
         .offset     = PCI_MSI_FLAGS, // 2
         .size       = 2,
         .init_val   = 0x0000,
-        .ro_mask    = 0xFF8E,
-        .emu_mask   = 0x007F,
+        .res_mask   = 0xFE00,
+        .ro_mask    = 0x018E,
+        .emu_mask   = 0x017E,
         .init       = pt_msgctrl_reg_init,
         .u.w.read   = pt_word_reg_read,
         .u.w.write  = pt_msgctrl_reg_write,
@@ -660,7 +706,6 @@ static struct pt_reg_info_tbl pt_emu_reg
         .init_val   = 0x00000000,
         .ro_mask    = 0x00000003,
         .emu_mask   = 0xFFFFFFFF,
-        .no_wb      = 1,
         .init       = pt_common_reg_init,
         .u.dw.read  = pt_long_reg_read,
         .u.dw.write = pt_msgaddr32_reg_write,
@@ -673,7 +718,6 @@ static struct pt_reg_info_tbl pt_emu_reg
         .init_val   = 0x00000000,
         .ro_mask    = 0x00000000,
         .emu_mask   = 0xFFFFFFFF,
-        .no_wb      = 1,
         .init       = pt_msgaddr64_reg_init,
         .u.dw.read  = pt_long_reg_read,
         .u.dw.write = pt_msgaddr64_reg_write,
@@ -686,7 +730,6 @@ static struct pt_reg_info_tbl pt_emu_reg
         .init_val   = 0x0000,
         .ro_mask    = 0x0000,
         .emu_mask   = 0xFFFF,
-        .no_wb      = 1,
         .init       = pt_msgdata_reg_init,
         .u.w.read   = pt_word_reg_read,
         .u.w.write  = pt_msgdata_reg_write,
@@ -699,12 +742,55 @@ static struct pt_reg_info_tbl pt_emu_reg
         .init_val   = 0x0000,
         .ro_mask    = 0x0000,
         .emu_mask   = 0xFFFF,
-        .no_wb      = 1,
         .init       = pt_msgdata_reg_init,
         .u.w.read   = pt_word_reg_read,
         .u.w.write  = pt_msgdata_reg_write,
         .u.w.restore  = NULL,
     },
+    /* Mask reg (if PCI_MSI_FLAGS_MASK_BIT set, for 32-bit devices) */
+    {
+        .offset     = PCI_MSI_MASK_32,
+        .size       = 4,
+        .init_val   = 0x00000000,
+        .ro_mask    = 0xFFFFFFFF,
+        .emu_mask   = 0xFFFFFFFF,
+        .init       = pt_mask_reg_init,
+        .u.dw.read  = pt_long_reg_read,
+        .u.dw.write = pt_long_reg_write,
+    },
+    /* Mask reg (if PCI_MSI_FLAGS_MASK_BIT set, for 64-bit devices) */
+    {
+        .offset     = PCI_MSI_MASK_64,
+        .size       = 4,
+        .init_val   = 0x00000000,
+        .ro_mask    = 0xFFFFFFFF,
+        .emu_mask   = 0xFFFFFFFF,
+        .init       = pt_mask_reg_init,
+        .u.dw.read  = pt_long_reg_read,
+        .u.dw.write = pt_long_reg_write,
+    },
+    /* Pending reg (if PCI_MSI_FLAGS_MASK_BIT set, for 32-bit devices) */
+    {
+        .offset     = PCI_MSI_MASK_32 + 4,
+        .size       = 4,
+        .init_val   = 0x00000000,
+        .ro_mask    = 0xFFFFFFFF,
+        .emu_mask   = 0x00000000,
+        .init       = pt_pending_reg_init,
+        .u.dw.read  = pt_long_reg_read,
+        .u.dw.write = pt_long_reg_write,
+    },
+    /* Pending reg (if PCI_MSI_FLAGS_MASK_BIT set, for 64-bit devices) */
+    {
+        .offset     = PCI_MSI_MASK_64 + 4,
+        .size       = 4,
+        .init_val   = 0x00000000,
+        .ro_mask    = 0xFFFFFFFF,
+        .emu_mask   = 0x00000000,
+        .init       = pt_pending_reg_init,
+        .u.dw.read  = pt_long_reg_read,
+        .u.dw.write = pt_long_reg_write,
+    },
     {
         .size = 0,
     },
@@ -729,7 +815,8 @@ static struct pt_reg_info_tbl pt_emu_reg
         .offset     = PCI_MSI_FLAGS, // 2
         .size       = 2,
         .init_val   = 0x0000,
-        .ro_mask    = 0x3FFF,
+        .res_mask   = 0x3800,
+        .ro_mask    = 0x07FF,
         .emu_mask   = 0x0000,
         .init       = pt_msixctrl_reg_init,
         .u.w.read   = pt_word_reg_read,
@@ -1527,10 +1614,10 @@ static void pt_pci_write_config(PCIDevic
     uint32_t find_addr = address;
     uint32_t real_offset = 0;
     uint32_t valid_mask = 0xFFFFFFFF;
-    uint32_t read_val = 0;
+    uint32_t read_val = 0, wb_mask, wp_mask;
     uint8_t *ptr_val = NULL;
     int emul_len = 0;
-    int index = 0;
+    int index = 0, wp_flag = 0;
     int ret = 0;
 
 #ifdef PT_DEBUG_PCI_CONFIG_ACCESS
@@ -1600,11 +1687,21 @@ static void pt_pci_write_config(PCIDevic
     {
         PT_LOG("Error: pci_read_block failed. return value[%d].\n", ret);
         memset((uint8_t *)&read_val, 0xff, len);
+        wb_mask = 0;
     }
+    else
+        wb_mask = 0xFFFFFFFF >> ((4 - len) << 3);
 
     /* pass directly to libpci for passthrough type register group */
     if (reg_grp_entry == NULL)
+    {
+        if (!assigned_device->permissive)
+        {
+            wb_mask = 0;
+            wp_flag = 1;
+        }
         goto out;
+    }
 
     /* adjust the read and write value to appropriate CFC-CFF window */
     read_val <<= ((address & 3) << 3);
@@ -1623,6 +1720,12 @@ static void pt_pci_write_config(PCIDevic
             valid_mask = (0xFFFFFFFF >> ((4 - emul_len) << 3));
             valid_mask <<= ((find_addr - real_offset) << 3);
             ptr_val = ((uint8_t *)&val + (real_offset & 3));
+            wp_mask = reg->emu_mask | reg->ro_mask;
+            if (!assigned_device->permissive)
+                wp_mask |= reg->res_mask;
+            if (wp_mask == (0xFFFFFFFF >> ((4 - reg->size) << 3)))
+                wb_mask &= ~((wp_mask >> ((find_addr - real_offset) << 3))
+                             << ((len - emul_len) << 3));
 
             /* do emulation depend on register size */
             switch (reg->size) {
@@ -1671,6 +1774,16 @@ static void pt_pci_write_config(PCIDevic
             /* nothing to do with passthrough type register,
              * continue to find next byte
              */
+            if (!assigned_device->permissive)
+            {
+                wb_mask &= ~(0xff << ((len - emul_len) << 3));
+                /* Unused BARs will make it here, but we don't want to issue
+                 * warnings for writes to them (bogus writes get dealt with
+                 * above).
+                 */
+                if (index < 0)
+                    wp_flag = 1;
+            }
             emul_len--;
             find_addr++;
         }
@@ -1680,8 +1793,28 @@ static void pt_pci_write_config(PCIDevic
     val >>= ((address & 3) << 3);
 
 out:
-    if (!(reg && reg->no_wb)) {  /* unknown regs are passed through */
-        ret = pci_write_block(pci_dev, address, (uint8_t *)&val, len);
+    if (wp_flag && !assigned_device->permissive_warned)
+    {
+        assigned_device->permissive_warned = 1;
+        PT_LOG("Write-back to unknown field 0x%02x (partially) inhibited (0x%0*x)\n",
+               addr, len * 2, wb_mask);
+        PT_LOG("If device %02x:%02x.%o doesn't work, try enabling permissive\n",
+               pci_bus_num(d->bus), PCI_SLOT(d->devfn), PCI_FUNC(d->devfn));
+        PT_LOG("mode (unsafe) and if it helps report the problem to xen-devel\n");
+    }
+    for (index = 0; wb_mask; index += len) {
+        /* unknown regs are passed through */
+        while (!(wb_mask & 0xff)) {
+            index++;
+            wb_mask >>= 8;
+        }
+        len = 0;
+        do {
+            len++;
+            wb_mask >>= 8;
+        } while (wb_mask & 0xff);
+        ret = pci_write_block(pci_dev, address + index,
+                              (uint8_t *)&val + index, len);
 
         if (!ret)
             PT_LOG("Error: pci_write_block failed. return value[%d].\n", ret);
@@ -2848,6 +2981,7 @@ static uint32_t pt_pmc_reg_init(struct p
     return reg->init_val;
 }
 
+/* this function will be called twice (for ->power_mgmt on and off cases) */
 /* initialize PCI Power Management Control/Status register */
 static uint32_t pt_pmcsr_reg_init(struct pt_dev *ptdev,
         struct pt_reg_info_tbl *reg, uint32_t real_offset)
@@ -2855,8 +2989,23 @@ static uint32_t pt_pmcsr_reg_init(struct
     PCIDevice *d = &ptdev->dev;
     uint16_t cap_ver  = 0;
 
-    if (!ptdev->power_mgmt)
-        return reg->init_val;
+    switch (reg->emu_mask & (PCI_PM_CTRL_STATE_MASK |
+                             PCI_PM_CTRL_NO_SOFT_RESET))
+    {
+    case 0:
+        if (!ptdev->power_mgmt)
+            return PT_INVALID_REG;
+        break;
+    case PCI_PM_CTRL_STATE_MASK | PCI_PM_CTRL_NO_SOFT_RESET:
+        if (!ptdev->power_mgmt)
+            return reg->init_val;
+        return PT_INVALID_REG;
+    default:
+        /* exit I/O emulator */
+        PT_LOG("Internal error: Invalid PMCSR emulation mask %04x."
+               " I/O emulator exit.\n", reg->emu_mask);
+        exit(1);
+    }
 
     /* check PCI Power Management support version */
     cap_ver = ptdev->pm_state->pmc_field & PCI_PM_CAP_VER_MASK;
@@ -3000,6 +3149,42 @@ static uint32_t pt_msgdata_reg_init(stru
         return PT_INVALID_REG;
 }
 
+/* this function will be called twice (for 32 bit and 64 bit type) */
+/* initialize Mask register */
+static uint32_t pt_mask_reg_init(struct pt_dev *ptdev,
+        struct pt_reg_info_tbl *reg, uint32_t real_offset)
+{
+    uint32_t flags = ptdev->msi->flags;
+    uint32_t offset = reg->offset;
+
+    if (!(flags & PCI_MSI_FLAGS_MASK_BIT))
+        return PT_INVALID_REG;
+
+    if (offset == (flags & PCI_MSI_FLAGS_64BIT ?
+                   PCI_MSI_MASK_64 : PCI_MSI_MASK_32))
+        return reg->init_val;
+
+    return PT_INVALID_REG;
+}
+
+/* this function will be called twice (for 32 bit and 64 bit type) */
+/* initialize Pending register */
+static uint32_t pt_pending_reg_init(struct pt_dev *ptdev,
+        struct pt_reg_info_tbl *reg, uint32_t real_offset)
+{
+    uint32_t flags = ptdev->msi->flags;
+    uint32_t offset = reg->offset;
+
+    if (!(flags & PCI_MSI_FLAGS_MASK_BIT))
+        return PT_INVALID_REG;
+
+    if (offset == (flags & PCI_MSI_FLAGS_64BIT ?
+                   PCI_MSI_MASK_64 + 4 : PCI_MSI_MASK_32 + 4))
+        return reg->init_val;
+
+    return PT_INVALID_REG;
+}
+
 /* initialize Message Control register for MSI-X */
 static uint32_t pt_msixctrl_reg_init(struct pt_dev *ptdev,
         struct pt_reg_info_tbl *reg, uint32_t real_offset)
@@ -3331,24 +3516,18 @@ static int pt_bar_reg_read(struct pt_dev
 }
 
 
-/* read Power Management Control/Status register */
-static int pt_pmcsr_reg_read(struct pt_dev *ptdev,
-        struct pt_reg_tbl *cfg_entry,
-        uint16_t *value, uint16_t valid_mask)
+static uint32_t get_throughable_mask(const struct pt_dev *ptdev,
+                                     const struct pt_reg_info_tbl *reg,
+                                     uint32_t valid_mask)
 {
-    struct pt_reg_info_tbl *reg = cfg_entry->reg;
-    uint16_t valid_emu_mask = reg->emu_mask;
-
-    if (!ptdev->power_mgmt)
-        valid_emu_mask |= PCI_PM_CTRL_STATE_MASK | PCI_PM_CTRL_NO_SOFT_RESET;
+    uint32_t throughable_mask = ~(reg->emu_mask | reg->ro_mask);
 
-    valid_emu_mask = valid_emu_mask & valid_mask ;
-    *value = PT_MERGE_VALUE(*value, cfg_entry->data, ~valid_emu_mask);
+    if (!ptdev->permissive)
+        throughable_mask &= ~reg->res_mask;
 
-    return 0;
+    return throughable_mask & valid_mask;
 }
 
-
 /* write byte size emulate register */
 static int pt_byte_reg_write(struct pt_dev *ptdev,
         struct pt_reg_tbl *cfg_entry,
@@ -3356,14 +3535,13 @@ static int pt_byte_reg_write(struct pt_d
 {
     struct pt_reg_info_tbl *reg = cfg_entry->reg;
     uint8_t writable_mask = 0;
-    uint8_t throughable_mask = 0;
+    uint8_t throughable_mask = get_throughable_mask(ptdev, reg, valid_mask);
 
     /* modify emulate register */
     writable_mask = reg->emu_mask & ~reg->ro_mask & valid_mask;
     cfg_entry->data = PT_MERGE_VALUE(*value, cfg_entry->data, writable_mask);
 
     /* create value for writing to I/O device register */
-    throughable_mask = ~reg->emu_mask & valid_mask;
     *value = PT_MERGE_VALUE(*value, dev_value, throughable_mask);
 
     return 0;
@@ -3376,14 +3554,13 @@ static int pt_word_reg_write(struct pt_d
 {
     struct pt_reg_info_tbl *reg = cfg_entry->reg;
     uint16_t writable_mask = 0;
-    uint16_t throughable_mask = 0;
+    uint16_t throughable_mask = get_throughable_mask(ptdev, reg, valid_mask);
 
     /* modify emulate register */
     writable_mask = reg->emu_mask & ~reg->ro_mask & valid_mask;
     cfg_entry->data = PT_MERGE_VALUE(*value, cfg_entry->data, writable_mask);
 
     /* create value for writing to I/O device register */
-    throughable_mask = ~reg->emu_mask & valid_mask;
     *value = PT_MERGE_VALUE(*value, dev_value, throughable_mask);
 
     return 0;
@@ -3396,14 +3573,13 @@ static int pt_long_reg_write(struct pt_d
 {
     struct pt_reg_info_tbl *reg = cfg_entry->reg;
     uint32_t writable_mask = 0;
-    uint32_t throughable_mask = 0;
+    uint32_t throughable_mask = get_throughable_mask(ptdev, reg, valid_mask);
 
     /* modify emulate register */
     writable_mask = reg->emu_mask & ~reg->ro_mask & valid_mask;
     cfg_entry->data = PT_MERGE_VALUE(*value, cfg_entry->data, writable_mask);
 
     /* create value for writing to I/O device register */
-    throughable_mask = ~reg->emu_mask & valid_mask;
     *value = PT_MERGE_VALUE(*value, dev_value, throughable_mask);
 
     return 0;
@@ -3416,7 +3592,7 @@ static int pt_cmd_reg_write(struct pt_de
 {
     struct pt_reg_info_tbl *reg = cfg_entry->reg;
     uint16_t writable_mask = 0;
-    uint16_t throughable_mask = 0;
+    uint16_t throughable_mask = get_throughable_mask(ptdev, reg, valid_mask);
     uint16_t wr_value = *value;
     uint16_t emu_mask = reg->emu_mask;
 
@@ -3430,8 +3606,6 @@ static int pt_cmd_reg_write(struct pt_de
     cfg_entry->data = PT_MERGE_VALUE(*value, cfg_entry->data, writable_mask);
 
     /* create value for writing to I/O device register */
-    throughable_mask = ~emu_mask & valid_mask;
-
     if (*value & PCI_COMMAND_DISABLE_INTx)
     {
         if (ptdev->msi_trans_en)
@@ -3477,7 +3651,6 @@ static int pt_bar_reg_write(struct pt_de
     PCIDevice *d = (PCIDevice *)&ptdev->dev;
     PCIIORegion *r;
     uint32_t writable_mask = 0;
-    uint32_t throughable_mask = 0;
     uint32_t bar_emu_mask = 0;
     uint32_t bar_ro_mask = 0;
     uint32_t new_addr, last_addr;
@@ -3604,8 +3777,7 @@ static int pt_bar_reg_write(struct pt_de
 
 exit:
     /* create value for writing to I/O device register */
-    throughable_mask = ~bar_emu_mask & valid_mask;
-    *value = PT_MERGE_VALUE(*value, dev_value, throughable_mask);
+    *value = PT_MERGE_VALUE(*value, dev_value, 0);
 
     /* After BAR reg update, we need to remap BAR*/
     reg_grp_entry = pt_find_reg_grp(ptdev, PCI_COMMAND);
@@ -3632,9 +3804,8 @@ static int pt_exp_rom_bar_reg_write(stru
     PCIDevice *d = (PCIDevice *)&ptdev->dev;
     PCIIORegion *r;
     uint32_t writable_mask = 0;
-    uint32_t throughable_mask = 0;
+    uint32_t throughable_mask = get_throughable_mask(ptdev, reg, valid_mask);
     uint32_t r_size = 0;
-    uint32_t bar_emu_mask = 0;
     uint32_t bar_ro_mask = 0;
 
     r = &d->io_regions[PCI_ROM_SLOT];
@@ -3644,7 +3815,6 @@ static int pt_exp_rom_bar_reg_write(stru
     PT_GET_EMUL_SIZE(base->bar_flag, r_size);
 
     /* set emulate mask and read-only mask */
-    bar_emu_mask = reg->emu_mask;
     bar_ro_mask = (reg->ro_mask | (r_size - 1)) & ~PCI_ROM_ADDRESS_ENABLE;
 
     /* modify emulate register */
@@ -3664,7 +3834,6 @@ static int pt_exp_rom_bar_reg_write(stru
         r->addr = cfg_entry->data;
 
     /* create value for writing to I/O device register */
-    throughable_mask = ~bar_emu_mask & valid_mask;
     *value = PT_MERGE_VALUE(*value, dev_value, throughable_mask);
 
     /* After BAR reg update, we need to remap BAR*/
@@ -3688,22 +3857,18 @@ static int pt_pmcsr_reg_write(struct pt_
 {
     struct pt_reg_info_tbl *reg = cfg_entry->reg;
     PCIDevice *d = &ptdev->dev;
-    uint16_t emu_mask = reg->emu_mask;
     uint16_t writable_mask = 0;
-    uint16_t throughable_mask = 0;
+    uint16_t throughable_mask = get_throughable_mask(ptdev, reg, valid_mask);
     struct pt_pm_info *pm_state = ptdev->pm_state;
     uint16_t read_val = 0;
 
-    if (!ptdev->power_mgmt)
-        emu_mask |= PCI_PM_CTRL_STATE_MASK | PCI_PM_CTRL_NO_SOFT_RESET;
-
     /* modify emulate register */
-    writable_mask = emu_mask & ~reg->ro_mask & valid_mask;
+    writable_mask = reg->emu_mask & ~reg->ro_mask & valid_mask;
     cfg_entry->data = PT_MERGE_VALUE(*value, cfg_entry->data, writable_mask);
 
     /* create value for writing to I/O device register */
-    throughable_mask = ~emu_mask & valid_mask;
-    *value = PT_MERGE_VALUE(*value, dev_value, throughable_mask);
+    *value = PT_MERGE_VALUE(*value, dev_value & ~PCI_PM_CTRL_PME_STATUS,
+                            throughable_mask);
 
     if (!ptdev->power_mgmt)
         return 0;
@@ -3810,7 +3975,7 @@ static int pt_msgctrl_reg_write(struct p
 {
     struct pt_reg_info_tbl *reg = cfg_entry->reg;
     uint16_t writable_mask = 0;
-    uint16_t throughable_mask = 0;
+    uint16_t throughable_mask = get_throughable_mask(ptdev, reg, valid_mask);
     uint16_t old_ctrl = cfg_entry->data;
     PCIDevice *pd = (PCIDevice *)ptdev;
     uint16_t val;
@@ -3821,6 +3986,11 @@ static int pt_msgctrl_reg_write(struct p
 
     /* modify emulate register */
     writable_mask = reg->emu_mask & ~reg->ro_mask & valid_mask;
+    /* also emulate MSI_ENABLE bit for MSI-INTx translation */
+    if (ptdev->msi_trans_en) {
+        writable_mask |= PCI_MSI_FLAGS_ENABLE & valid_mask;
+        throughable_mask &= ~PCI_MSI_FLAGS_ENABLE;
+    }
     cfg_entry->data = PT_MERGE_VALUE(*value, cfg_entry->data, writable_mask);
     /* update the msi_info too */
     ptdev->msi->flags |= cfg_entry->data &
@@ -3828,7 +3998,6 @@ static int pt_msgctrl_reg_write(struct p
 
     /* create value for writing to I/O device register */
     val = *value;
-    throughable_mask = ~reg->emu_mask & valid_mask;
     *value = PT_MERGE_VALUE(*value, dev_value, throughable_mask);
 
     /* update MSI */
@@ -3868,12 +4037,6 @@ static int pt_msgctrl_reg_write(struct p
     else
         ptdev->msi->flags &= ~PCI_MSI_FLAGS_ENABLE;
 
-    /* pass through MSI_ENABLE bit when no MSI-INTx translation */
-    if (!ptdev->msi_trans_en) {
-        *value &= ~PCI_MSI_FLAGS_ENABLE;
-        *value |= val & PCI_MSI_FLAGS_ENABLE;
-    }
-
     return 0;
 }
 
@@ -3884,7 +4047,6 @@ static int pt_msgaddr32_reg_write(struct
 {
     struct pt_reg_info_tbl *reg = cfg_entry->reg;
     uint32_t writable_mask = 0;
-    uint32_t throughable_mask = 0;
     uint32_t old_addr = cfg_entry->data;
 
     /* modify emulate register */
@@ -3894,8 +4056,7 @@ static int pt_msgaddr32_reg_write(struct
     ptdev->msi->addr_lo = cfg_entry->data;
 
     /* create value for writing to I/O device register */
-    throughable_mask = ~reg->emu_mask & valid_mask;
-    *value = PT_MERGE_VALUE(*value, dev_value, throughable_mask);
+    *value = PT_MERGE_VALUE(*value, dev_value, 0);
 
     /* update MSI */
     if (cfg_entry->data != old_addr)
@@ -3914,7 +4075,6 @@ static int pt_msgaddr64_reg_write(struct
 {
     struct pt_reg_info_tbl *reg = cfg_entry->reg;
     uint32_t writable_mask = 0;
-    uint32_t throughable_mask = 0;
     uint32_t old_addr = cfg_entry->data;
 
     /* check whether the type is 64 bit or not */
@@ -3932,8 +4092,7 @@ static int pt_msgaddr64_reg_write(struct
     ptdev->msi->addr_hi = cfg_entry->data;
 
     /* create value for writing to I/O device register */
-    throughable_mask = ~reg->emu_mask & valid_mask;
-    *value = PT_MERGE_VALUE(*value, dev_value, throughable_mask);
+    *value = PT_MERGE_VALUE(*value, dev_value, 0);
 
     /* update MSI */
     if (cfg_entry->data != old_addr)
@@ -3953,7 +4112,6 @@ static int pt_msgdata_reg_write(struct p
 {
     struct pt_reg_info_tbl *reg = cfg_entry->reg;
     uint16_t writable_mask = 0;
-    uint16_t throughable_mask = 0;
     uint16_t old_data = cfg_entry->data;
     uint32_t flags = ptdev->msi->flags;
     uint32_t offset = reg->offset;
@@ -3974,8 +4132,7 @@ static int pt_msgdata_reg_write(struct p
     ptdev->msi->data = cfg_entry->data;
 
     /* create value for writing to I/O device register */
-    throughable_mask = ~reg->emu_mask & valid_mask;
-    *value = PT_MERGE_VALUE(*value, dev_value, throughable_mask);
+    *value = PT_MERGE_VALUE(*value, dev_value, 0);
 
     /* update MSI */
     if (cfg_entry->data != old_data)
@@ -3994,7 +4151,7 @@ static int pt_msixctrl_reg_write(struct 
 {
     struct pt_reg_info_tbl *reg = cfg_entry->reg;
     uint16_t writable_mask = 0;
-    uint16_t throughable_mask = 0;
+    uint16_t throughable_mask = get_throughable_mask(ptdev, reg, valid_mask);
     uint16_t old_ctrl = cfg_entry->data;
 
     /* modify emulate register */
@@ -4002,7 +4159,6 @@ static int pt_msixctrl_reg_write(struct 
     cfg_entry->data = PT_MERGE_VALUE(*value, cfg_entry->data, writable_mask);
 
     /* create value for writing to I/O device register */
-    throughable_mask = ~reg->emu_mask & valid_mask;
     *value = PT_MERGE_VALUE(*value, dev_value, throughable_mask);
 
     /* update MSI-X */
@@ -4206,7 +4362,7 @@ static struct pt_dev * register_real_dev
     struct pci_dev *pci_dev;
     uint8_t e_device, e_intx;
     char *key, *val;
-    int msi_translate, power_mgmt;
+    int msi_translate, power_mgmt, permissive = 0;
 
     PT_LOG("Assigning real physical device %02x:%02x.%x ...\n",
         r_bus, r_dev, r_func);
@@ -4250,6 +4406,8 @@ static struct pt_dev * register_real_dev
             else
                 PT_LOG("Error: unrecognized value for msitranslate=\n");
         }
+        else if (strcmp(key, "permissive") == 0)
+            permissive = 1;
         else if (strcmp(key, "power_mgmt") == 0)
         {
             if (strcmp(val, "0") == 0)
@@ -4287,6 +4445,7 @@ static struct pt_dev * register_real_dev
     assigned_device->msi_trans_cap = msi_translate;
     assigned_device->power_mgmt = power_mgmt;
     assigned_device->is_virtfn = pt_dev_is_virtfn(pci_dev);
+    assigned_device->permissive = permissive;
     pt_iomul_init(assigned_device, r_bus, r_dev, r_func);
 
     /* Initialize virtualized PCI configuration (Extended 256 Bytes) */
