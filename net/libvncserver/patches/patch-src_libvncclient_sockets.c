$NetBSD: patch-src_libvncclient_sockets.c,v 1.1 2025/05/04 09:47:18 nia Exp $

From ae7656ef8ab2f61f70a58fafd88e527f35b4e8de Mon Sep 17 00:00:00 2001
From: Jonathan Poelen <jonathan.poelen@gmail.com>
Date: Thu, 6 Feb 2025 17:36:46 +0100
Subject: [PATCH] libvncclient: fix memory leak in CompressClipData

--- src/libvncclient/sockets.c.orig	2024-12-22 09:54:53.000000000 +0000
+++ src/libvncclient/sockets.c
@@ -296,6 +296,12 @@ WriteToRFBServer(rfbClient* client, cons
 		errno == ENOENT ||
 #endif
 		errno == EAGAIN) {
+          if(client->sock == RFB_INVALID_SOCKET) {
+              errno = EBADF;
+              rfbClientErr("socket invalid\n");
+              return FALSE;
+          }
+
 	  FD_ZERO(&fds);
 	  FD_SET(client->sock,&fds);
 
@@ -858,6 +864,11 @@ int WaitForMessage(rfbClient* client,uns
   timeout.tv_sec=(usecs/1000000);
   timeout.tv_usec=(usecs%1000000);
 
+  if(client->sock == RFB_INVALID_SOCKET) {
+      errno = EBADF;
+      return -1;
+  }
+
   FD_ZERO(&fds);
   FD_SET(client->sock,&fds);
 
