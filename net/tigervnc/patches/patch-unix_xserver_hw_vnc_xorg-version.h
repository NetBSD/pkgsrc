$NetBSD: patch-unix_xserver_hw_vnc_xorg-version.h,v 1.1 2015/02/08 19:42:09 wiz Exp $

--- unix/xserver/hw/vnc/xorg-version.h.orig	2013-02-19 13:51:29.000000000 +0000
+++ unix/xserver/hw/vnc/xorg-version.h
@@ -44,8 +44,10 @@
 #define XORG 113
 #elif XORG_VERSION_CURRENT < ((1 * 10000000) + (14 * 100000) + (99 * 1000))
 #define XORG 114
+#elif XORG_VERSION_CURRENT < ((1 * 10000000) + (15 * 100000) + (99 * 1000))
+#define XORG 115
 #else
-#error "X.Org newer than 1.14 is not supported"
+#error "X.Org newer than 1.15 is not supported"
 #endif
 
 #endif
