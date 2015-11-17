$NetBSD: patch-xbmc_system.h,v 1.1 2015/11/17 14:56:07 jmcneill Exp $

--- xbmc/system.h.orig	2015-10-19 06:31:15.000000000 +0000
+++ xbmc/system.h
@@ -146,7 +146,7 @@
  * Linux Specific
  *****************/
 
-#if defined(TARGET_LINUX) || defined(TARGET_FREEBSD)
+#if defined(TARGET_LINUX) || defined(TARGET_FREEBSD) || defined(TARGET_NETBSD)
 #if defined(HAVE_LIBAVAHI_COMMON) && defined(HAVE_LIBAVAHI_CLIENT)
 #define HAS_ZEROCONF
 #define HAS_AVAHI
