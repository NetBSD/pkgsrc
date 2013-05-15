$NetBSD: patch-python_xen_xend_XendNode.py,v 1.1 2013/05/15 06:58:50 jnemeth Exp $

--- python/xen/xend/XendNode.py.orig	2010-04-07 16:12:05.000000000 +0000
+++ python/xen/xend/XendNode.py
@@ -276,28 +276,29 @@ class XendNode:
                 except KeyError:
                     pass
 
-        for pci_dev in PciUtil.get_all_pci_devices():
-            ppci_record = {
-                'domain':                   pci_dev.domain,
-                'bus':                      pci_dev.bus,
-                'slot':                     pci_dev.slot,
-                'func':                     pci_dev.func,
-                'vendor_id':                pci_dev.vendor,
-                'vendor_name':              pci_dev.vendorname,
-                'device_id':                pci_dev.device,
-                'device_name':              pci_dev.devicename,
-                'revision_id':              pci_dev.revision,
-                'class_code':               pci_dev.classcode,
-                'class_name':               pci_dev.classname,
-                'subsystem_vendor_id':      pci_dev.subvendor,
-                'subsystem_vendor_name':    pci_dev.subvendorname,
-                'subsystem_id':             pci_dev.subdevice,
-                'subsystem_name':           pci_dev.subdevicename,
-                'driver':                   pci_dev.driver
-                }
-            # If saved uuid exists, use it. Otherwise create one.
-            ppci_uuid = saved_ppci_table.get(pci_dev.name, uuid.createString())
-            XendPPCI(ppci_uuid, ppci_record)
+        pass
+        #for pci_dev in PciUtil.get_all_pci_devices():
+        #    ppci_record = {
+        #        'domain':                   pci_dev.domain,
+        #        'bus':                      pci_dev.bus,
+        #        'slot':                     pci_dev.slot,
+        #        'func':                     pci_dev.func,
+        #        'vendor_id':                pci_dev.vendor,
+        #        'vendor_name':              pci_dev.vendorname,
+        #        'device_id':                pci_dev.device,
+        #        'device_name':              pci_dev.devicename,
+        #        'revision_id':              pci_dev.revision,
+        #        'class_code':               pci_dev.classcode,
+        #        'class_name':               pci_dev.classname,
+        #        'subsystem_vendor_id':      pci_dev.subvendor,
+        #        'subsystem_vendor_name':    pci_dev.subvendorname,
+        #        'subsystem_id':             pci_dev.subdevice,
+        #        'subsystem_name':           pci_dev.subdevicename,
+        #        'driver':                   pci_dev.driver
+        #        }
+        #    # If saved uuid exists, use it. Otherwise create one.
+        #    ppci_uuid = saved_ppci_table.get(pci_dev.name, uuid.createString())
+        #    XendPPCI(ppci_uuid, ppci_record)
 
     def _init_PSCSIs(self):
         # Initialise PSCSIs and PSCSI_HBAs
