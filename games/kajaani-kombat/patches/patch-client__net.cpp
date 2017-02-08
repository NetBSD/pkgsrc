$NetBSD: patch-client__net.cpp,v 1.2 2017/02/08 00:04:53 joerg Exp $

Pointers are not relative to 0.
Don't shadow local variable.

--- client_net.cpp.orig	2005-01-22 16:51:34.000000000 +0000
+++ client_net.cpp
@@ -31,13 +31,13 @@ client_tcpnet::client_tcpnet(IPaddress *
   assert (ret != -1);
 
   cond = SDL_CreateCond();
-  if (cond <0)
+  if (!cond)
     {
       fprintf (stderr, "Error creating cond variable\n");
       exit(2);
     }
   mutex = SDL_CreateMutex();
-  if (mutex < 0)
+  if (!mutex)
     {
       fprintf (stderr, "Error creating mutex\n");
       exit(2);
@@ -45,13 +45,13 @@ client_tcpnet::client_tcpnet(IPaddress *
 
   active = true;
   trans_th = SDL_CreateThread (&client_tcpnet::transf_func, (void *) this);
-  if (trans_th < 0)
+  if (!trans_th)
     {
       fprintf(stderr, "Error starting thread: %s\n", SDL_GetError());
       exit(2);
     }
   input_th = SDL_CreateThread (&client_tcpnet::input_func, (void *) this);
-  if (input_th < 0)
+  if (!input_th)
     {
       fprintf(stderr, "Error starting thread: %s\n", SDL_GetError());
       exit(2);
@@ -192,7 +192,7 @@ int client_tcpnet::input_func(void *data
 	  if (SDLNet_SocketReady(cl->socket) == 0) continue;
 	  msg *m = 0;
 	  try {
-	    msg *m = msg::recv(cl->socket);
+	    m = msg::recv(cl->socket);
 	    cl->in.push(m);
 	  }
 	  catch (string &s)
