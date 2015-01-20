$NetBSD: patch-qemu-xen-traditional_i386-dm_hookstarget.mak,v 1.1 2015/01/20 16:42:13 bouyer Exp $

--- qemu-xen-traditional/i386-dm/hookstarget.mak.orig	2014-10-06 17:50:24.000000000 +0200
+++ qemu-xen-traditional/i386-dm/hookstarget.mak	2015-01-19 13:16:38.000000000 +0100
@@ -2,5 +2,5 @@
 
 install-hook:
 	$(INSTALL_DIR) "$(DESTDIR)/$(bindir)"
-	$(INSTALL_DIR) "$(DESTDIR)/$(configdir)"
-	$(INSTALL_PROG) $(QEMU_ROOT)/i386-dm/qemu-ifup-$(IOEMU_OS) "$(DESTDIR)/$(configdir)/qemu-ifup"
+	$(INSTALL_DIR) "$(DESTDIR)/$(XEN_EXAMPLES_DIR)/scripts"
+	$(INSTALL_PROG) $(QEMU_ROOT)/i386-dm/qemu-ifup-$(IOEMU_OS) "$(DESTDIR)/$(XEN_EXAMPLES_DIR)/scripts/qemu-ifup"
