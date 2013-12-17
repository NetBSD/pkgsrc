$NetBSD: patch-libvncserver_sockets.c,v 1.1 2013/12/17 16:27:18 prlw1 Exp $

Don't segfault when using PKG_OPTIONS.libVNCServer=-inet6
From commit 66282f5800

--- libvncserver/sockets.c.orig	2012-05-04 14:19:00.000000000 +0000
+++ libvncserver/sockets.c
@@ -402,9 +402,9 @@ rfbProcessNewConnection(rfbScreenInfoPtr
       rfbLogPerror("rfbProcessNewConnection: error in select");
       return FALSE;
     }
-    if (FD_ISSET(rfbScreen->listenSock, &listen_fds)) 
+    if (rfbScreen->listenSock >= 0 && FD_ISSET(rfbScreen->listenSock, &listen_fds)) 
       chosen_listen_sock = rfbScreen->listenSock;
-    if (FD_ISSET(rfbScreen->listen6Sock, &listen_fds)) 
+    if (rfbScreen->listen6Sock >= 0 && FD_ISSET(rfbScreen->listen6Sock, &listen_fds)) 
       chosen_listen_sock = rfbScreen->listen6Sock;
 
     if ((sock = accept(chosen_listen_sock,
