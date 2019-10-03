$NetBSD: patch-plugins_obs-outputs_net-if.h,v 1.2 2019/10/03 20:33:15 nia Exp $

Support NetBSD.

--- plugins/obs-outputs/net-if.h.orig	2019-09-20 15:14:16.000000000 +0000
+++ plugins/obs-outputs/net-if.h
@@ -28,13 +28,13 @@
 
 #ifdef __linux__
 #include <linux/if_link.h>
-#elif __FreeBSD__
+#elif defined(__FreeBSD__) || defined(__NetBSD__)
 #include <netinet/in.h>
 #ifndef _GNU_SOURCE
 #define _GNU_SOURCE
 #define __NET_IF_GNU_SOURCE__
 #endif //_GNU_SOURCE
-#endif //__FreeBSD__
+#endif //defined(__FreeBSD__) || defined(__NetBSD__)
 
 #include <ifaddrs.h>
 #include <netdb.h>
