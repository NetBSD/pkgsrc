$NetBSD: patch-src_x86__pci.c,v 1.1 2013/05/15 03:20:16 richard Exp $


Implement legacy io & map for x86 backend
Add the legacy io and map methods for the x86 backend, using ioperm, in/out, and the existing mmap method. 

--- src/x86_pci.c.orig	2012-04-09 17:02:57.000000000 +0000
+++ src/x86_pci.c
@@ -1,5 +1,5 @@
 /*
- * Copyright (c) 2009 Samuel Thibault
+ * Copyright (c) 2009, 2012 Samuel Thibault
  * Heavily inspired from the freebsd, netbsd, and openbsd backends
  * (C) Copyright Eric Anholt 2006
  * (C) Copyright IBM Corporation 2006
@@ -550,6 +550,94 @@ pci_system_x86_destroy(void)
     x86_disable_io();
 }
 
+static struct pci_io_handle *
+pci_device_x86_open_legacy_io(struct pci_io_handle *ret,
+    struct pci_device *dev, pciaddr_t base, pciaddr_t size)
+{
+    x86_enable_io();
+
+    ret->base = base;
+    ret->size = size;
+
+    return ret;
+}
+
+static void
+pci_device_x86_close_io(struct pci_device *dev, struct pci_io_handle *handle)
+{
+    /* Like in the Linux case, do not disable I/O, as it may be opened several
+     * times, and closed fewer times. */
+    /* x86_disable_io(); */
+}
+
+static uint32_t
+pci_device_x86_read32(struct pci_io_handle *handle, uint32_t reg)
+{
+    return inl(reg + handle->base);
+}
+
+static uint16_t
+pci_device_x86_read16(struct pci_io_handle *handle, uint32_t reg)
+{
+    return inw(reg + handle->base);
+}
+
+static uint8_t
+pci_device_x86_read8(struct pci_io_handle *handle, uint32_t reg)
+{
+    return inb(reg + handle->base);
+}
+
+static void
+pci_device_x86_write32(struct pci_io_handle *handle, uint32_t reg,
+		       uint32_t data)
+{
+    outl(data, reg + handle->base);
+}
+
+static void
+pci_device_x86_write16(struct pci_io_handle *handle, uint32_t reg,
+		       uint16_t data)
+{
+    outw(data, reg + handle->base);
+}
+
+static void
+pci_device_x86_write8(struct pci_io_handle *handle, uint32_t reg,
+		      uint8_t data)
+{
+    outb(data, reg + handle->base);
+}
+
+static int
+pci_device_x86_map_legacy(struct pci_device *dev, pciaddr_t base,
+    pciaddr_t size, unsigned map_flags, void **addr)
+{
+    struct pci_device_mapping map;
+    int err;
+
+    map.base = base;
+    map.size = size;
+    map.flags = map_flags;
+    err = pci_device_x86_map_range(dev, &map);
+    *addr = map.memory;
+
+    return err;
+}
+
+static int
+pci_device_x86_unmap_legacy(struct pci_device *dev, void *addr,
+    pciaddr_t size)
+{
+    struct pci_device_mapping map;
+
+    map.size = size;
+    map.flags = 0;
+    map.memory = addr;
+
+    return pci_device_generic_unmap_range(dev, &map);
+}
+
 static const struct pci_system_methods x86_pci_methods = {
     .destroy = pci_system_x86_destroy,
     .read_rom = pci_device_x86_read_rom,
@@ -559,6 +647,16 @@ static const struct pci_system_methods x
     .read = pci_device_x86_read,
     .write = pci_device_x86_write,
     .fill_capabilities = pci_fill_capabilities_generic,
+    .open_legacy_io = pci_device_x86_open_legacy_io,
+    .close_io = pci_device_x86_close_io,
+    .read32 = pci_device_x86_read32,
+    .read16 = pci_device_x86_read16,
+    .read8 = pci_device_x86_read8,
+    .write32 = pci_device_x86_write32,
+    .write16 = pci_device_x86_write16,
+    .write8 = pci_device_x86_write8,
+    .map_legacy = pci_device_x86_map_legacy,
+    .unmap_legacy = pci_device_x86_unmap_legacy,
 };
 
 static int pci_probe(struct pci_system_x86 *pci_sys_x86)
