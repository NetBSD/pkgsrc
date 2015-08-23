$NetBSD: patch-qemu-xen-traditional_hw_pass-through.h,v 1.2 2015/08/23 16:17:12 spz Exp $

patch for CVE-2015-4103 aka XSA-128 from
http://xenbits.xen.org/xsa/xsa128-qemut.patch

patch for CVE-2015-4104 aka XSA-129 from 
http://xenbits.xen.org/xsa/xsa129-qemut.patch

patch for CVE-2015-4105 aka XSA-130 from
http://xenbits.xen.org/xsa/xsa130-qemut.patch

patch for CVE-2015-4106 aka XSA-131 from
http://xenbits.xen.org/xsa/xsa131-qemut-6.patch
http://xenbits.xen.org/xsa/xsa131-qemut-7.patch
http://xenbits.xen.org/xsa/xsa131-qemut-8.patch

fix up pci include path for NetBSD

--- qemu-xen-traditional/hw/pass-through.h.orig	2014-01-09 12:44:42.000000000 +0000
+++ qemu-xen-traditional/hw/pass-through.h
@@ -20,14 +20,19 @@
 
 #include "hw.h"
 #include "pci.h"
+#ifdef __NetBSD__
+#include "pciutils/header.h"
+#include "pciutils/pci.h"
+#else
 #include "pci/header.h"
 #include "pci/pci.h"
+#endif
 #include "exec-all.h"
 #include "sys-queue.h"
 #include "qemu-timer.h"
 
 /* Log acesss */
-#define PT_LOGGING_ENABLED
+/* #define PT_LOGGING_ENABLED */
 
 /* Print errors even if logging is disabled */
 #define PT_ERR(_f, _a...)   fprintf(logfile, "%s: " _f, __func__, ##_a)
@@ -84,6 +89,12 @@
 #define PCI_MSI_FLAGS_MASK_BIT  0x0100
 #endif
 
+#ifndef PCI_MSI_MASK_32
+/* interrupt masking register */
+#define PCI_MSI_MASK_32     12
+#define PCI_MSI_MASK_64     16
+#endif
+
 #ifndef PCI_EXP_TYPE_PCIE_BRIDGE
 /* PCI/PCI-X to PCIE Bridge */
 #define PCI_EXP_TYPE_PCIE_BRIDGE 0x8
@@ -99,6 +110,14 @@
 #define PCI_EXP_TYPE_ROOT_EC     0xa
 #endif
 
+#ifndef PCI_VPD_ADDR
+/* Vital Product Data */
+#define PCI_VPD_ADDR		2	/* Address to access (15 bits!) */
+#define  PCI_VPD_ADDR_MASK	0x7fff	/* Address mask */
+#define  PCI_VPD_ADDR_F		0x8000	/* Write 0, 1 indicates completion */
+#define PCI_VPD_DATA		4	/* 32-bits of data returned here */
+#endif
+
 #ifndef PCI_ERR_UNCOR_MASK
 /* Uncorrectable Error Mask */
 #define PCI_ERR_UNCOR_MASK      8
@@ -234,6 +253,8 @@ struct pt_dev {
     unsigned power_mgmt:1;
     struct pt_pm_info *pm_state;                /* PM virtualization */
     unsigned is_virtfn:1;
+    unsigned permissive:1;
+    unsigned permissive_warned:1;
 
     /* io port multiplexing */
 #define PCI_IOMUL_INVALID_FD    (-1)
@@ -368,12 +389,12 @@ struct pt_reg_info_tbl {
     uint32_t size;
     /* reg initial value */
     uint32_t init_val;
+    /* reg reserved field mask (ON:reserved, OFF:defined) */
+    uint32_t res_mask;
     /* reg read only field mask (ON:RO/ROS, OFF:other) */
     uint32_t ro_mask;
     /* reg emulate field mask (ON:emu, OFF:passthrough) */
     uint32_t emu_mask;
-    /* no write back allowed */
-    uint32_t no_wb;
     /* emul reg initialize method */
     conf_reg_init init;
     union {
