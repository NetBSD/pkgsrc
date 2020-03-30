$NetBSD: patch-Src_DasherCore_SocketInputBase.cpp,v 1.1 2020/03/30 19:31:19 joerg Exp $

--- Src/DasherCore/SocketInputBase.cpp.orig	2020-03-30 12:56:59.535592416 +0000
+++ Src/DasherCore/SocketInputBase.cpp
@@ -112,7 +112,7 @@ bool Dasher::CSocketInputBase::StartList
   name.sin_family = AF_INET;
   name.sin_port = htons(port);
   name.sin_addr.s_addr = htonl(INADDR_ANY);
-  if(bind(sock, (struct sockaddr *)&name, sizeof(name)) < 0) {
+  if(::bind(sock, (struct sockaddr *)&name, sizeof(name)) < 0) {
     ReportErrnoError(_("Error binding to socket - already in use?"));
     DASHER_SOCKET_CLOSE_FUNCTION(sock);
     sock = -1;
