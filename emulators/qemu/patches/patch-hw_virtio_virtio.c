$NetBSD: patch-hw_virtio_virtio.c,v 1.1 2014/05/15 12:28:13 wiz Exp $

Fixes for
http://cve.mitre.org/cgi-bin/cvename.cgi?name=CVE-2013-4151
http://cve.mitre.org/cgi-bin/cvename.cgi?name=CVE-2013-4535
http://cve.mitre.org/cgi-bin/cvename.cgi?name=CVE-2013-4536
http://cve.mitre.org/cgi-bin/cvename.cgi?name=CVE-2013-6399
http://cve.mitre.org/cgi-bin/cvename.cgi?name=CVE-2014-0182
from upstream git.

--- hw/virtio/virtio.c.orig	2014-04-17 13:44:44.000000000 +0000
+++ hw/virtio/virtio.c
@@ -430,6 +430,12 @@ void virtqueue_map_sg(struct iovec *sg, 
     unsigned int i;
     hwaddr len;
 
+    if (num_sg >= VIRTQUEUE_MAX_SIZE) {
+        error_report("virtio: map attempt out of bounds: %zd > %d",
+                     num_sg, VIRTQUEUE_MAX_SIZE);
+        exit(1);
+    }
+
     for (i = 0; i < num_sg; i++) {
         len = sg[i].iov_len;
         sg[i].iov_base = cpu_physical_memory_map(addr[i], &len, is_write);
@@ -891,7 +897,9 @@ int virtio_set_features(VirtIODevice *vd
 
 int virtio_load(VirtIODevice *vdev, QEMUFile *f)
 {
-    int num, i, ret;
+    int i, ret;
+    int32_t config_len;
+    uint32_t num;
     uint32_t features;
     uint32_t supported_features;
     BusState *qbus = qdev_get_parent_bus(DEVICE(vdev));
@@ -906,6 +914,9 @@ int virtio_load(VirtIODevice *vdev, QEMU
     qemu_get_8s(f, &vdev->status);
     qemu_get_8s(f, &vdev->isr);
     qemu_get_be16s(f, &vdev->queue_sel);
+    if (vdev->queue_sel >= VIRTIO_PCI_QUEUE_MAX) {
+        return -1;
+    }
     qemu_get_be32s(f, &features);
 
     if (virtio_set_features(vdev, features) < 0) {
@@ -914,11 +925,21 @@ int virtio_load(VirtIODevice *vdev, QEMU
                      features, supported_features);
         return -1;
     }
-    vdev->config_len = qemu_get_be32(f);
+    config_len = qemu_get_be32(f);
+    if (config_len != vdev->config_len) {
+        error_report("Unexpected config length 0x%x. Expected 0x%zx",
+                     config_len, vdev->config_len);
+        return -1;
+    }
     qemu_get_buffer(f, vdev->config, vdev->config_len);
 
     num = qemu_get_be32(f);
 
+    if (num > VIRTIO_PCI_QUEUE_MAX) {
+        error_report("Invalid number of PCI queues: 0x%x", num);
+        return -1;
+    }
+
     for (i = 0; i < num; i++) {
         vdev->vq[i].vring.num = qemu_get_be32(f);
         if (k->has_variable_vring_alignment) {
