$NetBSD: patch-avahi-core_browse-domain.c,v 1.1 2025/02/26 11:43:05 nia Exp $

[PATCH] Fix NULL pointer crashes from #175

avahi-daemon is crashing when running "ping .local".
The crash is due to failing assertion from NULL pointer.
Add missing NULL pointer checks to fix it.

(CVE-2021-3502)

https://github.com/dkerr64/avahi/commit/fd482a74625b8db8547b8cfca3ee3d3c6c721423.patch

--- avahi-core/browse-domain.c.orig	2020-02-17 03:41:02.380380789 +0000
+++ avahi-core/browse-domain.c
@@ -253,7 +253,10 @@ AvahiSDomainBrowser *avahi_s_domain_brow
         AvahiSDomainBrowser *b;
 
         b = avahi_s_domain_browser_prepare(server, interface, protocol, domain, type, flags, callback, userdata);
+        if (!b)
+            return NULL;
+
         avahi_s_domain_browser_start(b);
 
         return b;
-}
\ No newline at end of file
+}
