$NetBSD: patch-util_netevent.c,v 1.3 2025/04/09 13:17:48 he Exp $

Apply fix for memory leak reported in
https://github.com/NLnetLabs/unbound/issues/1264
from
https://github.com/NLnetLabs/unbound/commit/4f06e658d1a10a2782a475e76cb0c4d308e08f7c

--- util/netevent.c.orig	2024-10-17 07:23:14.000000000 +0000
+++ util/netevent.c
@@ -3084,7 +3084,7 @@ int comm_point_perform_accept(struct com
 			if(verbosity >= 3)
 				log_err_addr("accept rejected",
 				"connection limit exceeded", addr, *addrlen);
-			close(new_fd);
+			sock_close(new_fd);
 			return -1;
 		}
 	}
@@ -3185,6 +3185,40 @@ static int http2_submit_settings(struct 
 }
 #endif /* HAVE_NGHTTP2 */
 
+#ifdef HAVE_NGHTTP2
+/** Delete http2 stream. After session delete or stream close callback */
+static void http2_stream_delete(struct http2_session* h2_session,
+	struct http2_stream* h2_stream)
+{
+	if(h2_stream->mesh_state) {
+		mesh_state_remove_reply(h2_stream->mesh, h2_stream->mesh_state,
+			h2_session->c);
+		h2_stream->mesh_state = NULL;
+	}
+	http2_req_stream_clear(h2_stream);
+	free(h2_stream);
+}
+#endif /* HAVE_NGHTTP2 */
+
+/** delete http2 session server. After closing connection. */
+static void http2_session_server_delete(struct http2_session* h2_session)
+{
+#ifdef HAVE_NGHTTP2
+	struct http2_stream* h2_stream, *next;
+	nghttp2_session_del(h2_session->session); /* NULL input is fine */
+	h2_session->session = NULL;
+	for(h2_stream = h2_session->first_stream; h2_stream;) {
+		next = h2_stream->next;
+		http2_stream_delete(h2_session, h2_stream);
+		h2_stream = next;
+	}
+	h2_session->first_stream = NULL;
+	h2_session->is_drop = 0;
+	h2_session->postpone_drop = 0;
+	h2_session->c->h2_stream = NULL;
+#endif
+	(void)h2_session;
+}
 
 void
 comm_point_tcp_accept_callback(int fd, short event, void* arg)
@@ -3223,6 +3257,8 @@ comm_point_tcp_accept_callback(int fd, s
 		if(!c_hdl->h2_session ||
 			!http2_submit_settings(c_hdl->h2_session)) {
 			log_warn("failed to submit http2 settings");
+			if(c_hdl->h2_session)
+				http2_session_server_delete(c_hdl->h2_session);
 			return;
 		}
 		if(!c->ssl) {
@@ -3240,14 +3276,23 @@ comm_point_tcp_accept_callback(int fd, s
 	}
 	if(!c_hdl->ev->ev) {
 		log_warn("could not ub_event_new, dropped tcp");
+#ifdef HAVE_NGHTTP2
+		if(c_hdl->type == comm_http && c_hdl->h2_session)
+			http2_session_server_delete(c_hdl->h2_session);
+#endif
 		return;
 	}
 	log_assert(fd != -1);
 	(void)fd;
 	new_fd = comm_point_perform_accept(c, &c_hdl->repinfo.remote_addr,
 		&c_hdl->repinfo.remote_addrlen);
-	if(new_fd == -1)
+	if(new_fd == -1) {
+#ifdef HAVE_NGHTTP2
+		if(c_hdl->type == comm_http && c_hdl->h2_session)
+			http2_session_server_delete(c_hdl->h2_session);
+#endif
 		return;
+	}
 	/* Copy remote_address to client_address.
 	 * Simplest way/time for streams to do that. */
 	c_hdl->repinfo.client_addrlen = c_hdl->repinfo.remote_addrlen;
@@ -5062,19 +5107,6 @@ struct http2_stream* http2_stream_create
 	h2_stream->stream_id = stream_id;
 	return h2_stream;
 }
-
-/** Delete http2 stream. After session delete or stream close callback */
-static void http2_stream_delete(struct http2_session* h2_session,
-	struct http2_stream* h2_stream)
-{
-	if(h2_stream->mesh_state) {
-		mesh_state_remove_reply(h2_stream->mesh, h2_stream->mesh_state,
-			h2_session->c);
-		h2_stream->mesh_state = NULL;
-	}
-	http2_req_stream_clear(h2_stream);
-	free(h2_stream);
-}
 #endif
 
 void http2_stream_add_meshstate(struct http2_stream* h2_stream,
@@ -5091,26 +5123,6 @@ void http2_stream_remove_mesh_state(stru
 	h2_stream->mesh_state = NULL;
 }
 
-/** delete http2 session server. After closing connection. */
-static void http2_session_server_delete(struct http2_session* h2_session)
-{
-#ifdef HAVE_NGHTTP2
-	struct http2_stream* h2_stream, *next;
-	nghttp2_session_del(h2_session->session); /* NULL input is fine */
-	h2_session->session = NULL;
-	for(h2_stream = h2_session->first_stream; h2_stream;) {
-		next = h2_stream->next;
-		http2_stream_delete(h2_session, h2_stream);
-		h2_stream = next;
-	}
-	h2_session->first_stream = NULL;
-	h2_session->is_drop = 0;
-	h2_session->postpone_drop = 0;
-	h2_session->c->h2_stream = NULL;
-#endif
-	(void)h2_session;
-}
-
 #ifdef HAVE_NGHTTP2
 void http2_session_add_stream(struct http2_session* h2_session,
 	struct http2_stream* h2_stream)
