$NetBSD: patch-src_connection.c,v 1.5 2025/05/06 15:49:16 schmonz Exp $

Allocate enough buffer for header sizes seen in common webservers.
https://github.com/renaudallard/sniproxy/commit/1a504817462209ecaa2f62ff925b58852e22f564

--- src/connection.c.orig	2024-07-02 15:36:27.000000000 +0000
+++ src/connection.c
@@ -812,13 +812,13 @@ new_connection(struct ev_loop *loop) {
     con->query_handle = NULL;
     con->use_proxy_header = 0;
 
-    con->client.buffer = new_buffer(4096, loop);
+    con->client.buffer = new_buffer(16384, loop);
     if (con->client.buffer == NULL) {
         free_connection(con);
         return NULL;
     }
 
-    con->server.buffer = new_buffer(4096, loop);
+    con->server.buffer = new_buffer(16384, loop);
     if (con->server.buffer == NULL) {
         free_connection(con);
         return NULL;
