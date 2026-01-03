$NetBSD: patch-src_libnet__socket.c,v 1.1 2026/01/03 10:02:04 wiz Exp $

Fix function definition.

--- src/libnet_socket.c.orig	2026-01-03 10:00:29.684084235 +0000
+++ src/libnet_socket.c
@@ -36,7 +36,7 @@
 #include "../include/libnet.h"
 
 int
-libnet_open_raw_sock(prot)
+libnet_open_raw_sock(int prot)
 {
     int fd;
     int one = 1;
