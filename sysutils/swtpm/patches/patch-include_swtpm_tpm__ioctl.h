$NetBSD: patch-include_swtpm_tpm__ioctl.h,v 1.1 2026/05/05 10:21:46 jperkin Exp $

Support illumos.

--- include/swtpm/tpm_ioctl.h.orig	2026-05-05 08:18:43.591961939 +0000
+++ include/swtpm/tpm_ioctl.h
@@ -19,7 +19,7 @@
 #include <sys/ioctl.h>
 #endif
 
-#ifdef HAVE_SYS_IOCCOM_H
+#if defined(HAVE_SYS_IOCCOM_H) || defined(__illumos__)
 #include <sys/ioccom.h>
 #endif
 
