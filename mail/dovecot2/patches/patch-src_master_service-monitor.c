$NetBSD: patch-src_master_service-monitor.c,v 1.1 2016/07/06 10:39:22 adam Exp $

Most importantly this fixes startup failure with kqueue.
https://github.com/dovecot/core/commit/ffd8dc932516bc55bf01d91355540daab365e5e9?diff=unified

--- src/master/service-monitor.c.orig	2016-07-06 09:36:27.000000000 +0000
+++ src/master/service-monitor.c
@@ -7,6 +7,7 @@
 #include "hash.h"
 #include "str.h"
 #include "safe-mkstemp.h"
+#include "master-client.h"
 #include "service.h"
 #include "service-process.h"
 #include "service-process-notify.h"
@@ -452,6 +453,12 @@ void services_monitor_start(struct servi
 		return;
 	service_anvil_monitor_start(service_list);
 
+	if (service_list->io_master == NULL) {
+		service_list->io_master =
+			io_add(service_list->master_fd, IO_READ,
+			       master_client_connected, service_list);
+	}
+
 	array_foreach(&service_list->services, services) {
 		struct service *service = *services;
 
