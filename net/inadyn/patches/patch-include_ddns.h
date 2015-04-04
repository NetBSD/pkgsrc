$NetBSD: patch-include_ddns.h,v 1.1 2015/04/04 07:59:34 snj Exp $

/var/run is for non-persistent data, and despite the misleading name,
RUNTIME_DATA_DIR contains "persistent cache files", so let's use
/var/db (subject to VARBASE replacement under pkgsrc) instead.

With RUNTIME_DATA_DIR set to a more reasonable value, stop using it
for the default pidfile location.

--- include/ddns.h.orig	2015-02-07 23:08:18.000000000 -0800
+++ include/ddns.h	2015-04-03 22:38:17.000000000 -0700
@@ -38,8 +38,8 @@
 
 /* Test values */
 #define DEFAULT_CONFIG_FILE	"/etc/inadyn.conf"
-#define RUNTIME_DATA_DIR	"/var/run/inadyn"
-#define DEFAULT_PIDFILE		RUNTIME_DATA_DIR "/inadyn.pid"
+#define RUNTIME_DATA_DIR	"/var/db/inadyn"
+#define DEFAULT_PIDFILE		"/var/run/inadyn.pid"
 
 #define DYNDNS_MY_IP_SERVER	"checkip.dyndns.org"
 #define DYNDNS_MY_CHECKIP_URL	"/"
