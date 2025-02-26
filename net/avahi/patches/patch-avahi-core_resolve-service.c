$NetBSD: patch-avahi-core_resolve-service.c,v 1.1 2025/02/26 11:43:05 nia Exp $

[PATCH] Fix NULL pointer crashes from #175

avahi-daemon is crashing when running "ping .local".
The crash is due to failing assertion from NULL pointer.
Add missing NULL pointer checks to fix it.

(CVE-2021-3502)

https://github.com/dkerr64/avahi/commit/fd482a74625b8db8547b8cfca3ee3d3c6c721423.patch

--- avahi-core/resolve-service.c.orig	2020-02-17 03:41:02.380380789 +0000
+++ avahi-core/resolve-service.c
@@ -519,7 +519,10 @@ AvahiSServiceResolver *avahi_s_service_r
         AvahiSServiceResolver *b;
 
         b = avahi_s_service_resolver_prepare(server, interface, protocol, name, type, domain, aprotocol, flags, callback, userdata);
+        if (!b)
+            return NULL;
+
         avahi_s_service_resolver_start(b);
 
         return b;
-}
\ No newline at end of file
+}
