$NetBSD: patch-stubdom_vtpmmgr_vtpm_manager.h,v 1.1 2017/03/30 09:15:10 bouyer Exp $
--- stubdom/vtpmmgr/vtpm_manager.h.orig	2017-03-28 15:33:35.000000000 +0200
+++ stubdom/vtpmmgr/vtpm_manager.h	2017-03-28 15:33:55.000000000 +0200
@@ -54,7 +54,7 @@
 
 //************************ Command Codes ****************************
 #define VTPM_ORD_BASE       0x0000
-#define TPM_VENDOR_COMMAND  0x02000000 // TPM Main, part 2, section 17.
+#define TPM_VENDOR_COMMAND  0x20000000 // TPM Main, part 2, section 17.
 #define VTPM_PRIV_BASE      (VTPM_ORD_BASE | TPM_VENDOR_COMMAND)
 
 /*
