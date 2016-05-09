$NetBSD: patch-src_arp-bsd.c,v 1.1 2016/05/09 11:07:26 adam Exp $

Fix for lack of RTF_LLINFO.

--- src/arp-bsd.c.orig	2016-05-09 11:03:59.000000000 +0000
+++ src/arp-bsd.c
@@ -33,6 +33,10 @@
 #include <string.h>
 #include <unistd.h>
 
+#if !(defined RTF_LLINFO)
+#define RTF_LLINFO RTF_LLDATA
+#endif
+
 #include "dnet.h"
 
 struct arp_handle {
