$NetBSD: patch-src_libvncclient_tls__openssl.c,v 1.1 2025/05/04 09:47:18 nia Exp $

From ae7656ef8ab2f61f70a58fafd88e527f35b4e8de Mon Sep 17 00:00:00 2001
From: Jonathan Poelen <jonathan.poelen@gmail.com>
Date: Thu, 6 Feb 2025 17:36:46 +0100
Subject: [PATCH] libvncclient: fix memory leak in CompressClipData

--- src/libvncclient/tls_openssl.c.orig	2024-12-22 09:54:53.000000000 +0000
+++ src/libvncclient/tls_openssl.c
@@ -167,6 +167,11 @@ static int sock_read_ready(SSL *ssl, uin
 
 	FD_ZERO(&fds);
 
+        if(SSL_get_fd(ssl) == RFB_INVALID_SOCKET) {
+            errno = EBADF;
+            return -1;
+        }
+
 	FD_SET(SSL_get_fd(ssl), &fds);
 
 	tv.tv_sec = ms / 1000;
