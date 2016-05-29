$NetBSD: patch-include_ddns.h,v 1.2 2016/05/29 22:32:12 abs Exp $

/var/run is for non-persistent data, and despite the misleading name,
RUNTIME_DATA_DIR contains "persistent cache files", so let's use
/var/db (subject to VARBASE replacement under pkgsrc) instead.

With RUNTIME_DATA_DIR set to a more reasonable value, stop using it
for the default pidfile location.

--- include/ddns.h.orig	2015-07-22 10:01:42.000000000 +0000
+++ include/ddns.h
@@ -34,14 +34,14 @@
 #include "plugin.h"
 #include "libite/lite.h"
 
-#define VERSION_STRING	"Inadyn version " VERSION " -- Dynamic DNS update client."
+#define VERSION_STRING	"Inadyn version " VERSION " -- Dynamic DNS update client."
 #define AGENT_NAME	"inadyn/" VERSION
 #define SUPPORT_ADDR	PACKAGE_BUGREPORT
 
 /* Test values */
-#define DEFAULT_CONFIG_FILE	"/etc/inadyn.conf"
-#define RUNTIME_DATA_DIR        _PATH_VARRUN     "inadyn/"
-#define DEFAULT_PIDFILE         RUNTIME_DATA_DIR "inadyn.pid"
+#define DEFAULT_CONFIG_FILE     SYSCONFDIR "/inadyn.conf"
+#define RUNTIME_DATA_DIR        _PATH_VARDB  "inadyn/"
+#define DEFAULT_PIDFILE         _PATH_VARRUN "inadyn.pid"
 
 #define DYNDNS_MY_IP_SERVER	"checkip.dyndns.org"
 #define DYNDNS_MY_CHECKIP_URL	"/"
