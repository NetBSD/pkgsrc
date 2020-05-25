$NetBSD: patch-src_SyslogCollectorInterface.cpp,v 1.1 2020/05/25 20:26:51 adam Exp $

Do not confuse bind() with std::bind.

--- src/SyslogCollectorInterface.cpp.orig	2020-05-25 09:54:23.000000000 +0000
+++ src/SyslogCollectorInterface.cpp
@@ -95,7 +95,7 @@ SyslogCollectorInterface::SyslogCollecto
   listen_addr.sin_addr.s_addr = inet_addr(server_address);
   listen_addr.sin_port = htons(server_port);
  
-  if(bind(listen_sock, (struct sockaddr *) &listen_addr, sizeof(struct sockaddr)) != 0)
+  if(::bind(listen_sock, (struct sockaddr *) &listen_addr, sizeof(struct sockaddr)) != 0)
     throw("bind error");
  
   if(listen(listen_sock, MAX_SYSLOG_SUBSCRIBERS) != 0)
