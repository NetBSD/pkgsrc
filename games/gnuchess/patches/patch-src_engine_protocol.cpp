$NetBSD: patch-src_engine_protocol.cpp,v 1.1 2026/10/16 17:53:01 ktnb Exp $

Actually quit the loop if the engine has quit

--- src/engine/protocol.cpp.orig	2026-10-16 17:42:47.125065148 +0000
+++ src/engine/protocol.cpp
@@ -109,7 +109,14 @@ void loop() {
 
    // loop
 
-   while (true) loop_step();
+   while (true) {
+     bool quit;
+     pthread_mutex_lock( &engine_quit_mutex );
+     quit = engine_quit;
+     pthread_mutex_unlock( &engine_quit_mutex );
+     if (quit) break;
+     loop_step();
+   }
 }
 
 // init()
