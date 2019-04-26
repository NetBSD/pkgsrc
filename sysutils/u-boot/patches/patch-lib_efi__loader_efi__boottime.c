$NetBSD: patch-lib_efi__loader_efi__boottime.c,v 1.1 2019/04/26 08:32:27 skrll Exp $

--- lib/efi_loader/efi_boottime.c.orig	2018-11-14 16:10:06.000000000 +0000
+++ lib/efi_loader/efi_boottime.c
@@ -1838,6 +1838,8 @@ static efi_status_t EFIAPI efi_exit_boot
 
 	board_quiesce_devices();
 
+	cleanup_before_linux();
+
 	/* This stops all lingering devices */
 	bootm_disable_interrupts();
 
