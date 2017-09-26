$NetBSD: patch-http.c,v 1.1 2017/09/26 17:57:36 gson Exp $

Do not crash when evhttp_send_reply_start() is called after
a timeout.  Fixes https://github.com/libevent/libevent/issues/509.

--- http.c.orig	2016-12-18 21:56:34.000000000 +0000
+++ http.c
@@ -2820,6 +2820,10 @@ evhttp_send_reply_start(struct evhttp_re
     const char *reason)
 {
 	evhttp_response_code_(req, code, reason);
+
+	if (req->evcon == NULL)
+		return;
+
 	if (evhttp_find_header(req->output_headers, "Content-Length") == NULL &&
 	    REQ_VERSION_ATLEAST(req, 1, 1) &&
 	    evhttp_response_needs_body(req)) {
