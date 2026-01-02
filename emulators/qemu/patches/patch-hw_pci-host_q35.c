$NetBSD: patch-hw_pci-host_q35.c,v 1.1 2026/01/02 05:16:24 riastradh Exp $

Work around black screen in VGA mode with SMM disabled, as required by,
e.g., NVMM:

https://gnats.NetBSD.org/59721
https://gitlab.com/qemu-project/qemu/-/issues/2608

--- hw/pci-host/q35.c.orig	2025-10-08 20:50:34.000000000 +0000
+++ hw/pci-host/q35.c
@@ -373,6 +373,10 @@ static void mch_update_smram(MCHPCIState
         memory_region_set_enabled(&mch->high_smram, false);
     }
 
+    if (!mch->has_smm_ranges) {
+        goto out;
+    }
+
     if ((pd->config[MCH_HOST_BRIDGE_ESMRAMC] & MCH_HOST_BRIDGE_ESMRAMC_T_EN) &&
         (pd->config[MCH_HOST_BRIDGE_SMRAM] & SMRAM_G_SMRAME)) {
         switch (pd->config[MCH_HOST_BRIDGE_ESMRAMC] &
@@ -406,7 +410,7 @@ static void mch_update_smram(MCHPCIState
                               mch->below_4g_mem_size - tseg_size);
     memory_region_set_alias_offset(&mch->tseg_window,
                                    mch->below_4g_mem_size - tseg_size);
-
+out:
     memory_region_transaction_commit();
 }
 
@@ -478,15 +482,15 @@ static void mch_write_config(PCIDevice *
         mch_update_pciexbar(mch);
     }
 
-    if (!mch->has_smm_ranges) {
-        return;
-    }
-
     if (ranges_overlap(address, len, MCH_HOST_BRIDGE_SMRAM,
                        MCH_HOST_BRIDGE_SMRAM_SIZE)) {
         mch_update_smram(mch);
     }
 
+    if (!mch->has_smm_ranges) {
+        return;
+    }
+
     if (ranges_overlap(address, len, MCH_HOST_BRIDGE_EXT_TSEG_MBYTES,
                        MCH_HOST_BRIDGE_EXT_TSEG_MBYTES_SIZE)) {
         mch_update_ext_tseg_mbytes(mch);
@@ -589,10 +593,6 @@ static void mch_realize(PCIDevice *d, Er
                  PAM_EXPAN_BASE + i * PAM_EXPAN_SIZE, PAM_EXPAN_SIZE);
     }
 
-    if (!mch->has_smm_ranges) {
-        return;
-    }
-
     /* if *disabled* show SMRAM to all CPUs */
     memory_region_init_alias(&mch->smram_region, OBJECT(mch), "smram-region",
                              mch->pci_address_space, MCH_HOST_BRIDGE_SMRAM_C_BASE,
@@ -608,6 +608,10 @@ static void mch_realize(PCIDevice *d, Er
                                         &mch->open_high_smram, 1);
     memory_region_set_enabled(&mch->open_high_smram, false);
 
+    if (!mch->has_smm_ranges) {
+        return;
+    }
+
     /* smram, as seen by SMM CPUs */
     memory_region_init(&mch->smram, OBJECT(mch), "smram", 4 * GiB);
     memory_region_set_enabled(&mch->smram, true);
