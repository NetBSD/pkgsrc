$NetBSD: patch-src_common_sockets.c,v 1.1 2025/05/04 09:47:18 nia Exp $

From e7ee07ddd7a3015a5b059a884f18181f3bd27877 Mon Sep 17 00:00:00 2001
From: Christian Beier <info@christianbeier.net>
Date: Wed, 5 Mar 2025 21:44:01 +0100
Subject: [PATCH] common: don't give invalid fd to FD_SET

re #655

--- src/common/sockets.c.orig	2024-12-22 09:54:53.000000000 +0000
+++ src/common/sockets.c
@@ -60,6 +60,11 @@ rfbBool sock_wait_for_connected(int sock
   timeout.tv_sec=timeout_seconds;
   timeout.tv_usec=0;
 
+  if(socket == RFB_INVALID_SOCKET) {
+      errno = EBADF;
+      return FALSE;
+  }
+
   FD_ZERO(&writefds);
   FD_SET(socket, &writefds);
   FD_ZERO(&exceptfds);
