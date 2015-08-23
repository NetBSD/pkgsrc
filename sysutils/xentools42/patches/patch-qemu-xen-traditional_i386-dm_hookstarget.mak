$NetBSD: patch-qemu-xen-traditional_i386-dm_hookstarget.mak,v 1.2 2015/08/23 16:17:12 spz Exp $

--- qemu-xen-traditional/i386-dm/hookstarget.mak.orig	2014-01-09 12:44:42.000000000 +0000
+++ qemu-xen-traditional/i386-dm/hookstarget.mak
@@ -2,5 +2,5 @@ IOEMU_OS=$(shell uname -s)
 
 install-hook:
 	$(INSTALL_DIR) "$(DESTDIR)/$(bindir)"
-	$(INSTALL_DIR) "$(DESTDIR)/$(configdir)"
-	$(INSTALL_PROG) $(QEMU_ROOT)/i386-dm/qemu-ifup-$(IOEMU_OS) "$(DESTDIR)/$(configdir)/qemu-ifup"
+	$(INSTALL_DIR) "$(DESTDIR)/$(XEN_EXAMPLES_DIR)/scripts"
+	$(INSTALL_PROG) $(QEMU_ROOT)/i386-dm/qemu-ifup-$(IOEMU_OS) "$(DESTDIR)/$(XEN_EXAMPLES_DIR)/scripts/qemu-ifup"
