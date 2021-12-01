$NetBSD: patch-src_daemon_interfaces-bsd.c,v 1.3 2021/12/01 19:18:57 hauke Exp $

Upstream's patch to <https://github.com/lldpd/lldpd/issues/489>
"bridge0 is a bridge too big. Please, report the problem"

--- src/daemon/interfaces-bsd.c.orig	2021-09-22 07:17:57.000000000 +0000
+++ src/daemon/interfaces-bsd.c
@@ -72,11 +72,19 @@ ifbsd_check_bridge(struct lldpd *cfg,
     struct interfaces_device_list *interfaces,
     struct interfaces_device *master)
 {
-	struct ifbreq req[64];
-	struct ifbifconf bifc = {
-		.ifbic_len = sizeof(req),
-		.ifbic_req = req
-	};
+	static size_t ifbic_len = 64;
+	struct ifbreq *req = NULL;
+	struct ifbifconf bifc = {};
+
+ retry_alloc:
+	if ((req = realloc(req, ifbic_len)) == NULL) {
+		log_warn("interfaces", "unable to allocate memory to query bridge %s",
+		    master->name);
+		free(bifc.ifbic_req);
+		return;
+	}
+	bifc.ifbic_len = ifbic_len;
+	bifc.ifbic_req = req;
 
 #if defined HOST_OS_FREEBSD || defined HOST_OS_NETBSD || defined HOST_OS_OSX || defined HOST_OS_DRAGONFLY
 	struct ifdrv ifd = {
@@ -101,11 +109,9 @@ ifbsd_check_bridge(struct lldpd *cfg,
 #else
 # error Unsupported OS
 #endif
-	if (bifc.ifbic_len >= sizeof(req)) {
-		log_warnx("interfaces",
-		    "%s is a bridge too big. Please, report the problem",
-		    master->name);
-		return;
+	if (bifc.ifbic_len >= ifbic_len) {
+		ifbic_len = bifc.ifbic_len + 1;
+		goto retry_alloc;
 	}
 	for (int i = 0; i < bifc.ifbic_len / sizeof(*req); i++) {
 		struct interfaces_device *slave =
