$NetBSD: patch-src_libvncclient_listen.c,v 1.1 2025/05/04 09:47:18 nia Exp $

From b17c59257fd940af3fb076ae9c4cf88c40e133ac Mon Sep 17 00:00:00 2001
From: Christian Beier <info@christianbeier.net>
Date: Wed, 5 Mar 2025 21:48:52 +0100
Subject: [PATCH] libvncclient: don't give invalid fds to FD_* macros

re #655

--- src/libvncclient/listen.c.orig	2024-12-22 09:54:53.000000000 +0000
+++ src/libvncclient/listen.c
@@ -102,9 +102,9 @@ listenForIncomingConnections(rfbClient* 
     r = select(rfbMax(listenSocket, listen6Socket)+1, &fds, NULL, NULL, NULL);
 
     if (r > 0) {
-      if (FD_ISSET(listenSocket, &fds))
+      if (listenSocket != RFB_INVALID_SOCKET && FD_ISSET(listenSocket, &fds))
 	client->sock = AcceptTcpConnection(client->listenSock); 
-      else if (FD_ISSET(listen6Socket, &fds))
+      else if (listen6Socket != RFB_INVALID_SOCKET && FD_ISSET(listen6Socket, &fds))
 	client->sock = AcceptTcpConnection(client->listen6Sock);
 
       if (client->sock == RFB_INVALID_SOCKET)
@@ -201,9 +201,9 @@ listenForIncomingConnectionsNoFork(rfbCl
 
   if (r > 0)
     {
-      if (FD_ISSET(client->listenSock, &fds))
+      if (client->listenSock != RFB_INVALID_SOCKET && FD_ISSET(client->listenSock, &fds))
 	client->sock = AcceptTcpConnection(client->listenSock); 
-      else if (FD_ISSET(client->listen6Sock, &fds))
+      else if (client->listen6Sock != RFB_INVALID_SOCKET && FD_ISSET(client->listen6Sock, &fds))
 	client->sock = AcceptTcpConnection(client->listen6Sock);
 
       if (client->sock == RFB_INVALID_SOCKET)
