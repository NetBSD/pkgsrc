$NetBSD: patch-unix_xserver_hw_vnc_XserverDesktop.cc,v 1.1 2026/06/03 11:28:53 wiz Exp $

Avoid re-registering notification for deleted client.
https://github.com/TigerVNC/tigervnc/pull/2116

--- unix/xserver/hw/vnc/XserverDesktop.cc.orig	2026-06-03 11:16:27.717384239 +0000
+++ unix/xserver/hw/vnc/XserverDesktop.cc
@@ -387,6 +387,7 @@ void XserverDesktop::blockHandler(int* timeout)
         server->removeSocket(*i);
         vncClientGone(fd);
         delete (*i);
+        continue;
       }
 
       /* Update existing NotifyFD to listen for write (or not) */
