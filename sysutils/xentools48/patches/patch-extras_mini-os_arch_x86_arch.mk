$NetBSD: patch-extras_mini-os_arch_x86_arch.mk,v 1.1 2017/03/30 09:15:10 bouyer Exp $

--- extras/mini-os/arch/x86/arch.mk.orig	2017-03-27 16:41:50.000000000 +0200
+++ extras/mini-os/arch/x86/arch.mk	2017-03-27 16:43:37.000000000 +0200
@@ -7,7 +7,7 @@
 
 ifeq ($(MINIOS_TARGET_ARCH),x86_32)
 ARCH_CFLAGS  := -m32 -march=i686
-ARCH_LDFLAGS := -m elf_i386
+ARCH_LDFLAGS := -Wl,-melf_i386
 ARCH_ASFLAGS := -m32
 EXTRA_INC += $(TARGET_ARCH_FAM)/$(MINIOS_TARGET_ARCH)
 EXTRA_SRC += arch/$(EXTRA_INC)
@@ -17,7 +17,7 @@
 ARCH_CFLAGS := -m64 -mno-red-zone -fno-reorder-blocks
 ARCH_CFLAGS += -fno-asynchronous-unwind-tables
 ARCH_ASFLAGS := -m64
-ARCH_LDFLAGS := -m elf_x86_64
+ARCH_LDFLAGS := -Wl,-melf_x86_64
 EXTRA_INC += $(TARGET_ARCH_FAM)/$(MINIOS_TARGET_ARCH)
 EXTRA_SRC += arch/$(EXTRA_INC)
 endif
