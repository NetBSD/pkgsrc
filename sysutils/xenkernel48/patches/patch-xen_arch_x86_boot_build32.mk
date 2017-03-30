$NetBSD: patch-xen_arch_x86_boot_build32.mk,v 1.1 2017/03/30 09:15:09 bouyer Exp $
linux's toolchain doesn't generate a .eh_frame section but NetBSD does.
remove it.

--- xen/arch/x86/boot/build32.mk.orig	2017-03-24 16:06:14.000000000 +0100
+++ xen/arch/x86/boot/build32.mk	2017-03-24 16:06:37.000000000 +0100
@@ -24,7 +24,7 @@
 				exit $$(expr $$idx + 1);; \
 			esac; \
 		done
-	$(OBJCOPY) -O binary -R .got.plt $< $@
+	$(OBJCOPY) -O binary -R .got.plt -R .eh_frame $< $@
 
 %.lnk: %.o
 	$(LD) $(LDFLAGS_DIRECT) -N -T build32.lds -o $@ $<
