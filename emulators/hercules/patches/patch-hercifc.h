$NetBSD: patch-hercifc.h,v 1.1 2011/05/01 23:28:59 ryoon Exp $

--- hercifc.h.orig	2009-02-09 07:55:14.000000000 +0000
+++ hercifc.h
@@ -90,7 +90,11 @@
 // --------------------------------------------------------------------
 
 #define  HERCIFC_CMD  "hercifc"           // Interface config command
+#if defined(__FreeBSD__) || defined(__NetBSD__)
+#define  HERCTUN_DEV  "/dev/tun"          // Default TUN/TAP char dev
+#else
 #define  HERCTUN_DEV  "/dev/net/tun"      // Default TUN/TAP char dev
+#endif
 
 typedef struct _CTLREQ
 {
