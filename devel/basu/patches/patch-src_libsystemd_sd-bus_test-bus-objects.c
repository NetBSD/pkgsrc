$NetBSD: patch-src_libsystemd_sd-bus_test-bus-objects.c,v 1.1 2026/04/14 10:58:10 kikadf Exp $

* Fix logging, on NetBSD %m is only allowed in syslog(3) like function

--- src/libsystemd/sd-bus/test-bus-objects.c.orig	2022-12-16 11:13:02.000000000 +0100
+++ src/libsystemd/sd-bus/test-bus-objects.c
@@ -247,14 +247,14 @@ static void *server(void *p) {
 
                 r = sd_bus_process(bus, NULL);
                 if (r < 0) {
-                        log_error_errno(r, "Failed to process requests: %m");
+                        log_error_errno(r, "Failed to process requests");
                         goto fail;
                 }
 
                 if (r == 0) {
                         r = sd_bus_wait(bus, (uint64_t) -1);
                         if (r < 0) {
-                                log_error_errno(r, "Failed to wait: %m");
+                                log_error_errno(r, "Failed to wait");
                                 goto fail;
                         }
 
