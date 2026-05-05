$NetBSD: patch-src_swtpm__ioctl_tpm__ioctl.c,v 1.1 2026/05/05 10:21:46 jperkin Exp $

Portability fix.

--- src/swtpm_ioctl/tpm_ioctl.c.orig	2026-05-05 08:39:39.470484913 +0000
+++ src/swtpm_ioctl/tpm_ioctl.c
@@ -90,6 +90,10 @@
 # define _IOC_NRMASK 255
 #endif
 
+#ifndef MIN
+#define MIN(a, b)	((a) < (b) ? (a) : (b))
+#endif
+
 /* poll timeout that takes into account a busy swtpm creating a key */
 #define DEFAULT_POLL_TIMEOUT 10000 /* ms */
 
