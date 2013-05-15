$NetBSD: patch-qemu-xen-traditional_i386-dm_hookstarget.mak,v 1.1 2013/05/15 06:58:50 jnemeth Exp $

--- qemu-xen-traditional/i386-dm/hookstarget.mak.orig	2011-04-15 11:45:21.000000000 +0200
+++ qemu-xen-traditional/i386-dm/hookstarget.mak	2011-04-15 11:46:36.000000000 +0200
@@ -2,5 +2,5 @@
 
 install-hook:
 	$(INSTALL_DIR) "$(DESTDIR)/$(bindir)"
-	$(INSTALL_DIR) "$(DESTDIR)/$(configdir)"
-	$(INSTALL_PROG) $(QEMU_ROOT)/i386-dm/qemu-ifup-$(IOEMU_OS) "$(DESTDIR)/$(configdir)/qemu-ifup"
+	$(INSTALL_DIR) "$(DESTDIR)/$(XEN_EXAMPLES_DIR)/scripts"
+	$(INSTALL_PROG) $(QEMU_ROOT)/i386-dm/qemu-ifup-$(IOEMU_OS) "$(DESTDIR)/$(XEN_EXAMPLES_DIR)/scripts/qemu-ifup"
