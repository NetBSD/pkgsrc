$NetBSD: patch-plugins_vidinput_bsd_vidinput_bsd.h,v 1.1 2011/12/04 21:59:37 marino Exp $

--- plugins/vidinput_bsd/vidinput_bsd.h.orig	2009-09-21 00:25:31.000000000 +0000
+++ plugins/vidinput_bsd/vidinput_bsd.h
@@ -13,6 +13,11 @@
 #include <ptlib/vconvert.h>
 #include <ptclib/delaychan.h>
 
+#if defined(P_DRAGONFLY)
+#include <sys/param.h>
+#include <machine/ioctl_meteor.h>
+#endif
+
 #if defined(P_FREEBSD)
 #include <sys/param.h>
 # if __FreeBSD_version >= 502100
