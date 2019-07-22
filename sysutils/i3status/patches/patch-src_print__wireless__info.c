$NetBSD: patch-src_print__wireless__info.c,v 1.3 2019/07/22 23:04:31 wiz Exp $

Add includes for AF_INET & AF_INET6.

--- src/print_wireless_info.c.orig	2019-01-23 08:03:56.000000000 +0000
+++ src/print_wireless_info.c
@@ -61,6 +61,7 @@
 
 #ifdef __NetBSD__
 #include <sys/types.h>
+#include <sys/socket.h>
 #include <net80211/ieee80211.h>
 #define IW_ESSID_MAX_SIZE IEEE80211_NWID_LEN
 #endif
