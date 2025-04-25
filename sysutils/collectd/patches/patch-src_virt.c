$NetBSD: patch-src_virt.c,v 1.1 2025/04/25 11:05:53 wiz Exp $

Fix build with libxml2 2.14.

--- src/virt.c.orig	2025-04-25 11:04:54.126466627 +0000
+++ src/virt.c
@@ -2205,7 +2205,7 @@ static int domain_lifecycle_event_cb(__a
   return 0;
 }
 
-static void virt_eventloop_timeout_cb(int timer ATTRIBUTE_UNUSED,
+static void virt_eventloop_timeout_cb(int timer,
                                       void *timer_info) {}
 
 static int register_event_impl(void) {
