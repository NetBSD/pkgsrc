$NetBSD: patch-stream_udp.c,v 1.1 2025/11/15 12:43:18 ryoon Exp $

--- stream/udp.c.orig	2025-10-08 03:41:09.150938225 +0000
+++ stream/udp.c
@@ -75,7 +75,7 @@ udp_open_socket (URL_t *url)
   }
 
   memset(&server_address, 0, sizeof(server_address));
-  if (isalpha (url->hostname[0]))
+  if (isalpha ((unsigned char)(url->hostname[0])))
   {
 #if !HAVE_WINSOCK2_H
     hp = gethostbyname (url->hostname);
@@ -124,7 +124,7 @@ udp_open_socket (URL_t *url)
   }
 
 #if HAVE_WINSOCK2_H
-  if (isalpha (url->hostname[0]))
+  if (isalpha ((unsigned char)(url->hostname[0])))
   {
     hp = gethostbyname (url->hostname);
     if (!hp)
