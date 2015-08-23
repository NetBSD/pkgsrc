$NetBSD: patch-qemu-xen_ioport.c,v 1.2 2015/08/23 16:17:12 spz Exp $

--- qemu-xen/ioport.c.orig	2013-10-10 14:15:47.000000000 +0000
+++ qemu-xen/ioport.c
@@ -177,6 +177,7 @@ int register_ioport_write(pio_addr_t sta
     return 0;
 }
 
+#undef read
 static uint32_t ioport_readb_thunk(void *opaque, uint32_t addr)
 {
     IORange *ioport = opaque;
