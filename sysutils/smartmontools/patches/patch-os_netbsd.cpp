$NetBSD: patch-os_netbsd.cpp,v 1.1.6.1 2018/08/18 10:34:16 bsiegert Exp $

Missing #include
Backport fix for NetBSD on bigendian systems
https://www.smartmontools.org/ticket/943
https://www.smartmontools.org/changeset/4628

--- os_netbsd.cpp.orig	2017-08-08 19:38:15.000000000 +0000
+++ os_netbsd.cpp
@@ -26,6 +26,7 @@
 
 #include <sys/drvctlio.h>
 #include <sys/utsname.h>
+#include <sys/stat.h>
 #include <errno.h>
 #include <unistd.h>
 
@@ -206,7 +207,7 @@ bool netbsd_ata_device::ata_pass_through
   req.sec_count = in.in_regs.sector_count;
   req.sec_num = in.in_regs.lba_low;
   req.head = in.in_regs.device;
-  req.cylinder = le16toh(in.in_regs.lba_mid | (in.in_regs.lba_high << 8));
+  req.cylinder = in.in_regs.lba_mid | (in.in_regs.lba_high << 8);
 
   switch (in.direction) {
     case ata_cmd_in::no_data:
@@ -237,41 +238,10 @@ bool netbsd_ata_device::ata_pass_through
   out.out_regs.sector_count = req.sec_count;
   out.out_regs.lba_low = req.sec_num;
   out.out_regs.device = req.head;
-  out.out_regs.lba_mid = le16toh(req.cylinder);
-  out.out_regs.lba_high = le16toh(req.cylinder) >> 8;
+  out.out_regs.lba_mid = req.cylinder;
+  out.out_regs.lba_high = req.cylinder >> 8;
   out.out_regs.status = req.command;
 
-  // Command specific processing
-  if (in.in_regs.command == ATA_SMART_CMD
-       && in.in_regs.features == ATA_SMART_STATUS
-       && in.out_needed.lba_high)
-  {
-    unsigned const char normal_lo=0x4f, normal_hi=0xc2;
-    unsigned const char failed_lo=0xf4, failed_hi=0x2c;
-
-    // Cyl low and Cyl high unchanged means "Good SMART status"
-    if (!(out.out_regs.lba_mid==normal_lo && out.out_regs.lba_high==normal_hi)
-    // These values mean "Bad SMART status"
-        && !(out.out_regs.lba_mid==failed_lo && out.out_regs.lba_high==failed_hi))
-
-    {
-      // We haven't gotten output that makes sense; print out some debugging info
-      char buf[512];
-      snprintf(buf, sizeof(buf),
-        "CMD=0x%02x\nFR =0x%02x\nNS =0x%02x\nSC =0x%02x\nCL =0x%02x\nCH =0x%02x\nRETURN =0x%04x\n",
-        (int)req.command,
-        (int)req.features,
-        (int)req.sec_count,
-        (int)req.sec_num,
-        (int)(le16toh(req.cylinder) & 0xff),
-        (int)((le16toh(req.cylinder) >> 8) & 0xff),
-        (int)req.error);
-      printwarning(BAD_SMART,buf);
-      out.out_regs.lba_high = failed_hi;
-      out.out_regs.lba_mid = failed_lo;
-    }
-  }
-
   return true;
 }
 
@@ -834,24 +804,29 @@ smart_device * netbsd_smart_interface::a
     }
   }
 
-  if (str_starts_with(test_name, net_dev_raw_prefix)) {
+  if (str_starts_with(test_name, net_dev_raw_prefix))
     test_name += strlen(net_dev_raw_prefix);
-    if (!strncmp(net_dev_ata_disk, test_name, strlen(net_dev_ata_disk)))
-      return get_ata_device(test_name, "ata");
-    if (!strncmp(net_dev_scsi_disk, test_name, strlen(net_dev_scsi_disk))) {
+  else if (str_starts_with(test_name, net_dev_prefix))
+    test_name += strlen(net_dev_prefix);
+  else
+    return 0; // device is not starting with /dev/ or /dev/r*
+
+  if (!strncmp(net_dev_ata_disk, test_name, strlen(net_dev_ata_disk)))
+    return get_ata_device(name, "ata");
+
+  if (!strncmp(net_dev_scsi_disk, test_name, strlen(net_dev_scsi_disk))) {
       // XXX Try to detect possible USB->(S)ATA bridge
       // XXX get USB vendor ID, product ID and version from sd(4)/umass(4).
       // XXX check sat device via get_usb_dev_type_by_id().
-
       // No USB bridge found, assume regular SCSI device
-      return get_scsi_device(test_name, "scsi");
-    }
-    if (!strncmp(net_dev_scsi_tape, test_name, strlen(net_dev_scsi_tape)))
-      return get_scsi_device(test_name, "scsi");
-  } else if (str_starts_with(test_name, net_dev_prefix)) {
-    if (!strncmp(NVME_PREFIX, test_name, strlen(NVME_PREFIX)))
-      return get_nvme_device(test_name, "nvme", 0 /* use default nsid */);
-  }
+      return get_scsi_device(name, "scsi");
+ }
+
+  if (!strncmp(net_dev_scsi_tape, test_name, strlen(net_dev_scsi_tape)))
+    return get_scsi_device(name, "scsi");
+
+  if (!strncmp(net_dev_nvme_ctrl, test_name, strlen(net_dev_nvme_ctrl)))
+    return get_nvme_device(name, "nvme", 0 /* use default nsid */);
 
   // device type unknown
   return 0;
