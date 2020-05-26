$NetBSD: patch-src_cmd_gdbserver.cpp,v 1.1 2020/05/26 11:28:50 joerg Exp $

--- src/cmd/gdbserver.cpp.orig	2020-05-26 01:36:49.070961229 +0000
+++ src/cmd/gdbserver.cpp
@@ -183,7 +183,7 @@ GdbServerSocketUnix::GdbServerSocketUnix
     address->sin_port = htons(port);
     memset(&address->sin_addr, 0, sizeof(address->sin_addr));
 
-    if(bind(sock, (struct sockaddr *)address, sizeof(address)))
+    if(::bind(sock, (struct sockaddr *)address, sizeof(address)))
         avr_error("Can not bind socket: %s", strerror(errno));
 
     if(listen(sock, 1) < 0)
