$NetBSD: patch-hw_tpm_tpm__ioctl.h,v 1.1 2019/02/13 14:08:43 jperkin Exp $

SunOS needs filio.h for _IO*() macros.

--- hw/tpm/tpm_ioctl.h.orig	2018-12-11 17:44:34.000000000 +0000
+++ hw/tpm/tpm_ioctl.h
@@ -8,6 +8,9 @@
 #ifndef _TPM_IOCTL_H_
 #define _TPM_IOCTL_H_
 
+#ifdef __sun
+#include <sys/filio.h>
+#endif
 #include <sys/uio.h>
 #include <sys/ioctl.h>
 
