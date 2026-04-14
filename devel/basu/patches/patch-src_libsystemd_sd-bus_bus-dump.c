$NetBSD: patch-src_libsystemd_sd-bus_bus-dump.c,v 1.1 2026/04/14 10:58:10 kikadf Exp $

* Fix logging, on NetBSD %m is only allowed in syslog(3) like function

--- src/libsystemd/sd-bus/bus-dump.c.orig	2022-12-16 11:13:02.000000000 +0100
+++ src/libsystemd/sd-bus/bus-dump.c
@@ -121,7 +121,7 @@ int bus_message_dump(sd_bus_message *m, 
 
         r = sd_bus_message_rewind(m, !(flags & BUS_MESSAGE_DUMP_SUBTREE_ONLY));
         if (r < 0)
-                return log_error_errno(r, "Failed to rewind: %m");
+                return log_error_errno(r, "Failed to rewind");
 
         if (!(flags & BUS_MESSAGE_DUMP_SUBTREE_ONLY)) {
                 _cleanup_free_ char *prefix = NULL;
@@ -152,7 +152,7 @@ int bus_message_dump(sd_bus_message *m, 
 
                 r = sd_bus_message_peek_type(m, &type, &contents);
                 if (r < 0)
-                        return log_error_errno(r, "Failed to peek type: %m");
+                        return log_error_errno(r, "Failed to peek type");
 
                 if (r == 0) {
                         if (level <= 1)
@@ -160,7 +160,7 @@ int bus_message_dump(sd_bus_message *m, 
 
                         r = sd_bus_message_exit_container(m);
                         if (r < 0)
-                                return log_error_errno(r, "Failed to exit container: %m");
+                                return log_error_errno(r, "Failed to exit container");
 
                         level--;
 
@@ -179,7 +179,7 @@ int bus_message_dump(sd_bus_message *m, 
                 if (bus_type_is_container(type) > 0) {
                         r = sd_bus_message_enter_container(m, type, contents);
                         if (r < 0)
-                                return log_error_errno(r, "Failed to enter container: %m");
+                                return log_error_errno(r, "Failed to enter container");
 
                         if (type == SD_BUS_TYPE_ARRAY)
                                 fprintf(f, "%sARRAY \"%s\" {\n", prefix, contents);
@@ -197,7 +197,7 @@ int bus_message_dump(sd_bus_message *m, 
 
                 r = sd_bus_message_read_basic(m, type, &basic);
                 if (r < 0)
-                        return log_error_errno(r, "Failed to get basic: %m");
+                        return log_error_errno(r, "Failed to get basic");
 
                 assert(r > 0);
 
