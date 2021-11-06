$NetBSD: patch-hifr.h,v 1.1 2021/11/06 16:43:23 rhialto Exp $

Correct back over-done "or NetBSD" condition.

--- hifr.h.orig	2020-11-30 19:36:38.734299287 +0000
+++ hifr.h
@@ -119,7 +119,7 @@ typedef struct hifr hifr;
   #define  hifr_netmask    ifreq.ifr_ifru.ifru_netmask
   #define  hifr_broadaddr  ifreq.ifr_ifru.ifru_broadaddr
   #define  hifr_hwaddr     ifreq.ifr_ifru.ifru_hwaddr
-#if defined( FREEBSD_OR_NETBSD )
+#if defined( __FreeBSD__ )
   /* short   ifru_flags[2];                                          */
   #define  hifr_flags      ifreq.ifr_ifru.ifru_flags[0]
 #else
