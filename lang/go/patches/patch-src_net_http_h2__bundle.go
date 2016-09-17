$NetBSD: patch-src_net_http_h2__bundle.go,v 1.1 2016/09/17 15:56:58 bsiegert Exp $

From: Brad Fitzpatrick <bradfitz@golang.org>
Date: Mon, 12 Sep 2016 14:44:02 +0000
Subject: [PATCH] http2: don't sniff first Request.Body byte in Transport until we have a conn

bodyAndLength mutates Request.Body if Request.ContentLength == 0,
reading the first byte to determine whether it's actually empty or
just undeclared. But we did that before we checked whether our
connection was overloaded, which meant the caller could retry the
request on an new or lesser-loaded connection, but then lose the first
byte of the request.

Updates golang/go#17071 (needs bundle into std before fixed)

--- src/net/http/h2_bundle.go.orig	2016-09-07 19:34:35.000000000 +0000
+++ src/net/http/h2_bundle.go
@@ -5486,9 +5486,6 @@ func (cc *http2ClientConn) RoundTrip(req
 	}
 	hasTrailers := trailers != ""
 
-	body, contentLen := http2bodyAndLength(req)
-	hasBody := body != nil
-
 	cc.mu.Lock()
 	cc.lastActive = time.Now()
 	if cc.closed || !cc.canTakeNewRequestLocked() {
@@ -5496,6 +5493,9 @@ func (cc *http2ClientConn) RoundTrip(req
 		return nil, http2errClientConnUnusable
 	}
 
+	body, contentLen := http2bodyAndLength(req)
+	hasBody := body != nil
+
 	// TODO(bradfitz): this is a copy of the logic in net/http. Unify somewhere?
 	var requestedGzip bool
 	if !cc.t.disableCompression() &&
