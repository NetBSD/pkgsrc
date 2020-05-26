$NetBSD: patch-xen_arch_x86_boot_build32.mk,v 1.1 2020/05/26 11:12:10 bouyer Exp $
linux's toolchain doesn't generate a .eh_frame section but NetBSD does.
remove it.

--- xen/arch/x86/boot/build32.mk.orig	2018-04-17 19:21:31.000000000 +0200
+++ xen/arch/x86/boot/build32.mk	2018-04-23 13:29:47.000000000 +0200
@@ -25,7 +25,7 @@
 				exit $$(expr $$idx + 1);; \
 			esac; \
 		done
-	$(OBJCOPY) -O binary -R .got.plt $< $@
+	$(OBJCOPY) -O binary -R .got.plt -R .eh_frame $< $@
 
 %.lnk: %.o
 	$(LD) $(LDFLAGS_DIRECT) -N -T build32.lds -o $@ $<
