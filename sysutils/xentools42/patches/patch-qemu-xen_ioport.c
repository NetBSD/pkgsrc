$NetBSD: patch-qemu-xen_ioport.c,v 1.1 2013/05/26 20:27:43 bouyer Exp $

--- qemu-xen/ioport.c.orig	2013-05-26 20:28:24.000000000 +0200
+++ qemu-xen/ioport.c	2013-05-26 20:28:28.000000000 +0200
@@ -177,6 +177,7 @@
     return 0;
 }
 
+#undef read
 static uint32_t ioport_readb_thunk(void *opaque, uint32_t addr)
 {
     IORange *ioport = opaque;
