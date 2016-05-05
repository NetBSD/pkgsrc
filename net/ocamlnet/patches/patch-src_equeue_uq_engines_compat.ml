$NetBSD: patch-src_equeue_uq_engines_compat.ml,v 1.1 2016/05/05 16:04:21 jaapb Exp $

Temporary patch for ocaml 4.03 (from upstream git repository)
--- src/equeue/uq_engines_compat.ml.orig	2016-02-29 12:24:18.000000000 +0000
+++ src/equeue/uq_engines_compat.ml
@@ -7,7 +7,7 @@ class type server_socket_acceptor = serv
 class type client_socket_connector = client_endpoint_connector
           
 
-exception Mem_not_supported = Uq_multiplex.Mem_not_supported
+(* exception Mem_not_supported = Uq_multiplex.Mem_not_supported *)
 
 let create_multiplex_controller_for_connected_socket =
   Uq_multiplex.create_multiplex_controller_for_connected_socket
