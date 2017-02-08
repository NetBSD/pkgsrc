$NetBSD: patch-game__server.cpp,v 1.1 2017/02/08 00:04:53 joerg Exp $

Pointers are not relative to 0.

--- game_server.cpp.orig	2017-01-08 19:35:01.809714788 +0000
+++ game_server.cpp
@@ -64,7 +64,7 @@ void game_server::init_net()
   
   // OK, init server thread to listen to clients
   con_th = SDL_CreateThread (&game_server::connection_accepter, (void *) this);
-  if (con_th < 0)
+  if (!con_th)
     {
       fprintf (stderr, "[SRV] Error starting thread: %s\n", SDL_GetError());
       exit(2);
