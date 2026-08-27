$NetBSD: patch-base_slp.py,v 1.1 2026/08/27 09:42:47 wiz Exp $

Fixes problem finding printers, as reported by Dave Tyson.

--- base/slp.py.orig	2026-08-27 09:41:26.843051571 +0000
+++ base/slp.py
@@ -67,7 +67,7 @@ def createSocketsWithsetOption(ttl=4):
 
     try:
         s.setsockopt(socket.SOL_IP, socket.IP_MULTICAST_TTL, ttl)
-        s.setsockopt(socket.SOL_IP, socket.IP_MULTICAST_IF, socket.inet_aton(intf) + socket.inet_aton('0.0.0.0'))
+        s.setsockopt(socket.SOL_IP, socket.IP_MULTICAST_IF, socket.inet_aton(intf))
         s.setsockopt(socket.SOL_IP, socket.IP_MULTICAST_LOOP ,1)
     except Exception as e:
         log.error("Unable to setup multicast socket for SLP: %s" % e)
