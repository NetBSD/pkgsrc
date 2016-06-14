$NetBSD: patch-src_print__wireless__info.c,v 1.1 2016/06/14 06:39:37 kamil Exp $

Add support for NetBSD.

--- src/print_wireless_info.c.orig	2016-01-01 18:51:19.000000000 +0000
+++ src/print_wireless_info.c
@@ -52,6 +52,12 @@
 #include <net80211/ieee80211_ioctl.h>
 #endif
 
+#ifdef __NetBSD__
+#include <unistd.h>
+#include <net80211/ieee80211.h>
+#define IW_ESSID_MAX_SIZE IEEE80211_NWID_LEN
+#endif
+
 #include "i3status.h"
 
 #define WIRELESS_INFO_FLAG_HAS_ESSID (1 << 0)
