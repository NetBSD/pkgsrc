$NetBSD: patch-hw_tpm_tpm__ioctl.h,v 1.2 2019/08/16 15:12:19 adam Exp $

SunOS needs filio.h for _IO*() macros.

--- hw/tpm/tpm_ioctl.h.orig	2019-08-15 19:01:42.000000000 +0000
+++ hw/tpm/tpm_ioctl.h
@@ -9,6 +9,9 @@
 #ifndef TPM_IOCTL_H
 #define TPM_IOCTL_H
 
+#ifdef __sun
+#include <sys/filio.h>
+#endif
 #include <sys/uio.h>
 #include <sys/ioctl.h>
 
