$NetBSD: patch-nvmecmds.cpp,v 1.1 2019/01/18 02:04:43 tnn Exp $

It looks from the code like it is supposed to work to read the SMART data
by calling the nvme passthrough ioctl with broadcast nsid.
But it doesn't seem to work on NetBSD? So use the explicit nsid instead.

--- nvmecmds.cpp.orig	2018-08-19 18:45:53.000000000 +0000
+++ nvmecmds.cpp
@@ -207,7 +207,11 @@ bool nvme_read_log_page(nvme_device * de
 // Read NVMe Error Information Log.
 bool nvme_read_error_log(nvme_device * device, nvme_error_log_page * error_log, unsigned num_entries)
 {
-  if (!nvme_read_log_page(device, 0x01, error_log, num_entries * sizeof(*error_log), true))
+  bool use_broadcast_nsid = true;
+#if defined(__NetBSD__)
+  use_broadcast_nsid = false;
+#endif
+  if (!nvme_read_log_page(device, 0x01, error_log, num_entries * sizeof(*error_log), use_broadcast_nsid))
     return false;
 
   if (isbigendian()) {
@@ -228,7 +232,11 @@ bool nvme_read_error_log(nvme_device * d
 // Read NVMe SMART/Health Information log.
 bool nvme_read_smart_log(nvme_device * device, nvme_smart_log & smart_log)
 {
-  if (!nvme_read_log_page(device, 0x02, &smart_log, sizeof(smart_log), true))
+  bool use_broadcast_nsid = true;
+#if defined(__NetBSD__)
+  use_broadcast_nsid = false;
+#endif
+  if (!nvme_read_log_page(device, 0x02, &smart_log, sizeof(smart_log), use_broadcast_nsid))
     return false;
 
   if (isbigendian()) {
