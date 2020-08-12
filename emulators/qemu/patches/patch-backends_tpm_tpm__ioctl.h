$NetBSD: patch-backends_tpm_tpm__ioctl.h,v 1.1 2020/08/12 18:31:27 ryoon Exp $

SunOS needs filio.h for _IO*() macros.

--- backends/tpm/tpm_ioctl.h.orig	2019-08-15 19:01:42.000000000 +0000
+++ backends/tpm/tpm_ioctl.h
@@ -9,6 +9,9 @@
 #ifndef TPM_IOCTL_H
 #define TPM_IOCTL_H
 
+#ifdef __sun
+#include <sys/filio.h>
+#endif
 #include <sys/uio.h>
 #include <sys/ioctl.h>
 
