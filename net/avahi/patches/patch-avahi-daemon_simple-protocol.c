$NetBSD: patch-avahi-daemon_simple-protocol.c,v 1.1 2025/02/26 11:43:05 nia Exp $

[PATCH] Avoid infinite-loop in avahi-daemon by handling HUP event in
 client_work

CVE-2021-3468
https://github.com/avahi/avahi/commit/6e72b8436b75481c8fd78b434d91b43c459e11e3.patch

--- avahi-daemon/simple-protocol.c.orig	2018-09-14 05:31:28.486023126 +0000
+++ avahi-daemon/simple-protocol.c
@@ -424,6 +424,11 @@ static void client_work(AvahiWatch *watc
         }
     }
 
+    if (events & AVAHI_WATCH_HUP) {
+        client_free(c);
+        return;
+    }
+
     c->server->poll_api->watch_update(
         watch,
         (c->outbuf_length > 0 ? AVAHI_WATCH_OUT : 0) |
