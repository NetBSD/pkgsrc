$NetBSD: patch-base_mdns.py,v 1.1 2026/08/27 09:42:47 wiz Exp $

Fixes problem finding printers, as reported by Dave Tyson.

--- base/mdns.py.orig	2026-08-27 09:40:27.508547954 +0000
+++ base/mdns.py
@@ -209,7 +209,7 @@ def createSocketsWithsetOption(ttl=4):
 
     try:
         s.setsockopt(socket.SOL_IP, socket.IP_MULTICAST_TTL, ttl)
-        s.setsockopt(socket.SOL_IP, socket.IP_MULTICAST_IF, socket.inet_aton(intf) + socket.inet_aton('0.0.0.0'))
+        s.setsockopt(socket.SOL_IP, socket.IP_MULTICAST_IF, socket.inet_aton(intf))
         s.setsockopt(socket.SOL_IP, socket.IP_MULTICAST_LOOP ,1)
     except Exception as e:
         log.error("Unable to setup multicast socket for mDNS: %s" % e)
