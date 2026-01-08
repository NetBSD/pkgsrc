$NetBSD: patch-sysdep_bsd_krt-sock.c,v 1.3 2026/01/08 14:26:29 adam Exp $

Fix build.

--- sysdep/bsd/krt-sock.c.orig	2026-01-08 10:38:17.947637208 +0000
+++ sysdep/bsd/krt-sock.c
@@ -358,7 +358,7 @@ krt_send_route(struct krt_proto *p, int 
 
     sockaddr_fill(&gate, af, gw, i, 0);
 #else
-    sockaddr_fill_dl(&gate, i);
+    sockaddr_fill_dl((struct sockaddr_dl *)&gate, i);
 #endif
 
     msg.rtm.rtm_addrs |= RTA_GATEWAY;
@@ -1233,7 +1233,7 @@ kif_update_sysdep_addr(struct iface *i)
     return 0;
 
   ip4_addr old = i->sysdep;
-  i->sysdep = ipa_to_ip4(ipa_from_sa4(&ifr.ifr_addr));
+  i->sysdep = ipa_to_ip4(ipa_from_sa4((sockaddr *)&ifr.ifr_addr));
 
   return !ip4_equal(i->sysdep, old);
 }
