$NetBSD: patch-src_WSClient.cpp,v 1.2 2023/10/19 15:11:26 tsutsui Exp $

- workaround errors of gcc7 on netbsd-9:
> WSClient.cpp:73:2: sorry, unimplemented: non-trivial designated initializers not supported

--- src/WSClient.cpp.orig	2023-10-19 10:40:17.000000000 +0000
+++ src/WSClient.cpp
@@ -69,6 +69,9 @@ WSClient::Init(wsclient_onmsg_callback_t
 		.recv_callback			= wsclient_recv_callback,
 		.send_callback			= wsclient_send_callback,
 		.genmask_callback		= wsclient_genmask_callback,
+		.on_frame_recv_start_callback	= NULL,
+		.on_frame_recv_chunk_callback	= NULL,
+		.on_frame_recv_end_callback	= NULL,
 		.on_msg_recv_callback	= wsclient_on_msg_recv_callback,
 	};
 	int r = wslay_event_context_client_init(&wsctx, &callbacks, this);
