$NetBSD: patch-hercifc.h,v 1.2 2012/03/25 05:27:43 ryoon Exp $

--- hercifc.h.orig	2009-02-09 07:55:14.000000000 +0000
+++ hercifc.h
@@ -90,7 +90,11 @@
 // --------------------------------------------------------------------
 
 #define  HERCIFC_CMD  "hercifc"           // Interface config command
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__DragonFly__)
+#define  HERCTUN_DEV  "/dev/tun"          // Default TUN/TAP char dev
+#else
 #define  HERCTUN_DEV  "/dev/net/tun"      // Default TUN/TAP char dev
+#endif
 
 typedef struct _CTLREQ
 {
@@ -101,7 +105,7 @@ typedef struct _CTLREQ
   union
   {
     struct ifreq     ifreq;
-#if !defined(__APPLE__) && !defined(__FreeBSD__) && !defined(__SOLARIS__)
+#if !defined(__APPLE__) && !defined(__FreeBSD__) && !defined(__SOLARIS__) && !defined(__DragonFly__)
     struct rtentry   rtentry;
 #endif
   }
