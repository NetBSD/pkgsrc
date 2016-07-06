$NetBSD: patch-src_master_service-listen.c,v 1.1 2016/07/06 10:39:22 adam Exp $

Most importantly this fixes startup failure with kqueue.
https://github.com/dovecot/core/commit/ffd8dc932516bc55bf01d91355540daab365e5e9?diff=unified

--- src/master/service-listen.c.orig	2016-07-06 09:34:27.000000000 +0000
+++ src/master/service-listen.c
@@ -6,7 +6,6 @@
 #include "fd-close-on-exec.h"
 #include "ioloop.h"
 #include "net.h"
-#include "master-client.h"
 #ifdef HAVE_SYSTEMD
 #include "sd-daemon.h"
 #endif
@@ -357,10 +356,6 @@ static int services_listen_master(struct
 
 	if (service_list->master_fd == -1)
 		return 0;
-
-	service_list->io_master =
-		io_add(service_list->master_fd, IO_READ,
-		       master_client_connected, service_list);
 	return 1;
 }
 
