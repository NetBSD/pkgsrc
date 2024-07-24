$NetBSD: patch-src_main_stats.c,v 1.1 2024/07/24 14:28:05 manu Exp $

From upstream
https://github.com/FreeRADIUS/freeradius-server/commit/3a9449539e4c5a74c85685cad6abe6edf412f701

From 3a9449539e4c5a74c85685cad6abe6edf412f701 Mon Sep 17 00:00:00 2001
From: "Alan T. DeKok" <aland@freeradius.org>
Date: Wed, 10 Jul 2024 09:29:39 -0400
Subject: [PATCH] ignore home server "ping" packets.  Fixes #5363

---
 src/main/stats.c | 8 ++++++++
 1 file changed, 8 insertions(+)

diff --git a/src/main/stats.c b/src/main/stats.c
index 29f2c48f4b9c..64cbafea931f 100644
--- ./src/main/stats.c.orig
+++ ./src/main/stats.c
@@ -95,6 +95,14 @@ void request_stats_final(REQUEST *request)
 
 	if ((request->options & RAD_REQUEST_OPTION_STATS) != 0) return;
 
+	/*
+	 *	This packet was originated by the server, and not
+	 *	received from a client.  It's a status-server or home
+	 *	server "ping" packet.  So we ignore it for statistics
+	 *	purposes.
+	 */
+	if (!request->packet) return;
+
 	/* don't count statistic requests */
 	if (request->packet->code == PW_CODE_STATUS_SERVER) {
 		return;
