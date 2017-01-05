$NetBSD: patch-src_core_xmpp-servers.c,v 1.1 2017/01/05 17:15:46 maya Exp $

use_ssl renamed to use_tls in irssi 1.0.0

--- src/core/xmpp-servers.c.orig	2016-03-18 14:07:32.000000000 +0000
+++ src/core/xmpp-servers.c
@@ -151,7 +151,7 @@ xmpp_server_init_connect(SERVER_CONNECT_
 	server->connect_pid = -1;
 
 	if (server->connrec->port <= 0)
-		server->connrec->port = (server->connrec->use_ssl) ?
+		server->connrec->port = (server->connrec->use_tls) ?
 		    LM_CONNECTION_DEFAULT_PORT_SSL : LM_CONNECTION_DEFAULT_PORT;
 
 	if (conn->real_jid == NULL)
@@ -335,7 +335,7 @@ lm_open_cb(LmConnection *connection, gbo
 		g_free(host);
 	} else
 		signal_emit("server connecting", 1, server);
-	if (server->connrec->use_ssl)
+	if (server->connrec->use_tls)
 		signal_emit("xmpp server status", 2, server, 
 		    "Using SSL encryption.");
 	else if (lm_ssl_get_use_starttls(lm_connection_get_ssl(server->lmconn)))
@@ -470,7 +470,7 @@ xmpp_server_connect(XMPP_SERVER_REC *ser
 		return;
 	error = NULL;
 	err_msg = NULL;
-	if (server->connrec->use_ssl) {
+	if (server->connrec->use_tls) {
 		if (!set_ssl(server->lmconn, &error, server, FALSE)) {
 			err_msg = "Cannot init ssl";
 			goto err;
