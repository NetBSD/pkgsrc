$NetBSD: patch-src_libsystemd_sd-bus_test-bus-server.c,v 1.1 2026/04/14 10:58:10 kikadf Exp $

* Fix logging, on NetBSD %m is only allowed in syslog(3) like function

--- src/libsystemd/sd-bus/test-bus-server.c.orig	2022-12-16 11:13:02.000000000 +0100
+++ src/libsystemd/sd-bus/test-bus-server.c
@@ -39,14 +39,14 @@ static void *server(void *p) {
 
                 r = sd_bus_process(bus, &m);
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
 
@@ -65,7 +65,7 @@ static void *server(void *p) {
 
                         r = sd_bus_message_new_method_return(m, &reply);
                         if (r < 0) {
-                                log_error_errno(r, "Failed to allocate return: %m");
+                                log_error_errno(r, "Failed to allocate return");
                                 goto fail;
                         }
 
@@ -77,7 +77,7 @@ static void *server(void *p) {
                                         &reply,
                                         &SD_BUS_ERROR_MAKE_CONST(SD_BUS_ERROR_UNKNOWN_METHOD, "Unknown method."));
                         if (r < 0) {
-                                log_error_errno(r, "Failed to allocate return: %m");
+                                log_error_errno(r, "Failed to allocate return");
                                 goto fail;
                         }
                 }
@@ -85,7 +85,7 @@ static void *server(void *p) {
                 if (reply) {
                         r = sd_bus_send(bus, reply, NULL);
                         if (r < 0) {
-                                log_error_errno(r, "Failed to send reply: %m");
+                                log_error_errno(r, "Failed to send reply");
                                 goto fail;
                         }
                 }
@@ -122,7 +122,7 @@ static int client(struct context *c) {
                         "org.freedesktop.systemd.test",
                         "Exit");
         if (r < 0)
-                return log_error_errno(r, "Failed to allocate method call: %m");
+                return log_error_errno(r, "Failed to allocate method call");
 
         r = sd_bus_call(bus, m, 0, &error, &reply);
         if (r < 0)
