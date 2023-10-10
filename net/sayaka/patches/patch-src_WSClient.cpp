$NetBSD: patch-src_WSClient.cpp,v 1.1 2023/10/10 14:20:53 tsutsui Exp $

- workaround errors of gcc7 on netbsd-9:
> WSClient.cpp:71:2: sorry, unimplemented: non-trivial designated initializers not supported

--- src/WSClient.cpp.orig	2023-10-09 11:22:42.000000000 +0000
+++ src/WSClient.cpp
@@ -67,6 +67,9 @@ WSClient::Init()
 		.recv_callback			= wsclient_recv_callback,
 		.send_callback			= wsclient_send_callback,
 		.genmask_callback		= wsclient_genmask_callback,
+		.on_frame_recv_start_callback	= NULL,
+		.on_frame_recv_chunk_callback	= NULL,
+		.on_frame_recv_end_callback	= NULL,
 		.on_msg_recv_callback	= wsclient_on_msg_recv_callback,
 	};
 	if (wslay_event_context_client_init(&wsctx, &callbacks, this) != 0) {
