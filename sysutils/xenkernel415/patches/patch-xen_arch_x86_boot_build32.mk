$NetBSD: patch-xen_arch_x86_boot_build32.mk,v 1.2 2022/03/04 17:54:08 bouyer Exp $
linux's toolchain doesn't generate a .eh_frame section but NetBSD does.
remove it.

--- xen/arch/x86/boot/build32.mk.orig	2022-01-31 10:42:09.000000000 +0100
+++ xen/arch/x86/boot/build32.mk	2022-03-03 14:12:56.486320239 +0100
@@ -25,7 +25,7 @@
 				exit $$(expr $$idx + 1);; \
 			esac; \
 		done
-	$(OBJCOPY) -O binary -R .got.plt $< $@
+	$(OBJCOPY) -O binary -R .got.plt -R .eh_frame $< $@
 
 %.lnk: %.o build32.lds
 	$(LD) $(LDFLAGS_DIRECT) -N -T build32.lds -o $@ $<
