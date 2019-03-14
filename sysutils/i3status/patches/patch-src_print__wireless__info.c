$NetBSD: patch-src_print__wireless__info.c,v 1.2 2019/03/14 11:55:29 wiz Exp $

Add includes for AF_INET & AF_INET6, and for free().

--- src/print_wireless_info.c.orig	2018-05-11 09:10:46.000000000 +0000
+++ src/print_wireless_info.c
@@ -60,10 +60,13 @@
 
 #ifdef __NetBSD__
 #include <sys/types.h>
+#include <sys/socket.h>
 #include <net80211/ieee80211.h>
 #define IW_ESSID_MAX_SIZE IEEE80211_NWID_LEN
 #endif
 
+#include <stdlib.h>
+
 #include "i3status.h"
 
 #define WIRELESS_INFO_FLAG_HAS_ESSID (1 << 0)
