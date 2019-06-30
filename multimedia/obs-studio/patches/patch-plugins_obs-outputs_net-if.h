$NetBSD: patch-plugins_obs-outputs_net-if.h,v 1.1 2019/06/30 21:01:24 nia Exp $

Support NetBSD.

--- plugins/obs-outputs/net-if.h.orig	2019-06-14 05:28:10.000000000 +0000
+++ plugins/obs-outputs/net-if.h
@@ -28,7 +28,7 @@
 
 #  ifdef __linux__
 #    include <linux/if_link.h>
-#  elif __FreeBSD__
+#  elif defined(__FreeBSD__) || defined(__NetBSD__)
 #    include <netinet/in.h>
 #    ifndef _GNU_SOURCE
 #      define _GNU_SOURCE
