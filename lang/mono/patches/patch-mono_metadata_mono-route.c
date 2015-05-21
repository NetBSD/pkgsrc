$NetBSD: patch-mono_metadata_mono-route.c,v 1.1 2015/05/21 14:38:08 kefren Exp $

Fix includes

--- mono/metadata/mono-route.c.orig	2015-05-11 16:20:29.000000000 +0300
+++ mono/metadata/mono-route.c	2015-05-11 16:20:39.000000000 +0300
@@ -8,6 +8,7 @@
 
 #if defined(PLATFORM_MACOSX) || defined(PLATFORM_BSD)
 
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <net/if.h>
 #include <net/if_dl.h>
