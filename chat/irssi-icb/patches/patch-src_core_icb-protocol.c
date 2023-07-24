$NetBSD: patch-src_core_icb-protocol.c,v 1.1 2023/07/24 22:21:42 khorben Exp $

--- src/core/icb-protocol.c.orig	2023-07-21 23:08:13.814105120 +0000
+++ src/core/icb-protocol.c
@@ -340,8 +340,8 @@ static void sig_server_connected(ICB_SER
                 return;
 
 	server->readtag =
-		g_input_add(net_sendbuffer_handle(server->handle),
-			    G_INPUT_READ,
+		i_input_add(net_sendbuffer_handle(server->handle),
+			    I_INPUT_READ,
 			    (GInputFunction) icb_parse_incoming, server);
 }
 
