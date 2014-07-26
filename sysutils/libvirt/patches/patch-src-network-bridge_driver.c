$NetBSD: patch-src-network-bridge_driver.c,v 1.1 2014/07/26 20:25:04 schnoebe Exp $

--- src/network/bridge_driver.c.orig	2014-06-27 14:51:07.000000000 +0000
+++ src/network/bridge_driver.c
@@ -328,6 +328,14 @@ networkRemoveInactive(virNetworkDriverSt
     return ret;
 }
 
+#if !defined(IFNAMSIZ)
+# if defined(IF_NAMESIZE)
+#  define IFNAMSIZ  IF_NAMESIZE
+# else
+#  error " IFNAMSIZ is not defined!"
+# endif
+#endif
+
 static char *
 networkBridgeDummyNicName(const char *brname)
 {
