$NetBSD: patch-lib_CL_devices_cpuinfo.c,v 1.2 2021/06/10 12:26:26 nia Exp $

Do not segfault if /sys/bus/pci/devices/0000:00:00.0/vendor does not exist.

https://github.com/pocl/pocl/pull/948

--- lib/CL/devices/cpuinfo.c.orig	2021-05-19 08:12:19.000000000 +0000
+++ lib/CL/devices/cpuinfo.c
@@ -416,9 +416,12 @@ pocl_cpuinfo_get_cpu_name_and_vendor(cl_
   if (!device->vendor_id)
     {
       f = fopen (pci_bus_root_vendor_file, "r");
-      num_read = fscanf (f, "%x", &device->vendor_id);
-      fclose (f);
-      /* no error checking, if it failed we just won't have the info */
+      if (f)
+        {
+          /* no error checking, if it failed we just won't have the info */
+          num_read = fscanf (f, "%x", &device->vendor_id);
+          fclose (f);
+        }
     }
 }
 
