$NetBSD: patch-client__net.cpp,v 1.1 2012/11/16 00:50:13 joerg Exp $

--- client_net.cpp.orig	2012-11-15 15:37:19.000000000 +0000
+++ client_net.cpp
@@ -192,7 +192,7 @@ int client_tcpnet::input_func(void *data
 	  if (SDLNet_SocketReady(cl->socket) == 0) continue;
 	  msg *m = 0;
 	  try {
-	    msg *m = msg::recv(cl->socket);
+	    m = msg::recv(cl->socket);
 	    cl->in.push(m);
 	  }
 	  catch (string &s)
