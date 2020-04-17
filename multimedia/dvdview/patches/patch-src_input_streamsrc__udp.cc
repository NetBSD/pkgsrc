$NetBSD: patch-src_input_streamsrc__udp.cc,v 1.1 2020/04/17 13:34:47 joerg Exp $

--- src/input/streamsrc_udp.cc.orig	2020-04-17 11:18:20.162881242 +0000
+++ src/input/streamsrc_udp.cc
@@ -81,7 +81,7 @@ int StreamSource_udp::SetUDPEndpoint(con
       sa.sin_addr.s_addr = htonl(INADDR_ANY);
       sa.sin_port = htons(port);
 
-      if(bind(sock_, (struct sockaddr*) & sa,
+      if(::bind(sock_, (struct sockaddr*) & sa,
 	      sizeof(sa)) < 0)
 	{
 	  fprintf(stderr, "bind() failed, %s\n", strerror(errno)); 
@@ -103,7 +103,7 @@ int StreamSource_udp::SetUDPEndpoint(con
     {
       /* address it not multicast, do the regular bind */
       /* Bind the socket to port */
-      if(bind(sock_, (struct sockaddr *) & sa, sizeof(sa)) < 0)
+      if(::bind(sock_, (struct sockaddr *) & sa, sizeof(sa)) < 0)
 	{
 	  fprintf(stderr, "bind() failed, %s\n", strerror(errno));
 	}                                              
