$NetBSD: patch-src_libsystemd_sd-bus_test-bus-creds.c,v 1.1 2026/04/14 10:58:10 kikadf Exp $

* Fix logging, on NetBSD %m is only allowed in syslog(3) like function

--- src/libsystemd/sd-bus/test-bus-creds.c.orig	2022-12-16 11:13:02.000000000 +0100
+++ src/libsystemd/sd-bus/test-bus-creds.c
@@ -14,7 +14,7 @@ int main(int argc, char *argv[]) {
         test_setup_logging(LOG_DEBUG);
 
         r = sd_bus_creds_new_from_pid(&creds, 0, _SD_BUS_CREDS_ALL);
-        log_full_errno(r < 0 ? LOG_ERR : LOG_DEBUG, r, "sd_bus_creds_new_from_pid: %m");
+        log_full_errno(r < 0 ? LOG_ERR : LOG_DEBUG, r, "sd_bus_creds_new_from_pid");
         assert_se(r >= 0);
 
         bus_creds_dump(creds, NULL, true);
