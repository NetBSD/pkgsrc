$NetBSD: patch-ai,v 1.1 2002/10/23 18:16:59 bouyer Exp $

--- Xvnc/programs/Xserver/hw/vnc/sockets.c.orig	Wed Oct 23 19:16:52 2002
+++ Xvnc/programs/Xserver/hw/vnc/sockets.c	Wed Oct 23 19:18:31 2002
@@ -512,9 +512,9 @@
 #else
     addr.su_len = sizeof(struct sockaddr_in);
     if (rfbLocalhostOnly)
-        addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
+        addr.su_sin.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
     else
-        addr.sin_addr.s_addr = htonl(INADDR_ANY);
+        addr.su_sin.sin_addr.s_addr = htonl(INADDR_ANY);
 #endif
 
     if ((sock = socket(addr.su_family, SOCK_STREAM, 0)) < 0) {
