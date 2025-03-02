$NetBSD: patch-backends_tpm_tpm__ioctl.h,v 1.1 2025/03/02 12:45:46 nia Exp $

SunOS needs filio.h for _IO*() macros.

--- backends/tpm/tpm_ioctl.h.orig	2022-12-14 16:28:45.000000000 +0000
+++ backends/tpm/tpm_ioctl.h
@@ -14,6 +14,9 @@
 
 #include <stdint.h>
 #include <sys/types.h>
+#ifdef __sun
+#include <sys/filio.h>
+#endif
 #ifndef _WIN32
 #include <sys/uio.h>
 #include <sys/ioctl.h>
