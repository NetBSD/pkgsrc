$NetBSD: patch-src_libsystemd_sd-bus_bus-track.c,v 1.1 2026/04/14 10:58:10 kikadf Exp $

* Fix logging, on NetBSD %m is only allowed in syslog(3) like function

--- src/libsystemd/sd-bus/bus-track.c.orig	2022-12-16 11:13:02.000000000 +0100
+++ src/libsystemd/sd-bus/bus-track.c
@@ -373,7 +373,7 @@ void bus_track_dispatch(sd_bus_track *tr
 
         r = track->handler(track, track->userdata);
         if (r < 0)
-                log_debug_errno(r, "Failed to process track handler: %m");
+                log_debug_errno(r, "Failed to process track handler");
         else if (r == 0)
                 bus_track_add_to_queue(track);
 
